#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"produit.h"
#include<QValidator>
#include<QMessageBox>
#include<QComboBox>
#include<QSqlQuery>
#include <QRegExpValidator>
#include<QSystemTrayIcon>
#include <QDirModel>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QTextStream>
#include <QPrintDialog>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QFileDialog>
//*********************************QRCODE******************
#include <string>
#include <vector>
#include<QDirModel>
#include <qrcode.h>
#include <string>
#include <iostream>
#include <fstream>
#include <QtSvg/QSvgRenderer>
using qrcodegen::QrCode;
//*********************************************************
#include"arduino.h"
//*****************************************************
#define NOM_RX "^([a-z]+[A-Z]+[ ]?|[a-z]+[A-Z])+$"
#define NUM_RX "^([0-9]+[,.]?)+$"
      QRegExp rxNom(NOM_RX);
      QRegExp rxNum(NUM_RX);
      QRegExpValidator* valiNom= new QRegExpValidator(rxNom);
       QRegExpValidator* valiNum= new QRegExpValidator(rxNum);
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
                        //background
                        ui->setupUi(this);
                        QPixmap pix("C:/Users/BERGILA/Desktop/2A24/projet/6.png");
                mSystemTrayIcon=new QSystemTrayIcon(this);
                mSystemTrayIcon->setIcon(QIcon(":/zesty.png"));
                mSystemTrayIcon ->setVisible(true);

                       // ui->background->setPixmap(pix);
                    //end background



                //controle de saisie
                    ui->le_nom->setValidator(valiNom);
                    ui->le_nommodifier->setValidator(valiNom);
                    ui->le_type->setValidator(valiNom);
                    ui->le_typemodifier->setValidator(valiNom);
                    ui->le_prix->setValidator(valiNum);
                    ui->le_prixmodifier->setValidator(valiNum);
                    ui->le_cab->setValidator(new QIntValidator(0, 99999999, this));
                    ui->le_quantite->setValidator(new QIntValidator(0, 999999, this));
                    ui->le_quantitemodifier->setValidator(new QIntValidator(0, 999999, this));
                //end controle de saisie




                        //AFFICHAGE
                        ui->tab_afficher->setModel(Pro.afficher());


                        //END AFFICHAGE



                        //RECHERCHE AVANCEE
                        Model_Completer=new QCompleter(this);
                        Model_Completer->setModel(Pro.wombo_comboNom());
                        ui->le_nomrechercher->setCompleter(Model_Completer);
                        Model_Completer2=new QCompleter(this);
                        Model_Completer2->setModel(Pro.wombo_combo());
                        ui->le_cabrechercher->setCompleter(Model_Completer2);
                        Model_Completer1=new QCompleter(this);
                        Model_Completer1->setModel(Pro.wombo_comboType());
                        ui->le_typerechercher->setCompleter(Model_Completer1);
                        //END RECHERCHE AVANCEE


                            //COMBOBOX CAB
                            ui->comboBox->setModel(Pro.wombo_combo());
                            ui->comobox_supprimer->setModel(Pro.wombo_combo());
                            //END COMBOBOX




}

MainWindow::~MainWindow()
{
    delete ui;
}











