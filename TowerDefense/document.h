#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class document;
}

class document : public QWidget
{
    Q_OBJECT

public:
    explicit document(QWidget *parent = nullptr);
    ~document();

private:
    Ui::document *ui;
    void closeEvent(QCloseEvent *event) override {
        emit returnSignal();
        event->accept();
    }
signals:
    void returnSignal();
};

#endif // DOCUMENT_H
