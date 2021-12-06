/********************************************************************************
** Form generated from reading UI file 'notepad.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOTEPAD_H
#define UI_NOTEPAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Notepad
{
public:
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *New;
    QPushButton *Open;
    QPushButton *Save;
    QPushButton *pushButton_4;
    QPushButton *Copy;
    QPushButton *Paste;
    QPushButton *Cut;
    QPushButton *pushButton_10;
    QPushButton *Redo;
    QPushButton *pushButton_2;
    QTextEdit *textEdit;

    void setupUi(QDialog *Notepad)
    {
        if (Notepad->objectName().isEmpty())
            Notepad->setObjectName(QStringLiteral("Notepad"));
        Notepad->resize(1224, 565);
        groupBox = new QGroupBox(Notepad);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 1207, 84));
        QFont font;
        font.setFamily(QStringLiteral("MV Boli"));
        font.setPointSize(10);
        groupBox->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        New = new QPushButton(groupBox);
        New->setObjectName(QStringLiteral("New"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        New->setIcon(icon);
        New->setIconSize(QSize(20, 20));
        New->setCheckable(false);

        horizontalLayout_2->addWidget(New);

        Open = new QPushButton(groupBox);
        Open->setObjectName(QStringLiteral("Open"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        Open->setIcon(icon1);
        Open->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(Open);

        Save = new QPushButton(groupBox);
        Save->setObjectName(QStringLiteral("Save"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/save.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Save->setIcon(icon2);
        Save->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(Save);

        pushButton_4 = new QPushButton(groupBox);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/save as.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon3);
        pushButton_4->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(pushButton_4);

        Copy = new QPushButton(groupBox);
        Copy->setObjectName(QStringLiteral("Copy"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        Copy->setIcon(icon4);
        Copy->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(Copy);

        Paste = new QPushButton(groupBox);
        Paste->setObjectName(QStringLiteral("Paste"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        Paste->setIcon(icon5);
        Paste->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(Paste);

        Cut = new QPushButton(groupBox);
        Cut->setObjectName(QStringLiteral("Cut"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        Cut->setIcon(icon6);
        Cut->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(Cut);

        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/undo.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_10->setIcon(icon7);
        pushButton_10->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(pushButton_10);

        Redo = new QPushButton(groupBox);
        Redo->setObjectName(QStringLiteral("Redo"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/redo.png"), QSize(), QIcon::Normal, QIcon::Off);
        Redo->setIcon(icon8);
        Redo->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(Redo);

        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon9);
        pushButton_2->setIconSize(QSize(20, 20));

        horizontalLayout_2->addWidget(pushButton_2);

        textEdit = new QTextEdit(Notepad);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 90, 1207, 470));
        textEdit->setFont(font);

        retranslateUi(Notepad);

        QMetaObject::connectSlotsByName(Notepad);
    } // setupUi

    void retranslateUi(QDialog *Notepad)
    {
        Notepad->setWindowTitle(QApplication::translate("Notepad", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Notepad", "Les Controles", Q_NULLPTR));
        New->setText(QApplication::translate("Notepad", "Nouveau", Q_NULLPTR));
        Open->setText(QApplication::translate("Notepad", "Ouvrir", Q_NULLPTR));
        Save->setText(QApplication::translate("Notepad", "Enregistrer", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Notepad", "Enregistrer Sous", Q_NULLPTR));
        Copy->setText(QApplication::translate("Notepad", "Copier", Q_NULLPTR));
        Paste->setText(QApplication::translate("Notepad", "Coller", Q_NULLPTR));
        Cut->setText(QApplication::translate("Notepad", "Couper", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("Notepad", "Annuler", Q_NULLPTR));
        Redo->setText(QApplication::translate("Notepad", "Refaire", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Notepad", "A Propos", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Notepad: public Ui_Notepad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOTEPAD_H
