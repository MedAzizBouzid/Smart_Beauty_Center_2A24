#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Refresh();
}
void MainWindow::Refresh(){
    ui->Affiche->setModel(fou.afficher());
    ui->comboBox_modif->setModel(fou.wombo_combo());
    ui->comboBox_supprim->setModel(fou.wombo_combo());
    Model_Completer=new QCompleter(this);
    Model_Completer->setModel(fou.wombo_combo());
    ui->lineEdit_chercher->setCompleter(Model_Completer);
    Model_Completer=new QCompleter(this);
    Model_Completer->setModel(fou.wombo_combo_type());
    ui->lineEdit_chercher_type->setCompleter(Model_Completer);
    ui->lineEdit_tri->setCompleter(Model_Completer);
    Model_Completer=new QCompleter(this);
    Model_Completer->setModel(fou.wombo_combo_local());
    ui->lineEdit_chercher_local->setCompleter(Model_Completer);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_tabWidget_tabCloseRequested(int index)
{
    ui->tabWidget->removeTab(index);
}

bool controle_alphabet_CODE(QString s){
    QString s1="&é~\"#'{([-|è`_ç^à@)]=}€¨$£¤ù%*µ<>,?;:/!§+AZERTYUIOPMLKJHGFDSQWXCVBN";
    QString s2=s.toUpper();
    int i=0;
    bool test=true;
    if(s.size()!=8)
        test=false;
    while(i<s2.size()&&test)
    {
        int j=0;
        while(j<s1.size()&&s2.at(i)!=s1.at(j))
            ++j;
        if(j<s1.size())
            test=false;
        else ++i;
    }
    return test;
}
bool controle_alphabet(QString s){
    QString s1="&é~\"#'{([-|è`_ç^à@)]=}€¨$£¤ù%*µ<>,?;:/!§+AZERTYUIOPMLKJHGFDSQWXCVBN";
    QString s2=s.toUpper();
    int i=0;
    bool test=true;
    while(i<s2.size()&&test)
    {
        int j=0;
        while(j<s1.size()&&s2.at(i)!=s1.at(j))
            ++j;
        if(j<s1.size())
            test=false;
        else ++i;
    }
    return test;
}
bool controle_numero(QString s){
    QString s1="&é~\"#'{([-|è`_ç^à@)]=}€¨$£¤ù%*µ<>,?;:/!§+";
    int i=0;
    bool test=true;
    while(i<s.size()&&test)
    {
        int j=0;
        while(j<s1.size()&&s.at(i)!=s1.at(j))
            ++j;
        if(j<s1.size())
            test=false;
        else ++i;
    }
    return test;
}

void MainWindow::on_Ajouter_clicked()
{
    QString code=ui->lineEdit_Code->text();
    QString num=ui->lineEdit_Num->text();
    QString local=ui->lineEdit_Localisation->text();
    QString type=ui->lineEdit_Type->text();
    QString prix=ui->lineEdit_Prix->text();

    bool verif_code=controle_alphabet_CODE(code);
    bool verif_num=controle_alphabet_CODE(num);
    bool verif_local=controle_numero(local);
    bool verif_type=controle_numero(type);
    bool verif_prix=controle_alphabet(prix);

    if(verif_code&&verif_num&&verif_prix&&verif_type&&verif_local)
    {
        fournisseur f(code,num,local,type,prix.toFloat());
        bool test=f.ajouter();
        Refresh();
        if(test)
        {

            ui->Affiche->setModel(fou.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Ajout avec succes.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }else
            QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                     QObject::tr("Ajout échoue.\n""Click Cancel to exit."),QMessageBox::Cancel);

    }else if(!verif_code)
        QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                 QObject::tr("Code Invalid.\n""Click Cancel to exit."),QMessageBox::Cancel);
    else if(!verif_num)
            QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                     QObject::tr("Numero Invalid.\n""Click Cancel to exit."),QMessageBox::Cancel);
    else if(!verif_prix)
            QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                     QObject::tr("Prix Invalid.\n""Click Cancel to exit."),QMessageBox::Cancel);
    else if(!verif_type)
            QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                     QObject::tr("Type Invalid.\n""Click Cancel to exit."),QMessageBox::Cancel);
    else if(!verif_local)
            QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                     QObject::tr("Localisation Invalid.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_Supprimer_clicked()
{
    QString code=ui->comboBox_supprim->currentText();

    bool verif_code=controle_alphabet(code);

    if(verif_code)
        {
        bool test=fou.supprimer(code);
        Refresh();
        if(test)
        {
            ui->Affiche->setModel(fou.afficher());
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Suppression avec succes.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
        else
                    QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                             QObject::tr("Suppression échoue.\n""Click Cancel to exit."),QMessageBox::Cancel);

        }else
            QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                     QObject::tr("Code Invalid.\n""Click Cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_Valide_Modif_clicked()
{
    QString id=ui->comboBox_modif->currentText();
    QString id_nv=ui->lineEdit_nv_code->text();
    QString type_nv=ui->lineEdit_nv_type->text();
    QString num_nv=ui->lineEdit_nv_num->text();
    QString localisation_nv=ui->lineEdit_nv_localisation->text();
    QString prix_nv=ui->lineEdit_nv_prix->text();
    bool verif_code=controle_alphabet_CODE(id_nv);
    bool verif_id=controle_alphabet_CODE(id);
    bool verif_num=controle_alphabet_CODE(num_nv);
    bool verif_prix=controle_alphabet(prix_nv);
    bool verif_type=controle_numero(type_nv);
    bool verif_localisation=controle_numero(localisation_nv);

    if(verif_code&&verif_num&&verif_prix&&verif_type&&verif_localisation&&verif_id)
    {
        fournisseur f(id_nv,num_nv,localisation_nv,type_nv,prix_nv.toFloat());
        bool test=f.modifier(id);
        if(test)
        {
            Refresh();
            QMessageBox::information(nullptr,QObject::tr("OK"),
                                     QObject::tr("Modification avec succes.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }else
            QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                     QObject::tr("Modification échoue.\n""Click Cancel to exit."),QMessageBox::Cancel);

    }else if(!verif_code || !verif_id)
        QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                 QObject::tr("Code Invalid.\n""Click Cancel to exit."),QMessageBox::Cancel);
    else if(!verif_num)
            QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                     QObject::tr("Numero Invalid.\n""Click Cancel to exit."),QMessageBox::Cancel);
    else if(!verif_prix)
            QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                     QObject::tr("Prix Invalid.\n""Click Cancel to exit."),QMessageBox::Cancel);
    else if(!verif_type)
            QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                     QObject::tr("Type Invalid.\n""Click Cancel to exit."),QMessageBox::Cancel);
    else if(!verif_localisation)
            QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                     QObject::tr("Localisation Invalid.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_Chercher_clicked()
{

    QString code=ui->lineEdit_chercher->text();
    QString type=ui->lineEdit_chercher_type->text();
    QString local=ui->lineEdit_chercher_local->text();
    bool verif_code=controle_alphabet(code);
    if(verif_code)
    {
     if(code!=""&&type==""&&local=="")
     ui->chercher->setModel(fou.cherhcer(code));
     else if(type!=""&&code==""&&local=="")
     ui->chercher->setModel(fou.cherhcer_type(type));
     else if(local!=""&&type==""&&code=="")
     ui->chercher->setModel(fou.cherhcer_local(local));
     else QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                QObject::tr("One attribute at a time!.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }

    else
        QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                 QObject::tr("Code Invalid.\n""Click Cancel to exit."),QMessageBox::Cancel);

}

void MainWindow::on_Tri_clicked()
{
    QString type=ui->lineEdit_tri->text();
    bool verif_type=controle_numero(type);
    if(verif_type)
        ui->Table_tri->setModel(fou.tri(ui->lineEdit_tri->text()));
    else
        QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                 QObject::tr("Type Invalid.\n""Click Cancel to exit."),QMessageBox::Cancel);
}



void MainWindow::on_pushButton_clicked()
{

}
