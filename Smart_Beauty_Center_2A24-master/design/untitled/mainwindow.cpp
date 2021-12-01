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
#define NOM_RX "^([a-z]+[A-Z]+[ ]?|[a-z]+[A-Z])+$"
#define NUM_RX "^([0-9]+[,.]?)+$"
      QRegExp rxNom(NOM_RX);
      QRegExp rxNum(NUM_RX);
      QRegExpValidator* valiNom= new QRegExpValidator(rxNom);
       QRegExpValidator* valiNum= new QRegExpValidator(rxNum);
//*********************************************************












MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



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
                                    QMessageBox::information(nullptr,QObject::tr("OK"),
                                                             QObject::tr("Ajout avec succes.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);


                                }else
                                {
                                    m_speech->say("Ajout échoue.");
                                    m_speech->say("Cliquez sur Annuler pour quitter.");
                                    QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                             QObject::tr("Ajout échoue.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                                }


                            }else if(!verif_code)
                            {
                                m_speech->say("Code Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                         QObject::tr("Code Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                            }

                            else if(!verif_num)
                            {
                                m_speech->say("Numero Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                         QObject::tr("Numero Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                            }

                            else if(!verif_prix)
                            {
                                m_speech->say("Prix Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                         QObject::tr("Prix Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                            }

                            else if(!verif_type)
                            {
                                m_speech->say("Type Invalid.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                         QObject::tr("Type Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                            }

                            else if(!verif_local)
                            {
                                m_speech->say("Localisation Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                         QObject::tr("Localisation Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
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
                                    QMessageBox::information(nullptr,QObject::tr("OK"),
                                                             QObject::tr("Suppression avec Succès.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                                }
                                else
                                {
                                    m_speech->say("Suppression échoue.");
                                    m_speech->say("Cliquez sur Annuler pour quitter.");
                                    QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                             QObject::tr("Suppression échoue.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                                }


                                }else
                            {
                                m_speech->say("Code Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                         QObject::tr("Code Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
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
                                 QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                        QObject::tr("Un attribut à la fois!\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                             }
                            }

                            else
                            {
                                m_speech->say("Code Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                         QObject::tr("Code Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);}
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
                                    QMessageBox::information(nullptr,QObject::tr("OK"),
                                                             QObject::tr("Modification avec Succès.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                                }else
                                {
                                    m_speech->say("Modification échoue.");
                                    m_speech->say("Cliquez sur Annuler pour quitter.");
                                    QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                             QObject::tr("Modification échoue.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                                }

                            }else if(!verif_code || !verif_id)
                            {
                                m_speech->say("Code Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                         QObject::tr("Code Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                            }

                            else if(!verif_num)
                            {
                                m_speech->say("Numero Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                         QObject::tr("Numero Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                            }

                            else if(!verif_prix)
                            {
                                m_speech->say("Prix Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                         QObject::tr("Prix Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                            }

                            else if(!verif_type)
                            {
                                m_speech->say("Type Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                         QObject::tr("Type Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                            }

                            else if(!verif_localisation)
                            {
                                m_speech->say("Localisation Invalide.");
                                m_speech->say("Cliquez sur Annuler pour quitter.");
                                QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                         QObject::tr("Localisation Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
                            }
                        }

                        void MainWindow::on_Tri_clicked()
                        {
                            QString type=ui->lineEdit_tri_fournisseur->text();
                            bool verif_type=controle_numero(type);
                            if(verif_type)
                                ui->Table_tri_fournisseur->setModel(fou.tri(ui->lineEdit_tri_fournisseur->text()));
                            else
                                QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                                         QObject::tr("Type Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
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
                QMessageBox::critical(nullptr,QObject::tr("Modifier produit"),QObject::tr("Modification non effectué.\n Click cancel to exit."),QMessageBox::Cancel);
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
                           QMessageBox::information(nullptr, QObject::tr("QrCode"),
                                                    QObject::tr("Veuillez Choisir un produit du Tableau.\n"
                                                                "Click Ok to exit."), QMessageBox::Ok);
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




