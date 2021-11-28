#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include <QVideoWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString username=ui->lineEdit->text();
    QString pwd=ui->lineEdit_2->text();
    if(username=="admin" && pwd=="admin")
    {
        QMessageBox::information(nullptr, QObject::tr("login effecuté"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        this->hide();

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Login non effectué"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_2_clicked()
{
    QMediaPlayer* player = new QMediaPlayer ;
    QVideoWidget* vw = new QVideoWidget ;
    player->setVideoOutput(vw);
    vw->setGeometry(100,100,300,400);
    player->setMedia(QUrl::fromLocalFile("C:\\Users\\LENOVO\\Desktop\\Gestion Employee\\pubSB.mp4"));
    vw->show();
    player->play();
}
