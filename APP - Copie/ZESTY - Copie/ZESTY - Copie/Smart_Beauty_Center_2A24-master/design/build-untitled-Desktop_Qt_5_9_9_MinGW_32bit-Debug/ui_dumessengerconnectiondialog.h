/********************************************************************************
** Form generated from reading UI file 'dumessengerconnectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DUMESSENGERCONNECTIONDIALOG_H
#define UI_DUMESSENGERCONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DuMessengerConnectionDialog
{
public:
    QLineEdit *hostname;
    QLabel *label_2;
    QPushButton *pb_accepter;
    QSpinBox *port;
    QLabel *label;
    QPushButton *pb_cancel;

    void setupUi(QDialog *DuMessengerConnectionDialog)
    {
        if (DuMessengerConnectionDialog->objectName().isEmpty())
            DuMessengerConnectionDialog->setObjectName(QStringLiteral("DuMessengerConnectionDialog"));
        DuMessengerConnectionDialog->resize(697, 484);
        hostname = new QLineEdit(DuMessengerConnectionDialog);
        hostname->setObjectName(QStringLiteral("hostname"));
        hostname->setGeometry(QRect(290, 180, 351, 20));
        label_2 = new QLabel(DuMessengerConnectionDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(188, 180, 71, 30));
        pb_accepter = new QPushButton(DuMessengerConnectionDialog);
        pb_accepter->setObjectName(QStringLiteral("pb_accepter"));
        pb_accepter->setGeometry(QRect(490, 290, 75, 23));
        port = new QSpinBox(DuMessengerConnectionDialog);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(290, 240, 354, 20));
        port->setMaximum(999999999);
        label = new QLabel(DuMessengerConnectionDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(209, 250, 51, 20));
        pb_cancel = new QPushButton(DuMessengerConnectionDialog);
        pb_cancel->setObjectName(QStringLiteral("pb_cancel"));
        pb_cancel->setGeometry(QRect(571, 290, 75, 23));

        retranslateUi(DuMessengerConnectionDialog);

        QMetaObject::connectSlotsByName(DuMessengerConnectionDialog);
    } // setupUi

    void retranslateUi(QDialog *DuMessengerConnectionDialog)
    {
        DuMessengerConnectionDialog->setWindowTitle(QApplication::translate("DuMessengerConnectionDialog", "Dialog", Q_NULLPTR));
        label_2->setText(QApplication::translate("DuMessengerConnectionDialog", "Hostname", Q_NULLPTR));
        pb_accepter->setText(QApplication::translate("DuMessengerConnectionDialog", "accepter", Q_NULLPTR));
        label->setText(QApplication::translate("DuMessengerConnectionDialog", "Port", Q_NULLPTR));
        pb_cancel->setText(QApplication::translate("DuMessengerConnectionDialog", "cancel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DuMessengerConnectionDialog: public Ui_DuMessengerConnectionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DUMESSENGERCONNECTIONDIALOG_H