//CRUD

            void MainWindow::on_pb_ajouterbouzid_clicked()
            {
                QString NomProduit=ui->le_nom->text();
                float Prix=ui->le_prix->text().toFloat();
            int CodeABar=ui->le_cab->text().toInt();
            QString Type=ui->le_type->text();
                    int Quantite=ui->le_quantite->text().toInt();

                Produit P(  NomProduit,CodeABar,Type ,Prix, Quantite);


                        bool test;
                int pos=P.Notifier();

                if(NomProduit=="" || Prix==0 || CodeABar==0 || Type=="" || Quantite==0 )
                        test=false;
                else test=P.ajouter();
                if(test)
               {    mSystemTrayIcon->showMessage(tr("Message"),tr("Produit est ajouté avec succés"));



                    Model_Completer=new QCompleter(this);
                    Model_Completer->setModel(Pro.wombo_comboNom());
                    ui->le_nomrechercher->setCompleter(Model_Completer);


                    Model_Completer1=new QCompleter(this);
                    Model_Completer1->setModel(Pro.wombo_comboType());
                    ui->le_typerechercher->setCompleter(Model_Completer1);
                    ui->tab_afficher->setModel(P.afficher());


                    if(pos==0)
                        mSystemTrayIcon->showMessage(tr("Message"),tr(" Stock est epuisé"));

                else if(pos==1)
                        mSystemTrayIcon->showMessage(tr("Message"),tr("Attention stock va etre epuisé"));

              }  else {
                    mSystemTrayIcon->showMessage(tr("Message"),tr("Ajout non effectué"));

            ui->tab_afficher->setModel(P.afficher());}
            }

                            void MainWindow::on_pb_supprimerbouzid_clicked()
                            {
                                Produit P1;
                                P1.setCodeABar(ui->comobox_supprimer->currentText().toInt());
                                bool test=P1.supprimer(P1.GetCodeabar());

                                if(test)
                                {mSystemTrayIcon->showMessage(tr("Message"),tr("Produit est Supprimé avec succés"));

                                    Model_Completer=new QCompleter(this);
                                    Model_Completer->setModel(Pro.wombo_comboNom());
                                    ui->le_nomrechercher->setCompleter(Model_Completer);
                                    Model_Completer1=new QCompleter(this);
                                    Model_Completer1->setModel(Pro.wombo_comboType());
                                    ui->le_typerechercher->setCompleter(Model_Completer1);
                                    ui->tab_afficher->setModel(Pro.afficher());
                                    ui->comobox_supprimer->setModel(P1.wombo_combo());
                            }
                                else mSystemTrayIcon->showMessage(tr("Message"),tr("Suppression non effectué"));
                            }


void MainWindow::on_pb_modifierbouzid_clicked()
{
QString NomProduitn=ui->le_nommodifier->text();
float Prixn=ui->le_quantitemodifier->text().toInt();
int cab=ui->comboBox->currentText().toInt();
//int cab=ui->le_cabmodifier->text().toInt();
QString Typen=ui->le_typemodifier->text();
int Quantiten=ui->le_prixmodifier->text().toFloat();

Produit P(NomProduitn,cab,Typen,Quantiten,Prixn);

bool test=P.modifier(cab);




if(test)
{

    ui->tab_afficher->setModel(Pro.afficher());
    ui->comboBox->setModel(P.wombo_combo());
    ui->comobox_supprimer->setModel(P.wombo_combo());
    Model_Completer=new QCompleter(this);
    Model_Completer->setModel(Pro.wombo_comboNom());
    ui->le_nomrechercher->setCompleter(Model_Completer);
    Model_Completer1=new QCompleter(this);
    Model_Completer1->setModel(Pro.wombo_comboType());
    ui->le_typerechercher->setCompleter(Model_Completer1);
    mSystemTrayIcon->showMessage(tr("Message"),tr("Produit est modifié avec succés"));
int pos=P.Notifier();
    if(pos==0)
        mSystemTrayIcon->showMessage(tr("Message"),tr("Attention stock est epuisé"));

            else if(pos==1)
        mSystemTrayIcon->showMessage(tr("Message"),tr("Attention stock va etre epuisé"));
}
else {
    ui->tab_afficher->setModel(Pro.afficher());
    QMessageBox::critical(nullptr,QObject::tr("Modifier produit"),QObject::tr("Modification non effectué.\n Click cancel to exit."),QMessageBox::Cancel);
}

}




















