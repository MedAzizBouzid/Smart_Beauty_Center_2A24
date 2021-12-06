#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//****************OUSSAMA INCLUDES*******************
#include "fournisseur.h"
#include <QMainWindow>
#include <QCompleter>
#include <QDirModel>
#include <QTextToSpeech>


//*****************BOUZID INCLUDES********************
#include"produit.h"
#include <QDirModel>
#include<QSystemTrayIcon>
#include "qrcode.h"
#include<QTcpSocket>
#include "arduino.h"

//*****************MARIEM INCLUDES*********************
#include "client.h"
#include "smtp.h"
//*****************SALIM INCLUDES*********************
#include "employe.h"

//*****************AZIZ chehata*************************

#include"service.h"
#include<QTextEdit>
#include<QtCharts>
#include<QChartView>
//**************************AZIZ jaballah*************************
#include "depense.h"
#include <QtCharts>
#include <QChartView>
#include <QSqlQuery>
#include <QLineSeries>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QSystemTrayIcon *Get_notif(){return mSystemTrayIcon;};


private slots:
    void on_Acceuil_clicked();
    void Refresh();
    void on_Fournisseurs_clicked();
    void on_Produits_clicked();
    void on_Services_clicked();
    void on_Employes_clicked();
    void on_Client_clicked();
    void on_Comptabilite_clicked();



    //******************OUSSAMA****************
    void on_Ajouter_fournisseur_clicked();
    void speak();
    void stop();
    void setRate(int);
    void setPitch(int);
    void setVolume(int volume);
    void stateChanged(QTextToSpeech::State state);
    void engineSelected(int index);
    void languageSelected(int language);
    void voiceSelected(int index);
    void localeChanged(const QLocale &locale);
    void on_Supprimer_fournisseur_clicked();
    void on_Localisation_fournisseur_clicked();
    void on_lineEdit_chercher_fournisseur_textChanged(const QString &arg1);
    void on_lineEdit_chercher_type_fournisseur_textChanged(const QString &arg1);
    void on_lineEdit_chercher_local_fournisseur_textChanged(const QString &arg1);
    void on_lineEdit_tri_fournisseur_textChanged(const QString &arg1);
    void on_Chercher_fournisseur_clicked();
    void on_Valide_Modif_fournisseur_clicked();
    void on_Tri_clicked();
    void on_pushButton_2_fournisseur_clicked();




    //**********************BOUZID****************************************
    void on_pb_ajouterbouzid_4_clicked();
    void on_pb_supprimerbouzid_4_clicked();
    void on_pb_modifierbouzid_4_clicked();
    void on_pb_rechercherbouzid_4_clicked();
    void on_pb_trinombouzid_4_clicked();
    void on_pb_imprimerbouzid_4_clicked();
    void on_pb_typebouzid_4_clicked();
    void on_pb_quantitebouzid_4_clicked();
    void on_pb_prixbouzid_4_clicked();
    void on_pb_recherchernombouzid_4_clicked();
    void on_pb_recherchertypebouzid_4_clicked();
    void on_notifierpbbouzid_4_clicked();
    void on_PDFbouzid_4_clicked();
    void on_pb_Qrcodebouzid_4_clicked();




    //**********************MARIEM********************************************
    void on_pbajoutermariem_clicked();
    void on_pb_suppmariem_clicked();
    void on_pbmodifiermariem_clicked();
    void on_pbrecherchermariem_clicked();
    void on_codemailmariem_returnPressed();
    void on_pb_mailmariem_clicked();
    void sendMail();
    void mailSent(QString);
    void on_calendarWidgetmariem_clicked(const QDate &date);



    void on_B_AjoutEmploye_2_clicked();

    void on_B_deleteEmploye_2_clicked();

    void on_B_ModifierEmploye_2_clicked();

    void on_pushButtonEmploye_2_clicked();

    void on_Tri_nomEmploye_2_clicked();

    void on_PDFEmploye_2_clicked();

    void on_backgroundmodif_tabCloseRequested(int index);

    void on_pb_connecter_clicked();

    void on_pb_envoyer_clicked();
    void on_tabWidget_tabCloseRequested(int index);

    void on_pb_ajouter_3_clicked();

    void on_pb_supprimer_3_clicked();

    void on_chehata_Valide_Modif_3_clicked();

    void on_groupBox_5_3_clicked();

    void on_search_pb_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_3_clicked();

    void on_pb_print2_3_clicked();

    void on_pushButton_2_3_clicked();

    void on_table_search_3_activated(const QModelIndex &index);

    void on_promo_pb_3_clicked();

    void on_pb_stat_3_clicked();

    void on_chehata_pb_ajouter_3_clicked();
    //******************AZIZ jaballah *****************************
    void on_pushButton_5_clicked();

    void on_supprimer_code_clicked();

    void on_pb_modifier_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_pushButton_2_clicked();

    void on_remise_button_clicked();

    void on_promos1_clicked();

    void on_tab_depense_activated(const QModelIndex &index);

    void on_stat_clicked();

    void on_imprimer2_clicked();

    void on_pushButton_clicked();

    void on_Comptabilite_2_clicked();

    void on_Chat_clicked();

    void on_Comptabilite_4_clicked();

public:
    QTextToSpeech * Get_speak(){return m_speech;};
private:
    Ui::MainWindow *ui;
   //***********OUSSAMA****************
    fournisseur fou;
    QCompleter* Model_Completer;
    QTextToSpeech *m_speech;
    QVector<QVoice> m_voices;
//***************BOUZID*****************

    Produit Pro;

      QCompleter* Model_Completer1;
       QCompleter* Model_Completer2;
       QSystemTrayIcon *mSystemTrayIcon;
       QTcpSocket *mSocket;

//****************MARIEM*******************
       Client Ctmp;
       QCompleter* Model_CompleterM, Model_CompleterM1;
       //****************SALIM*******************
       Employe Etmp;
       QCompleter* Model_Completers;

       //*******************AZIZ chehata*************************

              Service S;
           QSqlQuery qry;
           //*****************AZIZ jaballah*****************
            Depense Etmpp;
            Arduino A; // objet temporaire


};
#endif // MAINWINDOW_H
