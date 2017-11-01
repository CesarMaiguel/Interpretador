#include "finddialog.h"
#include "ui_finddialog.h"
#include <QMessageBox>

FindDialog::FindDialog(QWidget *parent, QPlainTextEdit *p) :
    QDialog(parent),
    ui(new Ui::FindDialog)
{
    ui->setupUi(this);
    text = p;
    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    ui->radioButton_2->setChecked(true);
    ui->pushButton->setDisabled(true);
    connect(ui->lineEdit,SIGNAL(textEdited(QString)),this,SLOT(switchSearchButton()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(search()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(close()));
}

FindDialog::~FindDialog()
{
    delete ui;
}

bool FindDialog::search(){

    bool toUp = ui->radioButton->isChecked();
    bool caseSensitive = ui->checkBox->isChecked();
    bool success = false;
    QTextCursor c;
    if(!toUp){
        if(caseSensitive){
            c = text->document()->find(ui->lineEdit->text(),text->textCursor(),QTextDocument::FindCaseSensitively);
        }else{
            c = text->document()->find(ui->lineEdit->text(),text->textCursor());
        }
    }else{
        if(caseSensitive){
            c = text->document()->find(ui->lineEdit->text(),text->textCursor(),QTextDocument::FindCaseSensitively|QTextDocument::FindBackward);
        }else{
            c = text->document()->find(ui->lineEdit->text(),text->textCursor(),QTextDocument::FindBackward);
        }
    }
    if(!c.isNull()){
        text->setTextCursor(c);
        parentWidget()->activateWindow();
        success = true;
    }else{
        QMessageBox *msg = new QMessageBox(this);
        msg->setWindowTitle("Notes");
        msg->setText("No se encontro \""+ui->lineEdit->text()+"\"");
        msg->show();
    }
    return success;
}

void FindDialog::switchSearchButton(){
    if(ui->lineEdit->text().isEmpty()||ui->lineEdit->text().isNull()){
        ui->pushButton->setDisabled(true);
    }else{
        ui->pushButton->setDisabled(false);
    }
}