// RECHERCHER

            void MainWindow::on_pb_rechercherbouzid_clicked()
            {

            int cab=ui->le_cabrechercher->text().toInt();

            Model_Completer=new QCompleter(this);
                Model_Completer->setModel(Pro.wombo_combo());
                ui->le_cabrechercher->setCompleter(Model_Completer);
                  QSqlQueryModel* Model_Complete=Pro.rechercher_cab( cab);
                  if (Model_Complete != nullptr)
                                         {
                                             ui->tab_rechercher->setModel(Model_Complete);
                                         }


            }

                        void MainWindow::on_pb_recherchernombouzid_clicked()
                        {
                            QString nom=ui->le_nomrechercher->text();

                            Model_Completer=new QCompleter(this);
                                Model_Completer->setModel(Pro.wombo_comboNom());
                                ui->le_nomrechercher->setCompleter(Model_Completer);
                                  QSqlQueryModel* Model_Complete=Pro.rechercher_nom( nom);
                                  if (Model_Complete != nullptr)
                                                         {
                                                             ui->tab_rechercher->setModel(Model_Complete);
                                                         }

                        }
                                            void MainWindow::on_pb_recherchertypebouzid_clicked()
                                            {
                                                QString type=ui->le_typerechercher->text();

                                                Model_Completer=new QCompleter(this);
                                                    Model_Completer->setModel(Pro.wombo_comboType());
                                                    ui->le_typerechercher->setCompleter(Model_Completer);
                                                      QSqlQueryModel* Model_Complete=Pro.rechercher_type( type);
                                                      if (Model_Complete != nullptr)
                                                                             {
                                                                                 ui->tab_rechercher->setModel(Model_Complete);
                                                                             }


                                            }









   //TRI
void MainWindow::on_pb_trinombouzid_clicked()
{
    QSqlQueryModel* model=Pro.trienom( );
    if(model !=nullptr)
         ui->tab_trie->setModel(model);
}



                void MainWindow::on_pb_typebouzid_clicked()
                {
                    QSqlQueryModel* model=Pro.trietype( );
                    if(model !=nullptr)
                         ui->tab_trie->setModel(model);
                }

                                    void MainWindow::on_pb_quantitebouzid_clicked()
                                    {
                                        QSqlQueryModel* model=Pro.triequantite( );
                                        if(model !=nullptr)
                                             ui->tab_trie->setModel(model);
                                    }

                                                            void MainWindow::on_pb_prixbouzid_clicked()
                                                            {
                                                                QSqlQueryModel* model=Pro.trieprix( );
                                                                if(model !=nullptr)
                                                                     ui->tab_trie->setModel(model);
                                                            }






void MainWindow::on_notifierpbbouzid_clicked()
{
    mSystemTrayIcon->showMessage(tr("Message"),tr("Attention stock va etre epuisé"));

}

