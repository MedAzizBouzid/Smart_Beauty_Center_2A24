#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"service.h"
#include<QMessageBox>
#include<QIntValidator>
#include<QTextEdit>
#include<QtCharts>
#include<QChartView>
#include <QTime>
#include<QCompleter>
#include<QPixmap>
#include<QSqlQueryModel>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   ui->Acode_s->setValidator(new QIntValidator(100, 99999, this));
    ui->Aprix->setValidator(new QIntValidator(0, 99999, this));
     ui->line_time->setValidator(new QIntValidator(0,2323 , this));

    ui->lineEdit_nv_prix->setValidator(new QIntValidator(0,99999,this));
 ui->Scode_s->setValidator(new QIntValidator(0,99999,this));

    QPixmap pic("C:/Users/hp_omen/Desktop/main/AZIZ.png");
    ui->label_16->setPixmap(pic.scaled(300,500,Qt::KeepAspectRatio));

    QPixmap picc("C:/Users/hp_omen/Desktop/main/Zlogo.png");
    ui->label_17->setPixmap(picc.scaled(300,500,Qt::KeepAspectRatio));


 ui->tab_service->setModel(S.afficher());


 QSqlQuery qry;


 qry.prepare("select * from SERVICE");

 if (qry.exec())
 {while (qry.next()){

QBarSet *set0 = new QBarSet("service");



*set0 <<qry.value(3).toFloat();


   QBarSeries *series=new QBarSeries();
   series->append(set0);





   QChart *chart= new QChart();

   chart->legend()->hide();
   chart->addSeries(series);
   chart->setTitle("statistiques");

    chart->setAnimationOptions(QChart::AllAnimations);

QStringList categories;
categories<<qry.value(1).toString();



QBarCategoryAxis *axis = new QBarCategoryAxis();
        axis->append(categories);
        chart->createDefaultAxes();

        chart->setAxisX(axis, series);
        chart->setAxisY(axis, series);

   QChartView *chartView = new QChartView(chart);
   chartView->setRenderHint(QPainter::Antialiasing);
   chartView->setParent(ui->horizontalFrame);

}}
   ui->comboBox_type->setModel(S.wombo_comboType());
   ui->comboBox_code_search->setModel(S.wombo_combocode());
    ui->comboBox_code_s->setModel(S.wombo_combocode());
    ui->comboBox_code_m->setModel(S.wombo_combocode());



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

void MainWindow::on_pb_ajouter_clicked()
{
    int code_s=ui->Acode_s->text().toInt();
    QString descriptions=ui->Adescription_s->text();
    QString type_s=ui->Atype_s->text();
    float prix=ui->Aprix->text().toFloat();
  Service S(code_s,descriptions,type_s,prix);
  bool test=S.ajouter();
       if(test)
       {

           QMessageBox::information(nullptr,QObject::tr("OK"),
                   QObject::tr("ajout effectué\n"
                              "click cancel to exit."), QMessageBox::Cancel);

           ui->tab_service->setModel(S.afficher());
           ui->comboBox_type->setModel(S.wombo_comboType());
           ui->comboBox_code_search->setModel(S.wombo_combocode());
            ui->comboBox_code_s->setModel(S.wombo_combocode());
            ui->comboBox_code_m->setModel(S.wombo_combocode());
       }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                   QObject::tr("ajout non effectué\n"
                              "click cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
Service S1;
S1.setcode_s(ui->Scode_s->text().toInt());

bool test=S1.supprimer(S1.getcode_s());
if(test)
{

    QMessageBox::information(nullptr,QObject::tr("OK"),
            QObject::tr("suppression effectué\n"
                       "click cancel to exit."), QMessageBox::Cancel);
     ui->tab_service->setModel(S.afficher());
    ui->comboBox_type->setModel(S.wombo_comboType());
    ui->comboBox_code_search->setModel(S.wombo_combocode());
     ui->comboBox_code_s->setModel(S.wombo_combocode());
     ui->comboBox_code_m->setModel(S.wombo_combocode());
}
else
    QMessageBox::critical(nullptr,QObject::tr("Not OK"),
            QObject::tr("suppression non effectué\n"
                       "click cancel to exit."), QMessageBox::Cancel);

}



void MainWindow::on_Valide_Modif_clicked()
{


    int code_s=ui->comboBox_code_m->currentText().toInt();
    QString desc_nv=ui->ndescriptions->text();
    QString type_snv=ui->type_nv->text();
    float prix_nv=ui->lineEdit_nv_prix->text().toFloat();





 Service S(code_s,desc_nv,type_snv,prix_nv);






       bool test=S.modifier(code_s);
       if(test)
       {

           QMessageBox::information(nullptr,QObject::tr("OK"),
                   QObject::tr("modifier effectué\n"
                              "click cancel to exit."), QMessageBox::Cancel);
            ui->tab_service->setModel(S.afficher());
           ui->comboBox_type->setModel(S.wombo_comboType());
           ui->comboBox_code_search->setModel(S.wombo_combocode());
            ui->comboBox_code_s->setModel(S.wombo_combocode());
            ui->comboBox_code_m->setModel(S.wombo_combocode());
       }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                   QObject::tr("modifier non effectué\n"
                              "click cancel to exit."), QMessageBox::Cancel);









   }




