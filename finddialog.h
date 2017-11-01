#ifndef FINDDIALOG_H
#define FINDDIALOG_H

#include <QDialog>
#include <QPlainTextEdit>

namespace Ui {
class FindDialog;
}

class FindDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = 0, QPlainTextEdit *p = 0);
    ~FindDialog();

public slots:
    bool search();
    void switchSearchButton();

private:
    Ui::FindDialog *ui;
    QPlainTextEdit *text;
};

#endif // FINDDIALOG_H
