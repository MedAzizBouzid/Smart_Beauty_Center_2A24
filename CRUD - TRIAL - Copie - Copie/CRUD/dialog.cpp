#include "dialog.h"
#include "ui_dialog.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_New_clicked()
{
    MainWindow s;
    s.Get_speak()->say("Nouveau fichier");
    file_path="";
    ui->textEdit->setText("");
}

void Dialog::on_Open_clicked()
{
    QString file_name= QFileDialog::getOpenFileName(this,"Open file");
    QFile f(file_name);
    file_path=file_name;
    if(!f.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"...","File not open");

    }else
    {
        QTextStream in(&f);
        QString text=in.readAll();
        ui->textEdit->setText(text);
        f.close();
    }
}

void Dialog::on_Save_clicked()
{
    QFile f(file_path);
    if(!f.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"...","File not open");

    }else
    {
        QTextStream out(&f);
        QString text=ui->textEdit->toPlainText();
        out<<text;
        f.flush();
        f.close();
    }
}

void Dialog::on_pushButton_4_clicked()
{
    QString file_name= QFileDialog::getSaveFileName(this,"Open file");
    QFile f(file_name);
    if(!f.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"...","File not open");

    }else
    {
        QTextStream out(&f);
        QString text=ui->textEdit->toPlainText();
        out<<text;
        f.flush();
        f.close();
    }
}

void Dialog::on_Copy_clicked()
{
    ui->textEdit->copy();
}

void Dialog::on_Paste_clicked()
{
    ui->textEdit->paste();
}

void Dialog::on_Cut_clicked()
{
    ui->textEdit->cut();

}

void Dialog::on_pushButton_10_clicked()
{
    ui->textEdit->undo();
}

void Dialog::on_Redo_clicked()
{
    ui->textEdit->redo();
}

void Dialog::on_pushButton_2_clicked()
{
    QString text;
    text+="Author: Oussema Ayari\n";
    text+="Date: 17/11/2021\n";
    text+="NotePad:(C) Notepad (R)\n";

    QMessageBox::about(this,"About Noptepad",text);
}