void MainWindow::on_pb_imprimerbouzid_clicked()
{
    QSqlDatabase db;
                    QTableView table_produit;
                    QSqlQueryModel * Modal=new  QSqlQueryModel();

                    QSqlQuery qry;
                     qry.prepare("SELECT * FROM PRODUITS ");
                     qry.exec();
                     Modal->setQuery(qry);
                     table_produit.setModel(Modal);


                     db.close();

                     QString strStream;
                     QTextStream out(&strStream);


                     const int rowCount = table_produit.model()->rowCount();
                     const int columnCount =  table_produit.model()->columnCount();

                     const QString strTitle ="Document";


                     out <<  "<html>\n"
                             "<img src='' height='120' width='120'/>"
                         "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg(strTitle)
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                        << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des Produits")
                        <<"<br>"

                        <<"<table border=1 cellspacing=0 cellpadding=2 width=\"100%\">\n";
                     out << "<thead><tr bgcolor=#f0f0f0>";
                     for (int column = 0; column < columnCount; column++)
                         if (!table_produit.isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(table_produit.model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!table_produit.isColumnHidden(column)) {
                                 QString data = table_produit.model()->data(table_produit.model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table>\n"
                             "<br><br>"
                             <<"<br>"
                             <<"<table border=1 cellspacing=0 cellpadding=2>\n";

                         out << "<thead><tr bgcolor=#f0f0f0>";

                             out <<  "</table>\n"

                         "</body>\n"
                         "</html>\n";

                     QTextDocument *document = new QTextDocument();
                     document->setHtml(strStream);

                     QPrinter printer;
                     QPrintDialog *dialog = new QPrintDialog(&printer, NULL);
                     if (dialog->exec() == QDialog::Accepted) {

                         document->print(&printer);
                     }

                     printer.setOutputFormat(QPrinter::PdfFormat);
                     printer.setPaperSize(QPrinter::A4);
                     printer.setOutputFileName("/tmp/produit.pdf");
                     printer.setPageMargins(QMarginsF(15, 15, 15, 15));

                     delete document;
}

void MainWindow::on_PDFbouzid_clicked()
{
    QString strStream;
                                 QTextStream out(&strStream);

                                  const int rowCount = ui->tab_afficher->model()->rowCount();
                                  const int columnCount = ui->tab_afficher->model()->columnCount();
                                 out <<  "<html>\n"
                                 "<head>\n"
                                                  "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                                                  <<  QString("<title>%1</title>\n").arg("strTitle")
                                                  <<  "</head>\n"
                                                  "<body bgcolor=#ffffff link=#5000A0>\n"

                                                 //     "<align='right'> " << datefich << "</align>"
                                                  "<center> <H1>Liste des produits</H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                                              // headers
                                              out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                                              out<<"<cellspacing=10 cellpadding=3>";
                                              for (int column = 0; column < columnCount; column++)
                                                  if (!ui->tab_afficher->isColumnHidden(column))
                                                      out << QString("<th>%1</th>").arg(ui->tab_afficher->model()->headerData(column, Qt::Horizontal).toString());
                                              out << "</tr></thead>\n";

                                              // data table
                                              for (int row = 0; row < rowCount; row++) {
                                                  out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                                  for (int column = 0; column < columnCount; column++) {
                                                      if (!ui->tab_afficher->isColumnHidden(column)) {
                                                          QString data = ui->tab_afficher->model()->data(ui->tab_afficher->model()->index(row, column)).toString().simplified();
                                                          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                                      }
                                                  }
                                                  out << "</tr>\n";
                                              }
                                              out <<  "</table> </center>\n"
                                                  "</body>\n"
                                                  "</html>\n";

                                        QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                                          if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                                         QPrinter printer (QPrinter::PrinterResolution);
                                          printer.setOutputFormat(QPrinter::PdfFormat);
                                         printer.setPaperSize(QPrinter::A4);
                                        printer.setOutputFileName(fileName);

                                         QTextDocument doc;
                                          doc.setHtml(strStream);
                                          doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                                          doc.print(&printer);
}

void MainWindow::on_pb_Qrcodebouzid_clicked()
{
    if(ui->tab_afficher->currentIndex().row()==-1)
               QMessageBox::information(nullptr, QObject::tr("QrCode"),
                                        QObject::tr("Veuillez Choisir un employeur du Tableau.\n"
                                                    "Click Ok to exit."), QMessageBox::Ok);
           else
           {
                int ID_E=ui->tab_afficher->model()->data(ui->tab_afficher->model()->index(ui->tab_afficher->currentIndex().row(),0)).toInt();
                const QrCode qr = QrCode::encodeText(std::to_string(ID_E).c_str(), QrCode::Ecc::LOW);
                std::ofstream myfile;
                myfile.open ("qrcode.svg") ;
                myfile << qr.toSvgString(1);
                myfile.close();
                QSvgRenderer svgRenderer(QString("qrcode.svg"));
                QPixmap pix( QSize(90, 90) );
                QPainter pixPainter( &pix );
                svgRenderer.render( &pixPainter );
                ui->label_code->setPixmap(pix);
           }
}


//*****************************ARDUINO******************************//
/*
void MainWindow::on_RB_ON_clicked()
{      int ret=A.connect_arduino(); // lancer la connexion à arduino
       switch(ret){
       case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
           break;
       case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
          break;
       case(-1):qDebug() << "arduino is not available";
       }
        QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
    A.setdata(A.read_from_arduino()) ;
        if(A.getdata()=="1")

        mSystemTrayIcon->showMessage(tr("Message"),tr("Le stock de prouit GEL est epuisé veuillez contactez le fournisseur"));



}

void MainWindow::on_RB_OFF_clicked()
{
    int ret=A.close_arduino();
    if(ret==0)
        qDebug()<<"arduino is closed";
}
*/


