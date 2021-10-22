/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *ajout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *groupBox_2;
    QLabel *label_9;
    QLineEdit *lineEdit_5;
    QLabel *label_10;
    QLineEdit *lineEdit_6;
    QLabel *label_11;
    QLineEdit *lineEdit_7;
    QLabel *label_12;
    QLineEdit *lineEdit_8;
    QLabel *label;
    QWidget *modif;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QGroupBox *groupBox;
    QLabel *label_5;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QWidget *supprim;
    QLabel *label_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QGroupBox *groupBox_3;
    QLabel *label_8;
    QLineEdit *lineEdit_4;
    QWidget *affich;
    QLabel *label_4;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QGroupBox *groupBox_4;
    QLabel *label_13;
    QLineEdit *lineEdit_9;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(787, 515);
        QIcon icon;
        icon.addFile(QStringLiteral("../../../../../../Downloads/livraison-fournisseurs-achats-gestion-commerciale.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QFont font;
        font.setFamily(QStringLiteral("Leelawadee"));
        font.setItalic(false);
        tabWidget->setFont(font);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideNone);
        tabWidget->setTabsClosable(true);
        tabWidget->setMovable(true);
        ajout = new QWidget();
        ajout->setObjectName(QStringLiteral("ajout"));
        pushButton = new QPushButton(ajout);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(410, 410, 93, 28));
        QFont font1;
        font1.setFamily(QStringLiteral("MV Boli"));
        font1.setItalic(false);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(ajout);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(620, 410, 93, 28));
        pushButton_2->setFont(font1);
        groupBox_2 = new QGroupBox(ajout);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setEnabled(true);
        groupBox_2->setGeometry(QRect(20, 10, 311, 381));
        groupBox_2->setMouseTracking(false);
        groupBox_2->setAutoFillBackground(false);
        groupBox_2->setFlat(true);
        groupBox_2->setCheckable(false);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 80, 161, 31));
        label_9->setFont(font1);
        lineEdit_5 = new QLineEdit(groupBox_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(170, 80, 113, 22));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(0, 180, 101, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("MV Boli"));
        font2.setPointSize(8);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        label_10->setFont(font2);
        lineEdit_6 = new QLineEdit(groupBox_2);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(140, 180, 161, 61));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(0, 280, 181, 31));
        label_11->setFont(font1);
        lineEdit_7 = new QLineEdit(groupBox_2);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(160, 280, 113, 22));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(0, 350, 101, 21));
        label_12->setFont(font1);
        lineEdit_8 = new QLineEdit(groupBox_2);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));
        lineEdit_8->setGeometry(QRect(160, 350, 113, 22));
        label = new QLabel(ajout);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-1150, 20, 1941, 431));
        QFont font3;
        font3.setFamily(QStringLiteral("Nirmala UI Semilight"));
        font3.setItalic(false);
        label->setFont(font3);
        label->setPixmap(QPixmap(QString::fromUtf8("../../../../b1.jpg")));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../../../../Downloads/plus.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(ajout, icon1, QString());
        label->raise();
        pushButton->raise();
        pushButton_2->raise();
        groupBox_2->raise();
        modif = new QWidget();
        modif->setObjectName(QStringLiteral("modif"));
        label_2 = new QLabel(modif);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(380, 0, 381, 371));
        label_2->setPixmap(QPixmap(QString::fromUtf8("../../../../../../Downloads/livraison-fournisseurs-achats-gestion-commerciale.png")));
        pushButton_3 = new QPushButton(modif);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(440, 410, 93, 28));
        pushButton_3->setFont(font1);
        pushButton_4 = new QPushButton(modif);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(630, 410, 93, 28));
        pushButton_4->setFont(font1);
        groupBox = new QGroupBox(modif);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        groupBox->setGeometry(QRect(10, 10, 341, 301));
        groupBox->setMouseTracking(false);
        groupBox->setAutoFillBackground(false);
        groupBox->setFlat(true);
        groupBox->setCheckable(false);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 80, 131, 31));
        label_5->setFont(font1);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 80, 113, 22));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 180, 231, 31));
        label_6->setFont(font1);
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(240, 180, 91, 22));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../../../../../Downloads/modiif.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(modif, icon2, QString());
        supprim = new QWidget();
        supprim->setObjectName(QStringLiteral("supprim"));
        label_3 = new QLabel(supprim);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(386, 6, 371, 371));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../../../../Downloads/livraison-fournisseurs-achats-gestion-commerciale.png")));
        pushButton_5 = new QPushButton(supprim);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(420, 410, 93, 28));
        pushButton_5->setFont(font1);
        pushButton_6 = new QPushButton(supprim);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(630, 410, 93, 28));
        pushButton_6->setFont(font1);
        groupBox_3 = new QGroupBox(supprim);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setEnabled(true);
        groupBox_3->setGeometry(QRect(20, 40, 341, 111));
        groupBox_3->setMouseTracking(false);
        groupBox_3->setAutoFillBackground(false);
        groupBox_3->setFlat(true);
        groupBox_3->setCheckable(false);
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 80, 151, 31));
        label_8->setFont(font1);
        lineEdit_4 = new QLineEdit(groupBox_3);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(170, 80, 113, 22));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../../../../../../Downloads/miinus.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(supprim, icon3, QString());
        affich = new QWidget();
        affich->setObjectName(QStringLiteral("affich"));
        label_4 = new QLabel(affich);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setEnabled(true);
        label_4->setGeometry(QRect(390, 0, 371, 371));
        label_4->setPixmap(QPixmap(QString::fromUtf8("../../../../../../Downloads/livraison-fournisseurs-achats-gestion-commerciale.png")));
        pushButton_7 = new QPushButton(affich);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(410, 410, 93, 28));
        pushButton_7->setFont(font1);
        pushButton_8 = new QPushButton(affich);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(620, 410, 93, 28));
        pushButton_8->setFont(font1);
        groupBox_4 = new QGroupBox(affich);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setEnabled(true);
        groupBox_4->setGeometry(QRect(20, 50, 341, 111));
        groupBox_4->setMouseTracking(false);
        groupBox_4->setAutoFillBackground(false);
        groupBox_4->setFlat(true);
        groupBox_4->setCheckable(false);
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(0, 80, 151, 31));
        label_13->setFont(font1);
        lineEdit_9 = new QLineEdit(groupBox_4);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));
        lineEdit_9->setGeometry(QRect(170, 80, 113, 22));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../../../../../../Downloads/afficher.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(affich, icon4, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 2, 1);


        horizontalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des fournisseurs", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Annuler", Q_NULLPTR));
        groupBox_2->setTitle(QString());
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; color:#ffffff;\">code des produits :</span></p></body></html>", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; color:#ffffff;\">description: </span></p></body></html>", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; color:#ffffff;\">type: </span></p></body></html>", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt; color:#ffffff;\">prix: </span></p></body></html>", Q_NULLPTR));
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(ajout), QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        tabWidget->setTabToolTip(tabWidget->indexOf(ajout), QApplication::translate("MainWindow", "Ajout d\"un fournisseur", Q_NULLPTR));
        label_2->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Annuler", Q_NULLPTR));
        groupBox->setTitle(QString());
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">code des produits :</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">donner le nouveau prix :</span></p><p><br/></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(modif), QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        tabWidget->setTabToolTip(tabWidget->indexOf(modif), QApplication::translate("MainWindow", "Modifier fournisseur", Q_NULLPTR));
        label_3->setText(QString());
        pushButton_5->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "Annuler", Q_NULLPTR));
        groupBox_3->setTitle(QString());
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">code des produits :</span></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(supprim), QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        label_4->setText(QString());
        pushButton_7->setText(QApplication::translate("MainWindow", "Valider", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "Annuler", Q_NULLPTR));
        groupBox_4->setTitle(QString());
        label_13->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">code des produits :</span></p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(affich), QApplication::translate("MainWindow", "Afficher", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
