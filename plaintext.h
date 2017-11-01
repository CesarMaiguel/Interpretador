#ifndef PLAINTEXT_H
#define PLAINTEXT_H

#include <QPlainTextEdit>

class PlainText : public QPlainTextEdit
{
    Q_OBJECT
public:
    explicit PlainText(QWidget *parent = 0);
    void dropEvent(QDropEvent *event);

signals:
    void dropEventSignal(QString mimeText);
};

#endif // PLAINTEXT_H