void MainWindow::on_search_pb_clicked()
{ int code_s=ui->comboBox_code_search->currentText().toInt();

    QSqlQueryModel* model=S.rechercher(code_s);


    ui->table_search->setModel(model);

}

void MainWindow::on_groupBox_5_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec() == QDialog::Rejected)return;

    ui->label_16->render(&printer);


}



void MainWindow::on_pushButton_3_clicked()
{

  QString times=ui->line_time->text();
  Service S;


  S.time(times);
  bool test=S.ajoutertime();
  if(test)
        {

            QMessageBox::information(nullptr,QObject::tr("OK"),
                    QObject::tr(" effectué\n"
                               "click cancel to exit."), QMessageBox::Cancel);
            ui->tab_service->setModel(S.afficher());
            ui->comboBox_type->setModel(S.wombo_comboType());
            ui->comboBox_code_search->setModel(S.wombo_combocode());
             ui->comboBox_code_s->setModel(S.wombo_combocode());
             ui->comboBox_code_m->setModel(S.wombo_combocode());
        }
        else
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                    QObject::tr("le service est occupé \n"
                               "click cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_print2_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec() == QDialog::Rejected)return;

    ui->label_17->render(&printer);

}

void MainWindow::on_pushButton_2_clicked()
{
    //int code_s=ui->comboBox_code_m->currentText().toInt();

}

void MainWindow::on_table_search_activated(const QModelIndex &index)
{
   QString val=ui->table_search ->model()->data(index).toString();
   QSqlQuery qry;
   qry.prepare("select * from SERVICE where CODE_S='"+val+"'");
   if (qry.exec())
   {while (qry.next()){
           ui->txt_code->setText(qry.value(0).toString());
            ui->txt_type->setText(qry.value(1).toString());
             ui->txt_description->setText(qry.value(2).toString());
              ui->txt_prix->setText(qry.value(3).toString());
       }


}
}

void MainWindow::on_promo_pb_clicked()
{
    int code_s=ui->comboBox_code_search->currentText().toInt();
    QString desc_nv=ui->txt_description->text();
    QString type_snv=ui->txt_type->text();
    int R=ui->prom_box->currentText().toInt();
    float prix_nv=ui->txt_prix->text().toFloat();
    prix_nv=prix_nv*(100-R)/100;





 Service S(code_s,desc_nv,type_snv,prix_nv);






       bool test=S.modifier(code_s);
       if(test)
       {

           QMessageBox::information(nullptr,QObject::tr("OK"),
                   QObject::tr("modifier effectué\n"
                              "click cancel to exit."), QMessageBox::Cancel);

            ui->tab_service->setModel(S.afficher());
           ui->comboBox_type->setModel(S.wombo_comboType());
           ui->comboBox_code_search->setModel(S.wombo_combocode());
            ui->comboBox_code_s->setModel(S.wombo_combocode());
            ui->comboBox_code_m->setModel(S.wombo_combocode());
       }
       else
           QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                   QObject::tr("modifier non effectué\n"
                              "click cancel to exit."), QMessageBox::Cancel);






}
