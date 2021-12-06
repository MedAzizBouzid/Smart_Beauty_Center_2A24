#include "mainwindow.h"
#include "ui_mainwindow.h"

//********OUSSAMA INCLUDES***********
#include "fournisseur.h"
#include "dialog.h"
#include <QLoggingCategory>
#include <QDesktopServices>
#include "notepad.h"

//***********BOUZID INCLUDES**************
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
//*******************QRCODE******************

#include <string>
#include <vector>
#include<QDirModel>
#include <qrcode.h>
#include <string>
#include <iostream>
#include <fstream>
#include <QtSvg/QSvgRenderer>
using qrcodegen::QrCode;
#define NOM_RX "^([a-z]+[A-Z]+[ ]?|[a-z][A-Z])+$"
#define NUM_RX "^([0-9]+[,.]?)+$"
      QRegExp rxNom(NOM_RX);
      QRegExp rxNum(NUM_RX);
      QRegExpValidator* valiNom= new QRegExpValidator(rxNom);
       QRegExpValidator* valiNum= new QRegExpValidator(rxNum);

//*************MARIEM INCLUDES***********************

#include <QIntValidator>
#include "client.h"
#include "smtp.h"
#include <QCalendarWidget>
#include <QDateEdit>
#include <QDate>
       //********************************jaballah
#include<depense.h>








#include "dumessengerconnectiondialog.h"
#include "ui_dumessengerconnectiondialog.h"
#include "chatsocket.h"
#include "chatserver.h"


#include "slidingstackedwidget.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->stackedWidget_2->setAnimation(QEasingCurve::Type::OutQuart);
    ui->stackedWidget_2->setSpeed(650);
    connect(ui->prev,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget_2->slideInPrev()){
            ui->prev->setEnabled(false);
            ui->next->setEnabled(false);
        }
    });
    connect(ui->next,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget_2->slideInNext()){
            ui->prev->setEnabled(false);
           ui->next->setEnabled(false);
        }
    });
    connect(ui->stackedWidget_2,&SlidingStackedWidget::animationFinished,[this]{
        ui->prev->setEnabled(true);
        ui->next->setEnabled(true);
    });
    //######################################################
    ui->stackedWidget_3->setAnimation(QEasingCurve::Type::OutQuart);
    ui->stackedWidget_3->setSpeed(650);
    connect(ui->prev_2,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget_3->slideInPrev()){
            ui->prev_2->setEnabled(false);
            ui->next_2->setEnabled(false);
        }
    });
    connect(ui->next_2,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget_3->slideInNext()){
            ui->prev_2->setEnabled(false);
           ui->next_2->setEnabled(false);
        }
    });
    connect(ui->stackedWidget_3,&SlidingStackedWidget::animationFinished,[this]{
        ui->prev_2->setEnabled(true);
        ui->next_2->setEnabled(true);
    });
    //######################################################
    ui->stackedWidget_4->setAnimation(QEasingCurve::Type::OutQuart);
    ui->stackedWidget_4->setSpeed(650);
    connect(ui->prev_3,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget_4->slideInPrev()){
            ui->prev_3->setEnabled(false);
            ui->next_3->setEnabled(false);
        }
    });
    connect(ui->next_3,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget_4->slideInNext()){
            ui->prev_3->setEnabled(false);
           ui->next_3->setEnabled(false);
        }
    });
    connect(ui->stackedWidget_4,&SlidingStackedWidget::animationFinished,[this]{
        ui->prev_3->setEnabled(true);
        ui->next_3->setEnabled(true);
    });
    //######################################################
    ui->stackedWidget_5->setAnimation(QEasingCurve::Type::OutQuart);
    ui->stackedWidget_5->setSpeed(650);
    connect(ui->prev_4,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget_5->slideInPrev()){
            ui->prev_4->setEnabled(false);
            ui->next_4->setEnabled(false);
        }
    });
    connect(ui->next_4,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget_5->slideInNext()){
            ui->prev_4->setEnabled(false);
           ui->next_4->setEnabled(false);
        }
    });
    connect(ui->stackedWidget_5,&SlidingStackedWidget::animationFinished,[this]{
        ui->prev_4->setEnabled(true);
        ui->next_4->setEnabled(true);
    });
    //######################################################
    ui->stackedWidget_6->setAnimation(QEasingCurve::Type::OutQuart);
    ui->stackedWidget_6->setSpeed(650);
    connect(ui->prev_5,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget_6->slideInPrev()){
            ui->prev_5->setEnabled(false);
            ui->next_5->setEnabled(false);
        }
    });
    connect(ui->next_5,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget_6->slideInNext()){
            ui->prev_5->setEnabled(false);
           ui->next_5->setEnabled(false);
        }
    });
    connect(ui->stackedWidget_6,&SlidingStackedWidget::animationFinished,[this]{
        ui->prev_5->setEnabled(true);
        ui->next_5->setEnabled(true);
    });
    //######################################################
    ui->stackedWidget_7->setAnimation(QEasingCurve::Type::OutQuart);
    ui->stackedWidget_7->setSpeed(650);
    connect(ui->prev_6,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget_7->slideInPrev()){
            ui->prev_6->setEnabled(false);
            ui->next_6->setEnabled(false);
        }
    });
    connect(ui->next_6,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget_7->slideInNext()){
            ui->prev_6->setEnabled(false);
           ui->next_6->setEnabled(false);
        }
    });
    connect(ui->stackedWidget_7,&SlidingStackedWidget::animationFinished,[this]{
        ui->prev_6->setEnabled(true);
        ui->next_6->setEnabled(true);
    });
    //######################################################
    ui->stackedWidget_8->setAnimation(QEasingCurve::Type::OutQuart);
    ui->stackedWidget_8->setSpeed(650);
    connect(ui->prev_7,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget_8->slideInPrev()){
            ui->prev_7->setEnabled(false);
            ui->next_7->setEnabled(false);
        }
    });
    connect(ui->next_7,&QAbstractButton::clicked,[this]{
        if(ui->stackedWidget_8->slideInNext()){
            ui->prev_7->setEnabled(false);
           ui->next_7->setEnabled(false);
        }
    });
    connect(ui->stackedWidget_8,&SlidingStackedWidget::animationFinished,[this]{
        ui->prev_7->setEnabled(true);
        ui->next_7->setEnabled(true);
    });
    //QMainWindow::showFullScreen();
    mSocket=new QTcpSocket(this);
    connect(mSocket,&QTcpSocket::readyRead,[&]()
    { QTextStream T(mSocket);
       auto text=T.readAll();
       ui->textEdit->append(text);
    });
    QBarSet *set0 = new QBarSet("depense");




                           *set0 <<  15 << 20 << 30 << 40 << 50 << 60;

                              QBarSeries *series=new QBarSeries();
                              series->append(set0);




                              QChart *chart= new QChart();
                              chart->legend()->hide();
                              chart->addSeries(series);
                              chart->setTitle("statistique");

                               chart->setAnimationOptions(QChart::AllAnimations);

                           QStringList categories;
                           categories<<"depense"<<"s"<<"g"<<"ff"<<"m"<<"f";
                           QBarCategoryAxis *axis = new QBarCategoryAxis();
                                   axis->append(categories);
                                   chart->createDefaultAxes();

                                   chart->setAxisX(axis, series);
                                   chart->setAxisY(axis, series);



                              QChartView *chartView = new QChartView(chart);
                              chartView->setRenderHint(QPainter::Antialiasing);

                              chartView->setParent(ui->horizontaltit);
    //*******OUSSAMA******************
    Refresh();
    ui->stackedWidget->setCurrentIndex(1);
    ui->engine_fournisseur->addItem("Default", QString("default"));
    foreach (QString engine, QTextToSpeech::availableEngines())
        ui->engine_fournisseur->addItem(engine, engine);
    ui->engine_fournisseur->setCurrentIndex(0);
    engineSelected(0);
    m_speech->say("Bienvenue utilisateur");
    connect(ui->speakButton_fournisseur, &QPushButton::clicked, this, &MainWindow::speak);
    connect(ui->pitch_fournisseur, &QSlider::valueChanged, this, &MainWindow::setPitch);
    connect(ui->rate_fournisseur, &QSlider::valueChanged, this, &MainWindow::setRate);
    connect(ui->volume_fournisseur, &QSlider::valueChanged, this, &MainWindow::setVolume);
    connect(ui->engine_fournisseur, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::engineSelected);

    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).

    //********************BOUZID****************

    QPixmap pix("C:/Users/BERGILA/Desktop/2A24/projet/6.png");
