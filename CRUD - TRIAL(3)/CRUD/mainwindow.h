#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseur.h"
#include <QMainWindow>
#include <QCompleter>
#include <QDirModel>
#include <QtWidgets/qmainwindow.h>

#include "ui_mainwindow.h"

#include <QTextToSpeech>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_tabWidget_tabCloseRequested(int index);

    void on_pushButton_7_clicked();

    void on_Ajouter_clicked();

    void on_Supprimer_clicked();

    void on_Valide_Modif_clicked();

    void on_Chercher_clicked();

    void on_Tri_clicked();

    void on_Chercher_type_clicked();

    void on_Chercher_local_clicked();
    void Refresh();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    fournisseur fou;
    QCompleter* Model_Completer;
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

private slots:
    void on_speakButton_clicked();

private:

    QTextToSpeech *m_speech;
    QVector<QVoice> m_voices;
};
#endif // MAINWINDOW_H
