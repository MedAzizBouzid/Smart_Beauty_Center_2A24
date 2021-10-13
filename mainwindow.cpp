#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/BERGILA/Desktop/2A24/projet/background.png");
    ui->background->setPixmap(pix);
    ui->background_2->setPixmap(pix);
    ui->background_3->setPixmap(pix);
    ui->background_4->setPixmap(pix);


}

MainWindow::~MainWindow()
{
    delete ui;
}