mSystemTrayIcon=new QSystemTrayIcon(this);
mSystemTrayIcon->setIcon(QIcon(":/zesty.png"));
mSystemTrayIcon ->setVisible(true);

   // ui->background->setPixmap(pix);
//end background



//controle de saisie
ui->le_nombouzid_4->setValidator(valiNom);
ui->le_nommodifierbouzid_4->setValidator(valiNom);
ui->le_typebouzid_4->setValidator(valiNom);
ui->le_typemodifierbouzid_4->setValidator(valiNom);
ui->le_prixbouzid_4->setValidator(valiNum);
ui->le_prixmodifierbouzid_4->setValidator(valiNum);
ui->le_cabbouzid_4->setValidator(new QIntValidator(0, 99999999, this));
ui->le_quantitebouzid_4->setValidator(new QIntValidator(0, 999999, this));
ui->le_quantitemodifierbouzid_4->setValidator(new QIntValidator(0, 999999, this));
//end controle de saisie




    //AFFICHAGE
    ui->tab_afficherbouzid_4->setModel(Pro.afficher());


    //END AFFICHAGE



    //RECHERCHE AVANCEE
    Model_Completer=new QCompleter(this);
    Model_Completer->setModel(Pro.wombo_comboNom());
    ui->le_nomrechercherbouzid_4->setCompleter(Model_Completer);
    Model_Completer2=new QCompleter(this);
    Model_Completer2->setModel(Pro.wombo_combo());
    ui->le_cabrechercherbouzid_4->setCompleter(Model_Completer2);
    Model_Completer1=new QCompleter(this);
    Model_Completer1->setModel(Pro.wombo_comboType());
    ui->le_typerechercherbouzid_4->setCompleter(Model_Completer1);
    //END RECHERCHE AVANCEE


        //COMBOBOX CAB
        ui->comboBoxbouzid_4->setModel(Pro.wombo_combo());
        ui->comobox_supprimerbouzid_4->setModel(Pro.wombo_combo());
        //END COMBOBOX



//**********************************MARIEM****************************

// Tri par date
        ui->TVTRI->setModel(Ctmp.tridate_rdv());

// affichage mail
        QString Adresse_Mail=ui->codemail->text();
        QSqlQueryModel* model=Ctmp.recherchermail(Adresse_Mail);
       ui->tvmail->setModel(model);

//comboboxes
        ui->comboBox->addItem("cheveux");
         ui->comboBox->addItem("soin");
          ui->comboBox->addItem("makeup");
           ui->comboBox->addItem("ongles");
           ui->comboBox_2->addItem("cheveux");
            ui->comboBox_2->addItem("soin");
            ui->comboBox_2->addItem("makeup");
            ui->comboBox_2->addItem("ongles");
             ui->comboBox_srech->addItem("-");
            ui->comboBox_srech->addItem("cheveux");
             ui->comboBox_srech->addItem("soin");
              ui->comboBox_srech->addItem("makeup");
               ui->comboBox_srech->addItem("ongles");
             ui->comboBox_modif->setModel(Ctmp.rechav());
             ui->comboBox_Supp->setModel(Ctmp.rechav());

            ui->TABCLI->setModel(Ctmp.afficher()); // liste des clients


//recherche avancé
            Model_CompleterM=new QCompleter(this);
                Model_CompleterM->setModel(Ctmp.rechav());
                ui->coderech->setCompleter(Model_CompleterM);
                 ui->codemail->setCompleter(Model_CompleterM);
                 Model_CompleterM=new QCompleter(this);
                     Model_CompleterM->setModel(Ctmp.rechavmail());
                     ui->codemail->setCompleter(Model_CompleterM);

//Controle de saisie
                     ui->lenom->setValidator(valiNom);
                     ui->leprenom->setValidator(valiNom);
                     ui->lecode->setValidator(new QIntValidator(0, 9999, this));
                     ui->lenum->setValidator(new QIntValidator(0, 99999999, this) );
                     ui->ladresse->setValidator( new QRegExpValidator( QRegExp( "[a-z0-9_]{1,99}\\S@[a-z]{1,99}\\S\\.[a-z]{1,99}\\S+" ), this ) );
                     ui->ladate->setValidator( new QRegExpValidator( QRegExp( "[0-31_]\\S/[0-12_]\\S\\/[0-2021_]\\S+" ), this ) );
                     ui->nommodif->setValidator(valiNom);
                     ui->prenommodif->setValidator(valiNom);
                     ui->numtelmodif->setValidator( new QIntValidator(0, 99999999, this)  );
                     ui->adressemodif->setValidator( new QRegExpValidator( QRegExp( "[a-z0-9_]{1,99}\\S@[a-z]{1,99}\\S\\.[a-z]{1,99}\\S+" ), this ) );
                     ui->datemodif->setValidator( new QRegExpValidator( QRegExp( "[0-31_]\\S/[0-12_]\\S\\/[0-2021_]\\S+" ), this ) );
                     ui->coderech->setValidator(new QIntValidator(0, 9999, this));
                     ui->daterech->setValidator( new QRegExpValidator( QRegExp( "[0-31_]\\S/[0-12_]\\S\\/[0-2021_]\\S+" ), this ) );
                     ui->codemail->setValidator( new QRegExpValidator( QRegExp( "[a-z0-9_]{1,99}\\S@[a-z]{1,99}\\S\\.[a-z]{1,99}\\S+" ), this ) );

            //********************SALIM****************
            ui->le_id_2->setValidator(new QIntValidator(0,99999999,this));
            ui->le_telephone_2->setValidator(new QIntValidator(0,99999999,this));
            ui->le_id_2->setValidator(new QIntValidator(0,99999999,this));
            ui->tableView_3->setModel(Etmp.afficher());
            Model_Completers=new QCompleter(this);
            Model_Completers->setModel(Etmp.wombo_combo2());
            ui->Recherche_2->setCompleter(Model_Completers);
            ui->comboBox_7->setModel(Etmp.wombo_combo2());
            ui->comboBox_6->setModel(Etmp.wombo_combo2());
            ui->le_nom_2->setValidator(valiNom);
            ui->le_role_2->setValidator(valiNom);
            ui->le_prenom_2->setValidator(valiNom);
            ui->Mod_Nom_3->setValidator(valiNom);
            ui->Mod_Role_3->setValidator(valiNom);
            ui->Mod_Prenom_3->setValidator(valiNom);




}

MainWindow::~MainWindow()
{
    delete ui;
}


