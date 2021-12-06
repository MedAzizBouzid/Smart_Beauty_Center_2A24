/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QToolButton *toolButton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(645, 686);
        QIcon icon;
        icon.addFile(QStringLiteral(":/243530218_1310825109377240_1931357582866907769_n.ico"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        Dialog->setStyleSheet(QLatin1String("*{\n"
"border-radius: 15px;\n"
"}"));
        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(70, 50, 471, 590));
        widget->setStyleSheet(QLatin1String("background-color: rgb(36,34,44);\n"
"	color: #000000;"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(140, 180, 211, 221));
        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(0, 90, 201, 51));
        lineEdit->setStyleSheet(QLatin1String("QLineEdit{\n"
"border: 2px solid rgb(37,39,48);\n"
"border-radius: 20px;\n"
"color:#FFF;\n"
"padding-right: 20px;\n"
"padding-left: 20px;\n"
"background-color: rgb(69, 65, 85);\n"
"}\n"
"QLineEdit:hover{\n"
"border: 2px solid rgb(38,50,62);\n"
"}\n"
"QLineEdit:focus{\n"
"border: 2px solid rgb(35,170,250);\n"
"background-color: rgb(103, 97, 126);\n"
"}"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(170, 90, 151, 91));
        QFont font;
        font.setFamily(QStringLiteral("Vijaya"));
        font.setPointSize(36);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QLatin1String("#label{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 36pt \"Vijaya\";\n"
"}\n"
""));
        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(380, -20, 111, 131));
        toolButton->setStyleSheet(QStringLiteral("border: solid rgb(0,0,0) 30px"));
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(128, 128));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(150, 450, 171, 41));
        pushButton->setStyleSheet(QLatin1String("QPushButton{\n"
"border:  solid rgb(37,39,48);\n"
"color:#FFF;\n"
"background-color: rgb(69, 65, 85);\n"
"	font: 19pt \"Vijaya\";\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"font: Bold;\n"
"	background-color: rgb(206, 19, 2);\n"
"}\n"
"QPushButton:focus{\n"
"	background-color: rgb(255, 0, 0);\n"
"font: Bold;\n"
"}\n"
"\n"
""));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(140, 510, 191, 41));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{\n"
"border:  solid rgb(37,39,48);\n"
"color:#FFF;\n"
"background-color: rgb(69, 65, 85);\n"
"	font: 19pt \"Vijaya\";\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"font: Bold;\n"
"	background-color: rgb(206, 19, 2);\n"
"}\n"
"QPushButton:focus{\n"
"	background-color: rgb(255, 0, 0);\n"
"font: Bold;\n"
"}\n"
"\n"
""));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Login", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("Dialog", "CIN", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "Login", Q_NULLPTR));
        toolButton->setText(QString());
        pushButton->setText(QApplication::translate("Dialog", "Login", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Dialog", "WATCH VIDEO", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
