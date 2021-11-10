#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
class QTcpSocket;
namespace Apexalliance {


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pb_envoyer_clicked();

    void on_pb_connecter_clicked();

private:
    Ui::Widget *ui;
    QTcpSocket *mSocket;
};
}//end apexalliance
#endif // WIDGET_H
