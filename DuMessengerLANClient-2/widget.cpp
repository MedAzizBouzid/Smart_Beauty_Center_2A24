#include "widget.h"
#include "ui_widget.h"
#include"dumessengerconnectiondialog.h"
#include <QTcpSocket>

namespace Apexalliance {


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    mSocket=new QTcpSocket(this);
    connect(mSocket,&QTcpSocket::readyRead,[&]()
    { QTextStream T(mSocket);
       auto text=T.readAll();
       ui->textEdit->append(text);

    });
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pb_envoyer_clicked()
{
QTextStream T(mSocket);
T<<ui->le_nickname->text()<<": "<<ui->le_message->text();
mSocket->flush();
ui->le_message->clear();
}

void Widget::on_pb_connecter_clicked()
{
DuMessengerConnectionDialog D(this);
if(D.exec()==QDialog::Rejected)
{
    return;

}
mSocket->connectToHost(D.hostname(),D.port());

}
}//end
