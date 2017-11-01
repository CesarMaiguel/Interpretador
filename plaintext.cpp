#include "plaintext.h"
#include <QMimeData>

PlainText::PlainText(QWidget *parent): QPlainTextEdit(parent)
{

}

void PlainText::dropEvent(QDropEvent *event){
    emit dropEventSignal(event->mimeData()->urls().at(0).toLocalFile());
    event->ignore();
}