//******************************OUSSAMA**************************
                        void MainWindow::speak()
                        {
                            m_speech->say(ui->plainTextEdit_fournisseur->toPlainText());
                        }
                        void MainWindow::stop()
                        {
                            m_speech->stop();
                        }

                        void MainWindow::setRate(int rate)
                        {
                            m_speech->setRate(rate / 10.0);
                        }

                        void MainWindow::setPitch(int pitch)
                        {
                            m_speech->setPitch(pitch / 10.0);
                        }

                        void MainWindow::setVolume(int volume)
                        {
                            m_speech->setVolume(volume / 100.0);
                        }

                        void MainWindow::stateChanged(QTextToSpeech::State state)
                        {


                            ui->pauseButton_fournisseur->setEnabled(state == QTextToSpeech::Speaking);
                            ui->resumeButton_fournisseur->setEnabled(state == QTextToSpeech::Paused);
                            ui->stopButton_fournisseur->setEnabled(state == QTextToSpeech::Speaking || state == QTextToSpeech::Paused);
                        }

                        void MainWindow::engineSelected(int index)
                        {
                            QString engineName = ui->engine_fournisseur->itemData(index).toString();
                            //delete m_speech;
                            if (engineName == "default")
                                m_speech = new QTextToSpeech(this);
                            else
                                m_speech = new QTextToSpeech(engineName, this);
                            disconnect(ui->language_fournisseur, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::languageSelected);
                            ui->language_fournisseur->clear();
                            // Populate the languages combobox before connecting its signal.
                            QVector<QLocale> locales = m_speech->availableLocales();
                            QLocale current = m_speech->locale();
                            foreach (const QLocale &locale, locales) {
                                QString name(QString("%1 (%2)")
                                             .arg(QLocale::languageToString(locale.language()))
                                             .arg(QLocale::countryToString(locale.country())));
                                QVariant localeVariant(locale);
                                ui->language_fournisseur->addItem(name, localeVariant);
                                if (locale.name() == current.name())
                                    current = locale;
                            }
                            setRate(ui->rate_fournisseur->value());
                            setPitch(ui->pitch_fournisseur->value());
                            setVolume(ui->volume_fournisseur->value());
                            connect(ui->stopButton_fournisseur, &QPushButton::clicked, m_speech, &QTextToSpeech::stop);
                            connect(ui->pauseButton_fournisseur, &QPushButton::clicked, m_speech, &QTextToSpeech::pause);
                            connect(ui->resumeButton_fournisseur, &QPushButton::clicked, m_speech, &QTextToSpeech::resume);

                            connect(m_speech, &QTextToSpeech::stateChanged, this, &MainWindow::stateChanged);
                            connect(m_speech, &QTextToSpeech::localeChanged, this, &MainWindow::localeChanged);

                            connect(ui->language_fournisseur, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::languageSelected);
                            localeChanged(current);
                        }

                        void MainWindow::languageSelected(int language)
                        {
                            QLocale locale = ui->language_fournisseur->itemData(language).toLocale();
                            m_speech->setLocale(locale);
                        }

                        void MainWindow::voiceSelected(int index)
                        {
                            m_speech->setVoice(m_voices.at(index));
                        }

                        void MainWindow::localeChanged(const QLocale &locale)
                        {
                            QVariant localeVariant(locale);
                            ui->language_fournisseur->setCurrentIndex(ui->language_fournisseur->findData(localeVariant));

                            disconnect(ui->voice_fournisseur, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::voiceSelected);
                            ui->voice_fournisseur->clear();

                            m_voices = m_speech->availableVoices();
                            QVoice currentVoice = m_speech->voice();
                            foreach (const QVoice &voice, m_voices) {
                                ui->voice_fournisseur->addItem(QString("%1 - %2 - %3").arg(voice.name())
                                                  .arg(QVoice::genderName(voice.gender()))
                                                  .arg(QVoice::ageName(voice.age())));
                                if (voice.name() == currentVoice.name())
                                    ui->voice_fournisseur->setCurrentIndex(ui->voice_fournisseur->count() - 1);
                            }
                            connect(ui->voice_fournisseur, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::voiceSelected);
                        }
                        void MainWindow::Refresh(){
                            ui->Affiche_fournisseur->setModel(fou.afficher());
                            ui->comboBox_modif_fournisseur->setModel(fou.wombo_combo());
                            ui->Localisation_combobox_fournisseur->setModel(fou.wombo_combo_local());
                            ui->comboBox_supprim_fournisseur->setModel(fou.wombo_combo());
                            Model_Completer=new QCompleter(this);
                            Model_Completer->setModel(fou.wombo_combo());
                            ui->lineEdit_chercher_fournisseur->setCompleter(Model_Completer);
                            Model_Completer=new QCompleter(this);
                            Model_Completer->setModel(fou.wombo_combo_type());
                            //ui->lineEdit_chercher_type->setCompleter(Model_Completer);
                            ui->lineEdit_tri_fournisseur->setCompleter(Model_Completer);
                            Model_Completer=new QCompleter(this);
                            Model_Completer->setModel(fou.wombo_combo_local());
                            //ui->lineEdit_chercher_local->setCompleter(Model_Completer);
                        }
                        void MainWindow::on_Acceuil_clicked()
                        {
                            ui->stackedWidget->setCurrentIndex(1);
                        }

                        void MainWindow::on_Fournisseurs_clicked()
                        {
                            ui->stackedWidget->setCurrentIndex(0);
                        }

                        void MainWindow::on_Produits_clicked()
                        {
                            ui->stackedWidget->setCurrentIndex(2);
                        }

                        void MainWindow::on_Services_clicked()
                        {
                            ui->stackedWidget->setCurrentIndex(3);
                        }

                        void MainWindow::on_Employes_clicked()
                        {
                            ui->stackedWidget->setCurrentIndex(4);
                        }

                        void MainWindow::on_Client_clicked()
                        {
                            ui->stackedWidget->setCurrentIndex(5);
                        }

                        void MainWindow::on_Comptabilite_clicked()
                        {
                            ui->stackedWidget->setCurrentIndex(6);
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
                            QString s1="&é~\"#'{([|-è`_ç^à@)]=}€¨$£¤ù%*µ<>,?;:/!§+AZERTYUIOPMLKJHGFDSQWXCVBN";
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
                            QString s1="&é~\"#'{([|è`_ç^à@)]=}€¨$£¤ù%*µ<>,?;:/!§+";
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
                        void MainWindow::on_Ajouter_fournisseur_clicked()
                        {
                            QString code=ui->lineEdit_Code_fournisseur->text();
                            QString num=ui->lineEdit_Num_fourniseur->text();
                            QString local=ui->lineEdit_Localisation_fournisseur->text();
                            QString type=ui->lineEdit_Type_fournisseur->text();
                            QString prix=ui->lineEdit_Prix_fournisseur->text();

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

                                    ui->Affiche_fournisseur->setModel(fou.afficher());
                                    m_speech->say("Ajout avec Succès.");
                                    m_speech->say("Cliquez sur Annuler pour quitter.");
                                    mSystemTrayIcon->showMessage(tr("Message"),tr("Ajout avec succés"));


                                }else
                                {
                                    m_speech->say("Ajout échoue.");
                                    m_speech->say("Cliquez sur Annuler pour quitter.");
                                    mSystemTrayIcon->showMessage(tr("Message"),tr("Ajout échoue"));

                                }


                            }else if(!verif_code)
                            {
                                m_speech->say("Code Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                mSystemTrayIcon->showMessage(tr("Message"),tr("Code Invalide."));
                            }

                            else if(!verif_num)
                            {
                                m_speech->say("Numero Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                mSystemTrayIcon->showMessage(tr("Message"),tr("Numero Invalide."));
                            }

                            else if(!verif_prix)
                            {
                                m_speech->say("Prix Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                mSystemTrayIcon->showMessage(tr("Message"),tr("Prix Invalide."));
                            }

                            else if(!verif_type)
                            {
                                m_speech->say("Type Invalid.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                mSystemTrayIcon->showMessage(tr("Message"),tr("Type Invalid."));
                            }

                            else if(!verif_local)
                            {
                                m_speech->say("Localisation Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                               mSystemTrayIcon->showMessage(tr("Message"),tr("Localisation Invalide."));
                            }

                        }

                        void MainWindow::on_Supprimer_fournisseur_clicked()
                        {
                            QString code=ui->comboBox_supprim_fournisseur->currentText();

                            bool verif_code=controle_alphabet(code);

                            if(verif_code)
                                {
                                bool test=fou.supprimer(code);
                                Refresh();
                                if(test)
                                {
                                    ui->Affiche_fournisseur->setModel(fou.afficher());
                                    m_speech->say("Suppression avec Succès.");
                                    m_speech->say("Cliquez sur Annuler pour quitter.");
                                    mSystemTrayIcon->showMessage(tr("Message"),tr("Suppression avec Succès."));
                                }
                                else
                                {
                                    m_speech->say("Suppression échoue.");
                                    m_speech->say("Cliquez sur Annuler pour quitter.");
                                    mSystemTrayIcon->showMessage(tr("Message"),tr("Suppression échoue."));
                                }


                                }else
                            {
                                m_speech->say("Code Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                mSystemTrayIcon->showMessage(tr("Message"),tr("Code Invalide."));
                            }

                        }

                        void MainWindow::on_Localisation_fournisseur_clicked()
                        {
                            QString p=ui->Localisation_combobox_fournisseur->currentText();
                            QDesktopServices::openUrl(QUrl("http://maps.google.com.sg/maps?q="+p+"&oe=utf-8&rls=org.mozilla:en-US:official&client=firefox-a&um=1&ie=UTF-8&hl=en&sa=N&tab=wl"));

                        }

                        void MainWindow::on_lineEdit_chercher_fournisseur_textChanged(const QString &code)
                        {
                            ui->chercher_fournisseur->setModel(fou.cherhcer(code));
                        }

                        void MainWindow::on_lineEdit_chercher_type_fournisseur_textChanged(const QString &type)
                        {
                            ui->chercher_fournisseur->setModel(fou.cherhcer_type(type));
                        }

                        void MainWindow::on_lineEdit_chercher_local_fournisseur_textChanged(const QString &local)
                        {
                            ui->chercher_fournisseur->setModel(fou.cherhcer_local(local));

                        }

                        void MainWindow::on_lineEdit_tri_fournisseur_textChanged(const QString &type)
                        {
                            ui->Table_tri_fournisseur->setModel(fou.tri(type));

                        }

                        void MainWindow::on_Chercher_fournisseur_clicked()
                        {
                            QString code=ui->lineEdit_chercher_fournisseur->text();
                            QString type=ui->lineEdit_chercher_type_fournisseur->text();
                            QString local=ui->lineEdit_chercher_local_fournisseur->text();
                            bool verif_code=controle_alphabet(code);
                            if(verif_code)
                            {
                             if(code!=""&&type==""&&local=="")
                             ui->chercher_fournisseur->setModel(fou.cherhcer(code));
                             else if(type!=""&&code==""&&local=="")
                             ui->chercher_fournisseur->setModel(fou.cherhcer_type(type));
                             else if(local!=""&&type==""&&code=="")
                             ui->chercher_fournisseur->setModel(fou.cherhcer_local(local));
                             else
                             {
                                 m_speech->say("Un attribut à la fois!");
                                 m_speech->say("Cliquez sur Annuler pour quitter.");
                                 mSystemTrayIcon->showMessage(tr("Message"),tr("Un attribut à la fois!"));
                             }
                            }

                            else
                            {
                                m_speech->say("Code Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                mSystemTrayIcon->showMessage(tr("Message"),tr("Code Invalide."));}
                        }

                        void MainWindow::on_Valide_Modif_fournisseur_clicked()
                        {
                            QString id=ui->comboBox_modif_fournisseur->currentText();
                            QString id_nv=ui->lineEdit_nv_code_fournisseur->text();
                            QString type_nv=ui->lineEdit_nv_type_fournisseur->text();
                            QString num_nv=ui->lineEdit_nv_num_fournisseur->text();
                            QString localisation_nv=ui->lineEdit_nv_localisation_fournisseur->text();
                            QString prix_nv=ui->lineEdit_nv_prix_fournisseur->text();
                            bool verif_code=controle_alphabet_CODE(id_nv);
                            bool verif_id=controle_alphabet_CODE(id);
                            bool verif_num=controle_alphabet_CODE(num_nv);
                            bool verif_prix=controle_alphabet(prix_nv);
                            bool verif_type=controle_numero(type_nv);
                            bool verif_localisation=controle_numero(localisation_nv);
                            if(num_nv=="")
                                verif_num=true;
                            if(id_nv=="")
                                verif_code=true;
                            if(localisation_nv=="")
                                verif_localisation=true;
                            if(prix_nv=="")
                                verif_prix=true;
                            if(type_nv=="")
                                verif_type=true;
                            if(verif_code&&verif_num&&verif_prix&&verif_type&&verif_localisation&&verif_id)
                            {
                                fournisseur f(id_nv,num_nv,localisation_nv,type_nv,prix_nv.toFloat());

                                bool test=true;
                                if(num_nv!="")
                                    test=f.modifier_num(id);
                                if(id_nv!="")
                                    test=f.modifier_code(id);
                                if(localisation_nv!="")
                                    test=f.modifier_local(id);
                                if(prix_nv!="")
                                    test=f.modifier_prix(id);
                                if(type_nv!="")
                                    test=f.modifier_type(id);
                                if(test)
                                {
                                    Refresh();
                                    m_speech->say("Modification avec Succès.");
                                    m_speech->say("Cliquez sur Annuler pour quitter.");
                                    mSystemTrayIcon->showMessage(tr("Message"),tr("Modification avec Succès."));
                                }else
                                {
                                    m_speech->say("Modification échoue.");
                                    m_speech->say("Cliquez sur Annuler pour quitter.");
                                    mSystemTrayIcon->showMessage(tr("Message"),tr("Modification échoue."));
                                }

                            }else if(!verif_code || !verif_id)
                            {
                                m_speech->say("Code Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                mSystemTrayIcon->showMessage(tr("Message"),tr("Code Invalide."));
                            }

                            else if(!verif_num)
                            {
                                m_speech->say("Numero Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                mSystemTrayIcon->showMessage(tr("Message"),tr("Numero Invalide."));
                            }

                            else if(!verif_prix)
                            {
                                m_speech->say("Prix Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                mSystemTrayIcon->showMessage(tr("Message"),tr("Prix Invalide."));
                            }

                            else if(!verif_type)
                            {
                                m_speech->say("Type Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                mSystemTrayIcon->showMessage(tr("Message"),tr("Type Invalide."));
                            }

                            else if(!verif_localisation)
                            {
                                m_speech->say("Localisation Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                mSystemTrayIcon->showMessage(tr("Message"),tr("Localisation Invalide."));
                            }
                        }

                        void MainWindow::on_Tri_clicked()
                        {
                            QString type=ui->lineEdit_tri_fournisseur->text();
                            bool verif_type=controle_numero(type);
                            if(verif_type)
                                ui->Table_tri_fournisseur->setModel(fou.tri(ui->lineEdit_tri_fournisseur->text()));
                            else
                                mSystemTrayIcon->showMessage(tr("Message"),tr("Type Invalide."));
                        }

                        void MainWindow::on_pushButton_2_fournisseur_clicked()
                        {
                            Notepad p;
                            p.setModal(true);
                            p.exec();
                        }

  //**********BOUZID***************************

                        void MainWindow::on_pb_ajouterbouzid_4_clicked()
                        {
                            QString NomProduit=ui->le_nombouzid_4->text();
                            float Prix=ui->le_prixbouzid_4->text().toFloat();
                        int CodeABar=ui->le_cabbouzid_4->text().toInt();
                        QString Type=ui->le_typebouzid_4->text();
                                int Quantite=ui->le_quantitebouzid_4->text().toInt();

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
                                ui->le_nomrechercherbouzid_4->setCompleter(Model_Completer);


                                Model_Completer1=new QCompleter(this);
                                Model_Completer1->setModel(Pro.wombo_comboType());
                                ui->le_typerechercherbouzid_4->setCompleter(Model_Completer1);
                                ui->tab_afficherbouzid_4->setModel(P.afficher());


                                if(pos==0)
                                    mSystemTrayIcon->showMessage(tr("Message"),tr(" Stock est epuisé"));

                            else if(pos==1)
                                    mSystemTrayIcon->showMessage(tr("Message"),tr("Attention stock va etre epuisé"));

                          }  else {
                                mSystemTrayIcon->showMessage(tr("Message"),tr("Ajout non effectué"));

                        ui->tab_afficherbouzid_4->setModel(P.afficher());}
                        }

                                        void MainWindow::on_pb_supprimerbouzid_4_clicked()
                                        {
                                            Produit P1;
                                            P1.setCodeABar(ui->comobox_supprimerbouzid_4->currentText().toInt());
                                            bool test=P1.supprimer(P1.GetCodeabar());

                                            if(test)
                                            {mSystemTrayIcon->showMessage(tr("Message"),tr("Produit est Supprimé avec succés"));

                                                Model_Completer=new QCompleter(this);
                                                Model_Completer->setModel(Pro.wombo_comboNom());
                                                ui->le_nomrechercherbouzid_4->setCompleter(Model_Completer);
                                                Model_Completer1=new QCompleter(this);
                                                Model_Completer1->setModel(Pro.wombo_comboType());
                                                ui->le_typerechercherbouzid_4->setCompleter(Model_Completer1);
                                                ui->tab_afficherbouzid_4->setModel(Pro.afficher());
                                                ui->comobox_supprimerbouzid_4->setModel(P1.wombo_combo());
                                        }
                                            else mSystemTrayIcon->showMessage(tr("Message"),tr("Suppression non effectué"));
                                        }


            void MainWindow::on_pb_modifierbouzid_4_clicked()
            {
            QString NomProduitn=ui->le_nommodifierbouzid_4->text();
            float Prixn=ui->le_quantitemodifierbouzid_4->text().toInt();
            int cab=ui->comboBoxbouzid_4->currentText().toInt();
            //int cab=ui->le_cabmodifier->text().toInt();
            QString Typen=ui->le_typemodifierbouzid_4->text();
            int Quantiten=ui->le_prixmodifierbouzid_4->text().toFloat();

            Produit P(NomProduitn,cab,Typen,Quantiten,Prixn);

            bool test=P.modifier(cab);




            if(test)
            {

                ui->tab_afficherbouzid_4->setModel(Pro.afficher());
                ui->comboBoxbouzid_4->setModel(P.wombo_combo());
                ui->comobox_supprimerbouzid_4->setModel(P.wombo_combo());
                Model_Completer=new QCompleter(this);
                Model_Completer->setModel(Pro.wombo_comboNom());
                ui->le_nomrechercherbouzid_4->setCompleter(Model_Completer);
                Model_Completer1=new QCompleter(this);
                Model_Completer1->setModel(Pro.wombo_comboType());
                ui->le_typerechercherbouzid_4->setCompleter(Model_Completer1);
                mSystemTrayIcon->showMessage(tr("Message"),tr("Produit est modifié avec succés"));
            int pos=P.Notifier();
                if(pos==0)
                    mSystemTrayIcon->showMessage(tr("Message"),tr("Attention stock est epuisé"));

                        else if(pos==1)
                    mSystemTrayIcon->showMessage(tr("Message"),tr("Attention stock va etre epuisé"));
            }
            else {
                ui->tab_afficherbouzid_4->setModel(Pro.afficher());
                mSystemTrayIcon->showMessage(tr("Message"),tr("Modification non effectué"));
            }

            }




















            // RECHERCHER

                        void MainWindow::on_pb_rechercherbouzid_4_clicked()
                        {

                        int cab=ui->le_cabrechercherbouzid_4->text().toInt();

                        Model_Completer=new QCompleter(this);
                            Model_Completer->setModel(Pro.wombo_combo());
                            ui->le_cabrechercherbouzid_4->setCompleter(Model_Completer);
                              QSqlQueryModel* Model_Complete=Pro.rechercher_cab( cab);
                              if (Model_Complete != nullptr)
                                                     {
                                                         ui->tab_rechercherbouzid_4->setModel(Model_Complete);
                                                     }


                        }

                                    void MainWindow::on_pb_recherchernombouzid_4_clicked()
                                    {
                                        QString nom=ui->le_nomrechercherbouzid_4->text();

                                        Model_Completer=new QCompleter(this);
                                            Model_Completer->setModel(Pro.wombo_comboNom());
                                            ui->le_nomrechercherbouzid_4->setCompleter(Model_Completer);
                                              QSqlQueryModel* Model_Complete=Pro.rechercher_nom( nom);
                                              if (Model_Complete != nullptr)
                                                                     {
                                                                         ui->tab_rechercherbouzid_4->setModel(Model_Complete);
                                                                     }

                                    }
                                                        void MainWindow::on_pb_recherchertypebouzid_4_clicked()
                                                        {
                                                            QString type=ui->le_typerechercherbouzid_4->text();

                                                            Model_Completer=new QCompleter(this);
                                                                Model_Completer->setModel(Pro.wombo_comboType());
                                                                ui->le_typerechercherbouzid_4->setCompleter(Model_Completer);
                                                                  QSqlQueryModel* Model_Complete=Pro.rechercher_type( type);
                                                                  if (Model_Complete != nullptr)
                                                                                         {
                                                                                             ui->tab_rechercherbouzid_4->setModel(Model_Complete);
                                                                                         }


                                                        }









               //TRI
            void MainWindow::on_pb_trinombouzid_4_clicked()
            {
                QSqlQueryModel* model=Pro.trienom( );
                if(model !=nullptr)
                     ui->tab_triebouzid_4->setModel(model);
            }



                            void MainWindow::on_pb_typebouzid_4_clicked()
                            {
                                QSqlQueryModel* model=Pro.trietype( );
                                if(model !=nullptr)
                                     ui->tab_triebouzid_4->setModel(model);
                            }

                                                void MainWindow::on_pb_quantitebouzid_4_clicked()
                                                {
                                                    QSqlQueryModel* model=Pro.triequantite( );
                                                    if(model !=nullptr)
                                                         ui->tab_triebouzid_4->setModel(model);
                                                }

                                                                        void MainWindow::on_pb_prixbouzid_4_clicked()
                                                                        {
                                                                            QSqlQueryModel* model=Pro.trieprix( );
                                                                            if(model !=nullptr)
                                                                                 ui->tab_triebouzid_4->setModel(model);
                                                                        }






            void MainWindow::on_notifierpbbouzid_4_clicked()
            {
                mSystemTrayIcon->showMessage(tr("Message"),tr("Attention stock va etre epuisé"));

            }

            void MainWindow::on_pb_imprimerbouzid_4_clicked()
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

            void MainWindow::on_PDFbouzid_4_clicked()
            {
                QString strStream;
                                             QTextStream out(&strStream);

                                              const int rowCount = ui->tab_afficherbouzid_4->model()->rowCount();
                                              const int columnCount = ui->tab_afficherbouzid_4->model()->columnCount();
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
                                                              if (!ui->tab_afficherbouzid_4->isColumnHidden(column))
                                                                  out << QString("<th>%1</th>").arg(ui->tab_afficherbouzid_4->model()->headerData(column, Qt::Horizontal).toString());
                                                          out << "</tr></thead>\n";

                                                          // data table
                                                          for (int row = 0; row < rowCount; row++) {
                                                              out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                                                              for (int column = 0; column < columnCount; column++) {
                                                                  if (!ui->tab_afficherbouzid_4->isColumnHidden(column)) {
                                                                      QString data = ui->tab_afficherbouzid_4->model()->data(ui->tab_afficherbouzid_4->model()->index(row, column)).toString().simplified();
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

            void MainWindow::on_pb_Qrcodebouzid_4_clicked()
            {
                if(ui->tab_afficherbouzid_4->currentIndex().row()==-1)
                mSystemTrayIcon->showMessage(tr("Message"),tr("Veuillez Choisir un produit du Tableau.\n"));
                       else
                       {
                            int ID_E=ui->tab_afficherbouzid_4->model()->data(ui->tab_afficherbouzid_4->model()->index(ui->tab_afficherbouzid_4->currentIndex().row(),0)).toInt();
                            const QrCode qr = QrCode::encodeText(std::to_string(ID_E).c_str(), QrCode::Ecc::LOW);
                            std::ofstream myfile;
                            myfile.open ("qrcode.svg") ;
                            myfile << qr.toSvgString(1);
                            myfile.close();
                            QSvgRenderer svgRenderer(QString("qrcode.svg"));
                            QPixmap pix( QSize(90, 90) );
                            QPainter pixPainter( &pix );
                            svgRenderer.render( &pixPainter );
                            ui->label_code_4->setPixmap(pix);
                       }
            }
            void MainWindow::on_pb_connecter_clicked()
            {
                DuMessengerConnectionDialog D(this);
                if(D.exec()==QDialog::Rejected)
                {
                    return;

                }
                mSocket->connectToHost(D.hostname(),D.port());

            }


//*******************************************************MARIEM**********************************************************************************************

            void MainWindow::on_pbajoutermariem_clicked()
            {

                int code_C=ui->lecode->text().toInt();
                QString Num_tel=ui->lenum->text();
                QString Nom=ui->lenom->text();
                QString Prenom=ui->leprenom->text();
                QString Adresse_Mail=ui->ladresse->text();
                QString Date_RDV=ui->ladate->text();
                QString S_Attribue=ui->comboBox->currentText();
                Client C(code_C,Num_tel,Nom,Prenom,Adresse_Mail,Date_RDV,S_Attribue);
              bool test=C.ajouter();

              if(test)
            {
                  ui->TVTRI->setModel(Ctmp.tridate_rdv());//Tri

                  ui->TABCLI->setModel(Ctmp.afficher());
                  Model_CompleterM=new QCompleter(this);
                      Model_CompleterM->setModel(Ctmp.rechav());
                      ui->coderech->setCompleter(Model_CompleterM);
                      mSystemTrayIcon->showMessage(tr("Message"),tr("Ajout effectué"));

            }
            else
                  mSystemTrayIcon->showMessage(tr("Message"),tr("Ajout non effectué"));


            }

            void MainWindow::on_pb_suppmariem_clicked()
            {

                int ccd=ui->comboBox_modif->currentText().toInt();
             bool test=Ctmp.supprimer(ccd);
             if(test)
             {
                 ui->TVTRI->setModel(Ctmp.tridate_rdv());//Tri

                       ui->TABCLI->setModel(Ctmp.afficher());
                       ui->comboBox_Supp->setModel(Ctmp.rechav());
                      Model_CompleterM=new QCompleter(this);
                          Model_CompleterM->setModel(Ctmp.rechav());
                          ui->coderech->setCompleter(Model_CompleterM);
                          mSystemTrayIcon->showMessage(tr("Message"),tr("Suppression effectué"));

               }
               else // si cvpas QMessageBox::critical
                 mSystemTrayIcon->showMessage(tr("Message"),tr("Suppression non effectué"));



            }


            void MainWindow::on_pbmodifiermariem_clicked()
            {
                int ccd=ui->comboBox_modif->currentText().toInt();
                QString Num_tel=ui->numtelmodif->text();
                QString Nom=ui->nommodif->text();
                QString Prenom=ui->prenommodif->text();
                QString Adresse_Mail=ui->adressemodif->text();
                QString Date_RDV=ui->datemodif->text();
               QString S_Attribue=ui->comboBox_2->currentText();
                Client C(ccd,Num_tel,Nom,Prenom,Adresse_Mail,Date_RDV,S_Attribue);
              bool test=C.modifier(ccd);
              if(test) // si cv QMessageBox::information
            {
                  ui->TVTRI->setModel(Ctmp.tridate_rdv());//Tri
                  ui->TABCLI->setModel(Ctmp.afficher());
                   ui->comboBox_modif->setModel(Ctmp.rechav());
                  Model_CompleterM=new QCompleter(this);
                      Model_CompleterM->setModel(Ctmp.rechav());
                      ui->coderech->setCompleter(Model_CompleterM);





                      mSystemTrayIcon->showMessage(tr("Message"),tr("Modification effectué"));

            }
            else // si cvpas QMessageBox::critical
                  mSystemTrayIcon->showMessage(tr("Message"),tr("Modification non effectué"));


            }



            void MainWindow::on_pbrecherchermariem_clicked()
            {
                int code_C=ui->coderech->text().toInt();
                QString Date_RDV=ui->daterech->text();
                QString S_Attribue=ui->comboBox_srech->currentText();
                      QSqlQueryModel* model=Ctmp.rechercher(code_C);
                      QSqlQueryModel* model1=Ctmp.rechercherDate(Date_RDV);
                      QSqlQueryModel* model2=Ctmp.rechercherService(S_Attribue);
                      if (model != nullptr && code_C!=0 && Date_RDV=="" && S_Attribue=="-")
                                             {

                                                 ui->tabrech->setModel(model);
                                             }
                      else if (model1 != nullptr && code_C==0 && Date_RDV!="" && S_Attribue=="-")
                                               ui->tabrech->setModel(model1);
                      else if (model1 != nullptr && code_C==0 && Date_RDV=="" && S_Attribue!="-")
                              ui->tabrech->setModel(model2);
            }



            void MainWindow::on_codemailmariem_returnPressed()
            {
                QString Adresse_Mail=ui->codemail->text();

                      QSqlQueryModel* model=Ctmp.recherchermail(Adresse_Mail);
                      if (model != nullptr)
                                             {

                                                 ui->tvmail->setModel(model);
                                             }
            }


            void MainWindow::sendMail()
            {
                Smtp *smtp= new Smtp("mariem52bel@gmail.com","yaaaaarab","smtp.gmail.com");
                connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
                 if(ui->radioButton->isChecked())
                 {
                     smtp->sendMail("",ui->codemail->text(),"Mail fidélité","Félicitation cher client!\nGrace à votre fidélité vous bénificiez d'un service gratuit.\n Contactez nous pour en savoir plus.\n");
                  }
                 else if(ui->radioButton_2->isChecked())
                 {
                     smtp->sendMail("",ui->codemail->text(),"Offres","Annonce Offres !\nProfitez de nos offres jusqu'à -50% solde!\n Contactez nous pour en savoir plus.\n");
                    }
            }

            void MainWindow::mailSent(QString status)
            {
                if(status == "Message sent")
                    QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
            }

            void MainWindow::on_pb_mailmariem_clicked()
            {

                  Smtp *smtp= new Smtp("mariem52bel@gmail.com","yaaaaarab","smtp.gmail.com");
                  connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
                   if(ui->radioButton->isChecked())
                   {
                       smtp->sendMail("",ui->codemail->text(),"Mail fidélité","Félicitation cher client!\nGrace à votre fidélité vous bénificiez d'un service gratuit.\n Contactez nous pour en savoir plus.\n");
                    }
                   else if(ui->radioButton_2->isChecked())
                   {
                       smtp->sendMail("",ui->codemail->text(),"Offres","Annonce Offres !\nProfitez de nos offres jusqu'à -50% solde!\n Contactez nous pour en savoir plus.\n");
                      }
                 void mailSent(QString)  ;

            }

            void MainWindow::on_calendarWidgetmariem_clicked(const QDate &Date_RDV)
            {

                ui->currentdate = new QDateEdit;
                    ui->currentdate->setDisplayFormat("dd/MM/yyyy");
                    ui->currentdate->setDate(Date_RDV);
                    QString Date(ui->currentdate->text());
               //QString Date=ui->currentdate->toString();
                QSqlQueryModel* model=Ctmp.rechercherDate(Date);
                if (model != nullptr)
                {
                   ui->tvrdv->setModel(model);
                }
            }
//*******************************************************SALIM**********************************************************************************************



void MainWindow::on_B_AjoutEmploye_2_clicked()
{
    int id=ui->le_id_2->text().toInt();
    int telephone=ui->le_telephone_2->text().toInt();
    int H_travail=0;
    QString nom=ui->le_nom_2->text();
    QString prenom=ui->le_prenom_2->text();
    QString adresse=ui->le_adresse_2->text();
    QString role=ui->le_role_2->text();
 Employe E(id,telephone,H_travail,nom,prenom,adresse,role);
      bool test=E.ajouter();
      if(test)
      {
          ui->tableView_3->setModel(Etmp.afficher());
          Model_Completers=new QCompleter(this);
          Model_Completers->setModel(Etmp.wombo_combo2());
          ui->Recherche_2->setCompleter(Model_Completers);
          ui->comboBox_7->setModel(Etmp.wombo_combo2());
          ui->comboBox_6->setModel(Etmp.wombo_combo2());
          mSystemTrayIcon->showMessage(tr("Message"),tr("Ajout effectué"));

      }
      else
          mSystemTrayIcon->showMessage(tr("Message"),tr("Ajout non effectué"));


}

void MainWindow::on_B_deleteEmploye_2_clicked()
{
    int id = ui->comboBox_2->currentText().toInt();
    bool test=Etmp.supprimer(id);
    if(test)
    {
        ui->tableView_3->setModel(Etmp.afficher());
        Model_Completers=new QCompleter(this);
        Model_Completers->setModel(Etmp.wombo_combo2());
        ui->Recherche_2->setCompleter(Model_Completers);
        ui->comboBox_7->setModel(Etmp.wombo_combo2());
        ui->comboBox_6->setModel(Etmp.wombo_combo2());
        mSystemTrayIcon->showMessage(tr("Message"),tr("Suppression effectué"));

    }
    else
        mSystemTrayIcon->showMessage(tr("Message"),tr("Suppression non effectué"));


}

void MainWindow::on_B_ModifierEmploye_2_clicked()
{
    int id = ui->comboBox->currentText().toInt();
        QString nom= ui->Mod_Nom_3->text();
        QString prenom= ui->Mod_Prenom_3->text();
        QString role= ui->Mod_Role_3->text();
        QString adresse= ui->Mod_Adresse_3->text();
        int telephone= ui->Mod_Telephone_3->text().toInt();
Employe E(id,telephone,0,nom,prenom,adresse,role);
      bool test=E.modifier(id);
      if(test)
    {

           ui->tableView_3->setModel(Etmp.afficher());
           Model_Completers=new QCompleter(this);
           Model_Completers->setModel(Etmp.wombo_combo2());
           ui->Recherche_2->setCompleter(Model_Completers);
           ui->comboBox_7->setModel(Etmp.wombo_combo2());
           ui->comboBox_6->setModel(Etmp.wombo_combo2());
           mSystemTrayIcon->showMessage(tr("Message"),tr("Modification effectué"));


    }
      else
          mSystemTrayIcon->showMessage(tr("Message"),tr("Modification non effectué"));

}

void MainWindow::on_pushButtonEmploye_2_clicked()
{
    QSqlQueryModel* model;
    QString tri=ui->comboBox_tri_2->currentText();
    QString nnom=ui->Recherche_2->text();
if(tri=="Nom")
         model=Etmp.rechercher_nom(nnom);
if(tri=="Prenom")
         model=Etmp.rechercher_Prenom(nnom);
if(tri=="Role")
         model=Etmp.rechercher_Role(nnom);
          if (model != nullptr)
          {
                   ui->tableView_5->setModel(model);
          }
}

void MainWindow::on_Tri_nomEmploye_2_clicked()
{
    QString tri=ui->comboBox_tri_2->currentText();
    if(tri=="Nom")
    {
    QSqlQueryModel* model=Etmp.Tri_nom();
    ui->tableView_5->setModel(model);
    }
    if(tri=="Prenom")
    {
    QSqlQueryModel* model=Etmp.Tri_prenom();
    ui->tableView_5->setModel(model);
    }
    if(tri=="Role")
    {
    QSqlQueryModel* model=Etmp.Tri_role();
    ui->tableView_5->setModel(model);
    }

}

void MainWindow::on_PDFEmploye_2_clicked()
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



void MainWindow::on_pb_envoyer_clicked()
{
    QTextStream T(mSocket);
    T<<ui->le_nickname->text()<<": "<<ui->le_message->text();
    mSocket->flush();
    ui->le_message->clear();
}

//********************************************AZIZ chehata********************************************
void MainWindow::on_chehata_pb_ajouter_3_clicked()
{
    int code_s=ui->Acode_s_3->text().toInt();
    QString descriptions=ui->Adescription_s_3->text();
    QString type_s=ui->Atype_s_3->text();
    float prix=ui->Aprix_3->text().toFloat();
  Service S(code_s,descriptions,type_s,prix);
  bool test=S.ajouter();
       if(test)
       {

           mSystemTrayIcon->showMessage(tr("Message"),tr("Ajout effectué"));


           ui->tab_service_3->setModel(S.afficher());

           ui->comboBox_code_search_3->setModel(S.wombo_combocode());
            ui->comboBox_code_s_3->setModel(S.wombo_combocode());
            ui->comboBox_code_m_3->setModel(S.wombo_combocode());
       }
       else
           mSystemTrayIcon->showMessage(tr("Message"),tr("Ajout non effectué"));

}

void MainWindow::on_pb_supprimer_3_clicked()
{
Service S1;
S1.setcode_s(ui->Scode_s_3->text().toInt());

bool test=S1.supprimer(S1.getcode_s());
if(test)
{

    mSystemTrayIcon->showMessage(tr("Message"),tr("Suppression effectué"));

     ui->tab_service_3->setModel(S.afficher());

    ui->comboBox_code_search_3->setModel(S.wombo_combocode());
     ui->comboBox_code_s_3->setModel(S.wombo_combocode());
     ui->comboBox_code_m_3->setModel(S.wombo_combocode());
}
else
    mSystemTrayIcon->showMessage(tr("Message"),tr("Suppression non effectué"));

}



void MainWindow::on_chehata_Valide_Modif_3_clicked()
{


    int code_s=ui->comboBox_code_m_3->currentText().toInt();
    QString desc_nv=ui->ndescriptions_3->text();
    QString type_snv=ui->type_nv_3->text();
    float prix_nv=ui->lineEdit_nv_prix_3->text().toFloat();





 Service S(code_s,desc_nv,type_snv,prix_nv);






       bool test=S.modifier(code_s);
       if(test)
       {

           mSystemTrayIcon->showMessage(tr("Message"),tr("Modification effectué"));

            ui->tab_service_3->setModel(S.afficher());

           ui->comboBox_code_search_3->setModel(S.wombo_combocode());
            ui->comboBox_code_s_3->setModel(S.wombo_combocode());
            ui->comboBox_code_m_3->setModel(S.wombo_combocode());
       }
       else
           mSystemTrayIcon->showMessage(tr("Message"),tr("Modification non effectué"));

   }




void MainWindow::on_search_pb_3_clicked()
{ int code_s=ui->comboBox_code_search_3->currentText().toInt();

    QSqlQueryModel* model=S.rechercher(code_s);


    ui->table_search_3->setModel(model);

}

void MainWindow::on_groupBox_5_3_clicked()
{

}

void MainWindow::on_pushButton_4_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec() == QDialog::Rejected)return;

    ui->label_148->render(&printer);


}



void MainWindow::on_pushButton_3_3_clicked()
{


  Service S;



  bool test=S.ajoutertime();
  if(test)
        {

      mSystemTrayIcon->showMessage(tr("Message"),tr("Effectué"));

            ui->tab_service_3->setModel(S.afficher());

            ui->comboBox_code_search_3->setModel(S.wombo_combocode());
             ui->comboBox_code_s_3->setModel(S.wombo_combocode());
             ui->comboBox_code_m_3->setModel(S.wombo_combocode());
        }
        else
      mSystemTrayIcon->showMessage(tr("Message"),tr("Le service est occupé"));


}

void MainWindow::on_pb_print2_3_clicked()
{
    QPrinter printer;
    printer.setPrinterName("desierd printer");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec() == QDialog::Rejected)return;

    ui->label_149->render(&printer);

}

void MainWindow::on_pushButton_2_3_clicked()
{
    //int code_s=ui->comboBox_code_m->currentText().toInt();

}

void MainWindow::on_table_search_3_activated(const QModelIndex &index)
{
   QString val=ui->table_search_3 ->model()->data(index).toString();
   QSqlQuery qry;
   qry.prepare("select * from SERVICE where CODE_S='"+val+"'");
   if (qry.exec())
   {while (qry.next()){
           ui->txt_code_3->setText(qry.value(0).toString());
            ui->txt_type_3->setText(qry.value(1).toString());
             ui->txt_description_3->setText(qry.value(2).toString());
              ui->txt_prix_3->setText(qry.value(3).toString());
       }


}
}

void MainWindow::on_promo_pb_3_clicked()
{
    int code_s=ui->comboBox_code_search_3->currentText().toInt();
    QString desc_nv=ui->txt_description_3->text();
    QString type_snv=ui->txt_type_3->text();
    int R=ui->prom_box_3->currentText().toInt();
    float prix_nv=ui->txt_prix_3->text().toFloat();
    prix_nv=prix_nv*(100-R)/100;





 Service S(code_s,desc_nv,type_snv,prix_nv);






       bool test=S.modifier(code_s);
       if(test)
       {

           mSystemTrayIcon->showMessage(tr("Message"),tr("Modification effectué"));


            ui->tab_service_3->setModel(S.afficher());

           ui->comboBox_code_search_3->setModel(S.wombo_combocode());
            ui->comboBox_code_s_3->setModel(S.wombo_combocode());
            ui->comboBox_code_m_3->setModel(S.wombo_combocode());
       }
       else
           mSystemTrayIcon->showMessage(tr("Message"),tr("Modification non effectué"));







}

void MainWindow::on_pb_stat_3_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                            model->setQuery("select * from SERVICE where PRIX < 100 ");
                            float prix1=model->rowCount();
                            model->setQuery("select * from SERVICE where PRIX  between 100 and 200 ");
                            float prix2=model->rowCount();
                            model->setQuery("select * from SERVICE where PRIX >300 ");
                            float prix3=model->rowCount();
                            float total=prix1+prix2+prix3;
                            QString a=QString("moins de 100 dt "+QString::number((prix1)/total,'f',2)+"%" );
                            QString b=QString("entre 100et 200dt "+QString::number((prix2)/total,'f',2)+"%" );
                            QString c=QString("300 et plus "+QString::number((prix3)/total,'f',2)+"%" );
                            QPieSeries *series = new QPieSeries();
                            series->append(a,prix1);
                            series->append(b,prix2);
                            series->append(c,prix3);
    if (prix1!=0)
                    {QPieSlice *slice = series->slices().at(0);
                     slice->setLabelVisible();
                     slice->setPen(QPen());}
                    if ( prix2!=0)
                    {
                             // Add label, explode and define brush for 2nd slice
                             QPieSlice *slice1 = series->slices().at(1);
                             //slice1->setExploded();
                             slice1->setLabelVisible();
                    }
                    if(prix3!=0)
                    {
                             // Add labels to rest of slices
                              QPieSlice *slice2 = series->slices().at(2);
                             //slice1->setExploded();
                             slice2->setLabelVisible();
                    }
                            // Create the chart widget
                            QChart *chart = new QChart();
                            // Add data to chart with title and hide legend
                            chart->addSeries(series);
                            chart->setTitle("statistique de"+ QString::number(total));
                            chart->legend()->hide();
                            // Used to display the chart
                            QChartView *chartView = new QChartView(chart);
                            chartView->setRenderHint(QPainter::Antialiasing);
                            chartView->resize(1000,500);
                            chartView->show();


}
//******************************************************AZIZ jaballah*******************************************


void MainWindow::on_pushButton_5_clicked()
{
    float somme=ui->ajout_amount->text().toFloat();
    QString categorie=ui->ajout_category->text();
    QString description=ui->ajout_description->text();
    int code=ui->ajout_code->text().toInt();

      Depense D( somme,categorie,description,code);
    bool    test=D.ajouter();

    if(test)
    {
        ui->tab_depense->setModel(Etmpp.afficher());

        mSystemTrayIcon->showMessage(tr("Message"),tr("Ajout effectué"));

    }
    else
        mSystemTrayIcon->showMessage(tr("Message"),tr("Ajout non effectué"));


 }


void MainWindow::on_supprimer_code_clicked()
{
    float code=ui->supp_code->text().toInt();
    bool test=Etmpp.supprimer(code);

    if(test)
    {
        ui->tab_depense->setModel(Etmpp.afficher());

        mSystemTrayIcon->showMessage(tr("Message"),tr("Suppression effectué"));


    }
    else
        mSystemTrayIcon->showMessage(tr("Message"),tr("Suppression non effectué"));


}



void MainWindow::on_pb_modifier_clicked()
{
    int code= ui->modifier_code->text().toInt();
    float somme = ui->modifier_somme->text().toFloat();
    float R=ui->remise->text().toFloat();
    QString categorie= ui->modifier_categorie->text();
    QString description= ui->modifier_description->text();
    somme=somme*(100-R)/100;


  Depense D(somme,categorie,description,code);
  bool test=D.modifier(code);
  if(test)
{
      ui->tab_depense->setModel(Etmpp.afficher());


      mSystemTrayIcon->showMessage(tr("Message"),tr("Modification effectué"));


}
  else
      mSystemTrayIcon->showMessage(tr("Message"),tr("Modification non effectué"));

}










void MainWindow::on_tab_depense_activated(const QModelIndex &index)
{
    QString val=ui->tab_depense ->model()->data(index).toString();
       QSqlQuery qry;
       qry.prepare("SELECT* FROM Comptabilite where CODE='"+val+"'");
       if (qry.exec())
       {while (qry.next()){
               ui->codetxt->setText(qry.value(0).toString());
                ui->descriptiontxt->setText(qry.value(4).toString());
                 ui->categorietxt->setText(qry.value(1).toString());
                  ui->amounttxt->setText(qry.value(3).toString());
           }


    }
}

void MainWindow::on_promos1_clicked()
{
    int code= ui->codetxt->text().toInt();
    float somme = ui->amounttxt->text().toFloat();
    float R=ui->appliquerpromos->text().toFloat();
    QString categorie= ui->categorietxt->text();
    QString description= ui->descriptiontxt->text();
    somme=somme*(100-R)/100;


  Depense D(somme,categorie,description,code);
  bool test=D.modifier(code);
  if(test)
{
      ui->tab_depense->setModel(Etmpp.afficher());


      mSystemTrayIcon->showMessage(tr("Message"),tr("Modification effectué"));


}
  else
      mSystemTrayIcon->showMessage(tr("Message"),tr("Modification non effectué"));


}

void MainWindow::on_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                                model->setQuery("select * from COMPTABILITE where SOMME < 100 ");
                                float SOMME1=model->rowCount();
                                model->setQuery("select * from COMPTABILITE where SOMME  between 100 and 200 ");
                                float SOMME2=model->rowCount();
                                model->setQuery("select * from COMPTABILITE where SOMME >300 ");
                                float SOMME3=model->rowCount();
                                float total=SOMME1+SOMME2+SOMME3;
                                QString a=QString("moins de 100 dt "+QString::number((SOMME1)/total,'f',2)+"%" );
                                QString b=QString("entre 100et 200dt "+QString::number((SOMME2)/total,'f',2)+"%" );
                                QString c=QString("300 et plus "+QString::number((SOMME3)/total,'f',2)+"%" );
                                QPieSeries *series = new QPieSeries();
                                series->append(a,SOMME1);
                                series->append(b,SOMME2);
                                series->append(c,SOMME3);
        if (SOMME1!=0)
                        {QPieSlice *slice = series->slices().at(0);
                         slice->setLabelVisible();
                         slice->setPen(QPen());}
                        if ( SOMME2!=0)
                        {

                                 QPieSlice *slice1 = series->slices().at(1);
                                 //slice1->setExploded();
                                 slice1->setLabelVisible();
                        }
                        if(SOMME3!=0)
                        {
                                 // Add labels to rest of slices
                                 QPieSlice *slice2 = series->slices().at(2);
                                 //slice1->setExploded();
                                 slice2->setLabelVisible();
                        }
                                // Create the chart widget
                                QChart *chart = new QChart();
                                // Add data to chart with title and hide legend
                                chart->addSeries(series);
                                chart->setTitle("statistique "+ QString::number(total));
                                chart->legend()->hide();
                                // Used to display the chart
                                QChartView *chartView = new QChartView(chart);
                                chartView->setRenderHint(QPainter::Antialiasing);
                                chartView->resize(1000,500);
                                chartView->show();
}



void MainWindow::on_imprimer2_clicked()
{
    QString strStream;
                         QTextStream out(&strStream);

                         const int rowCount = ui->tab_depense->model()->rowCount();
                         const int columnCount = ui->tab_depense->model()->columnCount();
                         QString TT = QDate::currentDate().toString("yyyy/MM/dd");
                         out <<"<html>\n"
                               "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             << "<title>ERP - COMmANDE LIST<title>\n "
                             << "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                             "<h1 style=\"text-align: center;\"><strong> *****LISTE DES  licence commerciale *****"+TT+" </strong></h1>"
                             "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                               "</br> </br>";
                         // headers
                         out << "<thead><tr bgcolor=#d6e5ff>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tab_depense->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tab_depense->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tab_depense->isColumnHidden(column)) {
                                     QString data =ui->tab_depense->model()->data(ui->tab_depense->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                             "</body>\n"
                             "</html>\n";

                         QTextDocument *document = new QTextDocument();
                         document->setHtml(strStream);

                         QPrinter printer;

                         QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                         if (dialog->exec() == QDialog::Accepted) {
                             document->print(&printer);
                         }

                         delete document;
}



void MainWindow::on_pushButton_clicked()
{
    A.write_to_arduino("1");
}

void MainWindow::on_Comptabilite_2_clicked()
{
    this->close();
}

void MainWindow::on_Chat_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}

void MainWindow::on_Comptabilite_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}
