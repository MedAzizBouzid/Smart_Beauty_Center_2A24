#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/azizj/Desktop/menu.png");
     ui->menu3->setPixmap(pix);
    ui->menu2->setPixmap(pix);
    ui->menu->setPixmap(pix);


}

MainWindow::~MainWindow()
{
    delete ui;
}
