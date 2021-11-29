#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "connection.h"
#define NOM_RX "^([a-z]+[A-Z]+[ ]?|[a-z][A-Z])+$"
      QRegExp rxNom(NOM_RX);
      QRegExpValidator* valiNom= new QRegExpValidator(rxNom);


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,99999999,this));
    ui->le_telephone->setValidator(new QIntValidator(0,99999999,this));
    ui->le_id->setValidator(new QIntValidator(0,99999999,this));
    ui->tableView->setModel(Etmp.afficher());
    Model_Completer=new QCompleter(this);
    Model_Completer->setModel(Etmp.wombo_combo());
    ui->Recherche->setCompleter(Model_Completer);
    ui->comboBox->setModel(Etmp.wombo_combo());
    ui->comboBox_2->setModel(Etmp.wombo_combo());
    ui->le_nom->setValidator(valiNom);
    ui->le_role->setValidator(valiNom);
    ui->le_prenom->setValidator(valiNom);
    ui->Mod_Nom->setValidator(valiNom);
    ui->Mod_Role->setValidator(valiNom);
    ui->Mod_Prenom->setValidator(valiNom);


    QPixmap pix("C:/Users/LENOVO/Desktop/Gestion Employee/background.png");
        ui->background_1->setPixmap(pix);
        ui->background_2->setPixmap(pix);
        ui->background_3->setPixmap(pix);
        ui->background_4->setPixmap(pix);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_B_AjoutEmploye_clicked()
{
   int id=ui->le_id->text().toInt();
   int telephone=ui->le_telephone->text().toInt();
   int H_travail=0;
   QString nom=ui->le_nom->text();
   QString prenom=ui->le_prenom->text();
   QString adresse=ui->le_adresse->text();
   QString role=ui->le_role->text();
Employe E(id,telephone,H_travail,nom,prenom,adresse,role);
     bool test=E.ajouter();
     if(test)
     {
         ui->tableView->setModel(Etmp.afficher());
         Model_Completer=new QCompleter(this);
         Model_Completer->setModel(Etmp.wombo_combo());
         ui->Recherche->setCompleter(Model_Completer);
         ui->comboBox->setModel(Etmp.wombo_combo());
         ui->comboBox_2->setModel(Etmp.wombo_combo());
         QMessageBox::information(nullptr,QObject::tr("OK"),
                 QObject::tr("ajout effectué\n"
                            "click cancel to exit."), QMessageBox::Cancel);
     }
     else
         QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                 QObject::tr("ajout non effectué\n"
                            "click cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_B_deleteEmploye_clicked()
{
   int id = ui->comboBox_2->currentText().toInt();
   bool test=Etmp.supprimer(id);
   if(test)
   {
       ui->tableView->setModel(Etmp.afficher());
       Model_Completer=new QCompleter(this);
       Model_Completer->setModel(Etmp.wombo_combo());
       ui->Recherche->setCompleter(Model_Completer);
       ui->comboBox->setModel(Etmp.wombo_combo());
       ui->comboBox_2->setModel(Etmp.wombo_combo());
       QMessageBox::information(nullptr,QObject::tr("OK"),
               QObject::tr("suppression effectué\n"
                          "click cancel to exit."), QMessageBox::Cancel);
   }
   else
       QMessageBox::critical(nullptr,QObject::tr("Not OK"),
               QObject::tr("suppression non effectué\n"
                          "click cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_B_ModifierEmploye_clicked()
{
    int id = ui->comboBox->currentText().toInt();
        QString nom= ui->Mod_Nom->text();
        QString prenom= ui->Mod_Prenom->text();
        QString role= ui->Mod_Role->text();
        QString adresse= ui->Mod_Adresse->text();
        int telephone= ui->Mod_Telephone->text().toInt();
Employe E(id,telephone,0,nom,prenom,adresse,role);
      bool test=E.modifier(id);
      if(test)
    {

           ui->tableView->setModel(Etmp.afficher());
           Model_Completer=new QCompleter(this);
           Model_Completer->setModel(Etmp.wombo_combo());
           ui->Recherche->setCompleter(Model_Completer);
           ui->comboBox->setModel(Etmp.wombo_combo());
           ui->comboBox_2->setModel(Etmp.wombo_combo());
    QMessageBox::information(nullptr, QObject::tr("modifier une agence"),
                      QObject::tr("Agence modifié.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("modifier une agence"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButtonEmploye_clicked()
{
    QSqlQueryModel* model;
    QString tri=ui->comboBox_tri->currentText();
    QString nnom=ui->Recherche->text();
if(tri=="Nom")
         model=Etmp.rechercher_nom(nnom);
if(tri=="Prenom")
         model=Etmp.rechercher_Prenom(nnom);
if(tri=="Role")
         model=Etmp.rechercher_Role(nnom);
          if (model != nullptr)
 {
          ui->tableView_2->setModel(model);
 }
}

void MainWindow::on_Tri_nomEmploye_clicked()
{
     QString tri=ui->comboBox_tri->currentText();
     if(tri=="Nom")
     {
     QSqlQueryModel* model=Etmp.Tri_nom();
     ui->tableView_2->setModel(model);
     }
     if(tri=="Prenom")
     {
     QSqlQueryModel* model=Etmp.Tri_prenom();
     ui->tableView_2->setModel(model);
     }
     if(tri=="Role")
     {
     QSqlQueryModel* model=Etmp.Tri_role();
     ui->tableView_2->setModel(model);
     }

}

void MainWindow::on_PDFEmploye_clicked()
{
    QSqlDatabase db;
                QTableView table_produit;
                QSqlQueryModel * Modal=new  QSqlQueryModel();

                QSqlQuery qry;
                 qry.prepare("SELECT * FROM EMPLOYE ");
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
                         "<img src='C:/Users/LENOVO/Documents/login/images/bg.png' height='120' width='120'/>"
                     "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     <<  QString("<title>%1</title>\n").arg(strTitle)
                     <<  "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                    << QString("<h3 style=\" font-size: 50px; font-family: Arial, Helvetica, sans-serif; color: #e80e32; font-weight: lighter; text-align: center;\">%1</h3>\n").arg("Liste des employe")
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
