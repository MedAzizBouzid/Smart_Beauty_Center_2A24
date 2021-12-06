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
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *widget;
    QWidget *widget_2;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QToolButton *toolButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(709, 686);
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
        lineEdit_2 = new QLineEdit(widget_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(9, 120, 191, 41));
        lineEdit_2->setStyleSheet(QLatin1String("QLineEdit{\n"
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
        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(9, 41, 201, 41));
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
        label->setStyleSheet(QLatin1String("#label{\n"
"	color: rgb(255, 255, 255);\n"
"	font: 36pt \"Nirmala UI\";\n"
"}\n"
""));
        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setGeometry(QRect(380, -20, 111, 131));
        toolButton->setStyleSheet(QStringLiteral("border: solid rgb(0,0,0) 30px"));
        toolButton->setIcon(icon);
        toolButton->setIconSize(QSize(128, 128));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Login", Q_NULLPTR));
        lineEdit_2->setPlaceholderText(QApplication::translate("Dialog", "Password", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("Dialog", "Username", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "Login", Q_NULLPTR));
        toolButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
