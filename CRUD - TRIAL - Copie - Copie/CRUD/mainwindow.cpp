#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fournisseur.h"
#include "dialog.h"
#include <QLoggingCategory>
#include <QDesktopServices>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Refresh();
    ui->engine->addItem("Default", QString("default"));
    foreach (QString engine, QTextToSpeech::availableEngines())
        ui->engine->addItem(engine, engine);
    ui->engine->setCurrentIndex(0);
    engineSelected(0);
    m_speech->say("Bienvenue utilisateur");
    connect(ui->speakButton, &QPushButton::clicked, this, &MainWindow::speak);
    connect(ui->pitch, &QSlider::valueChanged, this, &MainWindow::setPitch);
    connect(ui->rate, &QSlider::valueChanged, this, &MainWindow::setRate);
    connect(ui->volume, &QSlider::valueChanged, this, &MainWindow::setVolume);
    connect(ui->engine, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::engineSelected);
}
void MainWindow::Refresh(){
    ui->Affiche->setModel(fou.afficher());
    ui->comboBox_modif->setModel(fou.wombo_combo());
    ui->Localisation_combobox->setModel(fou.wombo_combo_local());
    ui->comboBox_supprim->setModel(fou.wombo_combo());
    Model_Completer=new QCompleter(this);
    Model_Completer->setModel(fou.wombo_combo());
    ui->lineEdit_chercher->setCompleter(Model_Completer);
    Model_Completer=new QCompleter(this);
    Model_Completer->setModel(fou.wombo_combo_type());
    //ui->lineEdit_chercher_type->setCompleter(Model_Completer);
    ui->lineEdit_tri->setCompleter(Model_Completer);
    Model_Completer=new QCompleter(this);
    Model_Completer->setModel(fou.wombo_combo_local());
    //ui->lineEdit_chercher_local->setCompleter(Model_Completer);
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
        m_speech->say("Code Invalid.");
        m_speech->say("Cliquez sur Annuler pour quitter.");
        QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                 QObject::tr("Code Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
    }

    else if(!verif_num)
    {
        m_speech->say("Numero Invalid.");
        m_speech->say("Cliquez sur Annuler pour quitter.");
        QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                 QObject::tr("Numero Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
    }

    else if(!verif_prix)
    {
        m_speech->say("Prix Invalid.");
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
        m_speech->say("Localisation Invalid.");
        m_speech->say("Cliquez sur Annuler pour quitter.");
        QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                 QObject::tr("Localisation Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
    }

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
        m_speech->say("Code Invalid.");
        m_speech->say("Cliquez sur Annuler pour quitter.");
        QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                 QObject::tr("Code Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
    }


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
        m_speech->say("Code Invalid.");
        m_speech->say("Cliquez sur Annuler pour quitter.");
        QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                 QObject::tr("Code Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
    }

    else if(!verif_num)
    {
        m_speech->say("Numero Invalid.");
        m_speech->say("Cliquez sur Annuler pour quitter.");
        QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                 QObject::tr("Numero Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
    }

    else if(!verif_prix)
    {
        m_speech->say("Prix Invalid.");
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

    else if(!verif_localisation)
    {
        m_speech->say("Localisation Invalid.");
        m_speech->say("Cliquez sur Annuler pour quitter.");
        QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                 QObject::tr("Localisation Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
    }

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
        m_speech->say("Code Invalid.");
        m_speech->say("Cliquez sur Annuler pour quitter.");
        QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                 QObject::tr("Code Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);}

}

void MainWindow::on_Tri_clicked()
{
    QString type=ui->lineEdit_tri->text();
    bool verif_type=controle_numero(type);
    if(verif_type)
        ui->Table_tri->setModel(fou.tri(ui->lineEdit_tri->text()));
    else
        QMessageBox::critical(nullptr,QObject::tr("ECHEC"),
                                 QObject::tr("Type Invalid.\n""Cliquez sur Annuler pour quitter."),QMessageBox::Cancel);
}

void MainWindow::speak()
{
    m_speech->say(ui->plainTextEdit->toPlainText());
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
    if (state == QTextToSpeech::Speaking) {
        ui->statusbar->showMessage("Speech started...");
    } else if (state == QTextToSpeech::Ready)
        ui->statusbar->showMessage("Speech stopped...", 2000);
    else if (state == QTextToSpeech::Paused)
        ui->statusbar->showMessage("Speech paused...");
    else
        ui->statusbar->showMessage("Speech error!");

    ui->pauseButton->setEnabled(state == QTextToSpeech::Speaking);
    ui->resumeButton->setEnabled(state == QTextToSpeech::Paused);
    ui->stopButton->setEnabled(state == QTextToSpeech::Speaking || state == QTextToSpeech::Paused);
}

void MainWindow::engineSelected(int index)
{
    QString engineName = ui->engine->itemData(index).toString();
    //delete m_speech;
    if (engineName == "default")
        m_speech = new QTextToSpeech(this);
    else
        m_speech = new QTextToSpeech(engineName, this);
    disconnect(ui->language, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::languageSelected);
    ui->language->clear();
    // Populate the languages combobox before connecting its signal.
    QVector<QLocale> locales = m_speech->availableLocales();
    QLocale current = m_speech->locale();
    foreach (const QLocale &locale, locales) {
        QString name(QString("%1 (%2)")
                     .arg(QLocale::languageToString(locale.language()))
                     .arg(QLocale::countryToString(locale.country())));
        QVariant localeVariant(locale);
        ui->language->addItem(name, localeVariant);
        if (locale.name() == current.name())
            current = locale;
    }
    setRate(ui->rate->value());
    setPitch(ui->pitch->value());
    setVolume(ui->volume->value());
    connect(ui->stopButton, &QPushButton::clicked, m_speech, &QTextToSpeech::stop);
    connect(ui->pauseButton, &QPushButton::clicked, m_speech, &QTextToSpeech::pause);
    connect(ui->resumeButton, &QPushButton::clicked, m_speech, &QTextToSpeech::resume);

    connect(m_speech, &QTextToSpeech::stateChanged, this, &MainWindow::stateChanged);
    connect(m_speech, &QTextToSpeech::localeChanged, this, &MainWindow::localeChanged);

    connect(ui->language, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::languageSelected);
    localeChanged(current);
}

void MainWindow::languageSelected(int language)
{
    QLocale locale = ui->language->itemData(language).toLocale();
    m_speech->setLocale(locale);
}

void MainWindow::voiceSelected(int index)
{
    m_speech->setVoice(m_voices.at(index));
}

void MainWindow::localeChanged(const QLocale &locale)
{
    QVariant localeVariant(locale);
    ui->language->setCurrentIndex(ui->language->findData(localeVariant));

    disconnect(ui->voice, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::voiceSelected);
    ui->voice->clear();

    m_voices = m_speech->availableVoices();
    QVoice currentVoice = m_speech->voice();
    foreach (const QVoice &voice, m_voices) {
        ui->voice->addItem(QString("%1 - %2 - %3").arg(voice.name())
                          .arg(QVoice::genderName(voice.gender()))
                          .arg(QVoice::ageName(voice.age())));
        if (voice.name() == currentVoice.name())
            ui->voice->setCurrentIndex(ui->voice->count() - 1);
    }
    connect(ui->voice, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &MainWindow::voiceSelected);
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_speakButton_clicked()
{

}

void MainWindow::on_lineEdit_chercher_textChanged(const QString &code)
{
    ui->chercher->setModel(fou.cherhcer(code));

}

void MainWindow::on_lineEdit_chercher_type_textChanged(const QString &type)
{
    ui->chercher->setModel(fou.cherhcer(type));

}



void MainWindow::on_pushButton_2_clicked()
{
    Dialog d;
    d.setModal(true);
    d.exec();
}

void MainWindow::on_lineEdit_tri_textChanged(const QString &type)
{
    ui->Table_tri->setModel(fou.tri(type));

}

void MainWindow::on_Localisation_clicked()
{
    QString p=ui->Localisation_combobox->currentText();
    QDesktopServices::openUrl(QUrl("http://maps.google.com.sg/maps?q="+p+"&oe=utf-8&rls=org.mozilla:en-US:official&client=firefox-a&um=1&ie=UTF-8&hl=en&sa=N&tab=wl"));

}
