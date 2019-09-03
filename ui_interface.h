/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Interface
{
public:
    QAction *actionTest;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *Login;
    QGridLayout *gridLayout_3;
    QPushButton *Connect;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *passwd;
    QSpacerItem *horizontalSpacer_3;
    QWidget *main;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *tempInt;
    QLabel *tempExt;
    QLabel *label_3;
    QLabel *label_4;
    QFormLayout *formLayout_4;
    QLabel *label;
    QLabel *status;
    QPushButton *btConnection;
    QPushButton *Set;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout;
    QLabel *stateZ1;
    QPushButton *bStateZ1;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_2;
    QLabel *modeZ1;
    QPushButton *bModeZ1;
    QLabel *label_9;
    QLabel *tmpRestZ1;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_3;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_5;
    QLabel *stateZ2;
    QPushButton *bStateZ2;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_4;
    QLabel *modeZ2;
    QPushButton *bModeZ2;
    QLabel *label_15;
    QLabel *tmpRestZ2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *Chart;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Interface)
    {
        if (Interface->objectName().isEmpty())
            Interface->setObjectName(QString::fromUtf8("Interface"));
        Interface->resize(1024, 541);
        actionTest = new QAction(Interface);
        actionTest->setObjectName(QString::fromUtf8("actionTest"));
        centralWidget = new QWidget(Interface);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Login = new QWidget(centralWidget);
        Login->setObjectName(QString::fromUtf8("Login"));
        gridLayout_3 = new QGridLayout(Login);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        Connect = new QPushButton(Login);
        Connect->setObjectName(QString::fromUtf8("Connect"));

        gridLayout_3->addWidget(Connect, 2, 2, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        label_2 = new QLabel(Login);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_3->addWidget(label_2, 1, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 0, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_3, 3, 2, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_4, 2, 3, 1, 1);

        passwd = new QLineEdit(Login);
        passwd->setObjectName(QString::fromUtf8("passwd"));
        passwd->setEchoMode(QLineEdit::Password);

        gridLayout_3->addWidget(passwd, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 2, 0, 1, 2);


        gridLayout->addWidget(Login, 2, 0, 1, 1);

        main = new QWidget(centralWidget);
        main->setObjectName(QString::fromUtf8("main"));
        gridLayout_2 = new QGridLayout(main);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(main);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        tempInt = new QLabel(groupBox);
        tempInt->setObjectName(QString::fromUtf8("tempInt"));
        tempInt->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::FieldRole, tempInt);

        tempExt = new QLabel(groupBox);
        tempExt->setObjectName(QString::fromUtf8("tempExt"));
        tempExt->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, tempExt);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_4);


        gridLayout_2->addWidget(groupBox, 0, 1, 1, 1);

        formLayout_4 = new QFormLayout();
        formLayout_4->setSpacing(6);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label = new QLabel(main);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label);

        status = new QLabel(main);
        status->setObjectName(QString::fromUtf8("status"));
        status->setAlignment(Qt::AlignCenter);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, status);

        btConnection = new QPushButton(main);
        btConnection->setObjectName(QString::fromUtf8("btConnection"));

        formLayout_4->setWidget(1, QFormLayout::SpanningRole, btConnection);

        Set = new QPushButton(main);
        Set->setObjectName(QString::fromUtf8("Set"));

        formLayout_4->setWidget(2, QFormLayout::SpanningRole, Set);


        gridLayout_2->addLayout(formLayout_4, 0, 2, 1, 1);

        groupBox_2 = new QGroupBox(main);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stateZ1 = new QLabel(groupBox_2);
        stateZ1->setObjectName(QString::fromUtf8("stateZ1"));
        stateZ1->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(stateZ1, 0, Qt::AlignHCenter);

        bStateZ1 = new QPushButton(groupBox_2);
        bStateZ1->setObjectName(QString::fromUtf8("bStateZ1"));

        horizontalLayout->addWidget(bStateZ1, 0, Qt::AlignHCenter);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_8);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        modeZ1 = new QLabel(groupBox_2);
        modeZ1->setObjectName(QString::fromUtf8("modeZ1"));
        modeZ1->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(modeZ1);

        bModeZ1 = new QPushButton(groupBox_2);
        bModeZ1->setObjectName(QString::fromUtf8("bModeZ1"));

        horizontalLayout_2->addWidget(bModeZ1);


        formLayout_2->setLayout(1, QFormLayout::FieldRole, horizontalLayout_2);

        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_9);

        tmpRestZ1 = new QLabel(groupBox_2);
        tmpRestZ1->setObjectName(QString::fromUtf8("tmpRestZ1"));
        tmpRestZ1->setAlignment(Qt::AlignCenter);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, tmpRestZ1);


        gridLayout_2->addWidget(groupBox_2, 1, 1, 2, 1);

        groupBox_3 = new QGroupBox(main);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        formLayout_3 = new QFormLayout(groupBox_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_11);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        stateZ2 = new QLabel(groupBox_3);
        stateZ2->setObjectName(QString::fromUtf8("stateZ2"));
        stateZ2->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(stateZ2);

        bStateZ2 = new QPushButton(groupBox_3);
        bStateZ2->setObjectName(QString::fromUtf8("bStateZ2"));

        horizontalLayout_5->addWidget(bStateZ2);


        formLayout_3->setLayout(0, QFormLayout::FieldRole, horizontalLayout_5);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_13);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        modeZ2 = new QLabel(groupBox_3);
        modeZ2->setObjectName(QString::fromUtf8("modeZ2"));
        modeZ2->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(modeZ2);

        bModeZ2 = new QPushButton(groupBox_3);
        bModeZ2->setObjectName(QString::fromUtf8("bModeZ2"));

        horizontalLayout_4->addWidget(bModeZ2);


        formLayout_3->setLayout(1, QFormLayout::FieldRole, horizontalLayout_4);

        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_15);

        tmpRestZ2 = new QLabel(groupBox_3);
        tmpRestZ2->setObjectName(QString::fromUtf8("tmpRestZ2"));
        tmpRestZ2->setAlignment(Qt::AlignCenter);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, tmpRestZ2);


        gridLayout_2->addWidget(groupBox_3, 1, 2, 2, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 1, 3, 1, 1);

        horizontalSpacer = new QSpacerItem(267, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 2, 0, 1, 1);

        Chart = new QVBoxLayout();
        Chart->setSpacing(6);
        Chart->setObjectName(QString::fromUtf8("Chart"));

        gridLayout_2->addLayout(Chart, 3, 0, 1, 4);


        gridLayout->addWidget(main, 0, 0, 1, 1);

        Interface->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Interface);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 25));
        Interface->setMenuBar(menuBar);
        statusBar = new QStatusBar(Interface);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Interface->setStatusBar(statusBar);

        retranslateUi(Interface);

        QMetaObject::connectSlotsByName(Interface);
    } // setupUi

    void retranslateUi(QMainWindow *Interface)
    {
        Interface->setWindowTitle(QCoreApplication::translate("Interface", "Interface", nullptr));
        actionTest->setText(QCoreApplication::translate("Interface", "Test", nullptr));
        Connect->setText(QCoreApplication::translate("Interface", "Connection", nullptr));
        label_2->setText(QCoreApplication::translate("Interface", "Mot de passe", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Interface", "Temp\303\251rature", nullptr));
        tempInt->setText(QCoreApplication::translate("Interface", "NULL", nullptr));
        tempExt->setText(QCoreApplication::translate("Interface", "NULL", nullptr));
        label_3->setText(QCoreApplication::translate("Interface", "Int\303\251rieur", nullptr));
        label_4->setText(QCoreApplication::translate("Interface", "Ext\303\251rieur", nullptr));
        label->setText(QCoreApplication::translate("Interface", "Status", nullptr));
        status->setText(QCoreApplication::translate("Interface", "Connected", nullptr));
        btConnection->setText(QCoreApplication::translate("Interface", "Connect", nullptr));
        Set->setText(QCoreApplication::translate("Interface", "Modifier", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Interface", "Zone 1", nullptr));
        label_5->setText(QCoreApplication::translate("Interface", "Etat", nullptr));
        stateZ1->setText(QCoreApplication::translate("Interface", "NULL", nullptr));
        bStateZ1->setText(QCoreApplication::translate("Interface", "PushButton", nullptr));
        label_8->setText(QCoreApplication::translate("Interface", "Mode", nullptr));
        modeZ1->setText(QCoreApplication::translate("Interface", "NULL", nullptr));
        bModeZ1->setText(QCoreApplication::translate("Interface", "PushButton", nullptr));
        label_9->setText(QCoreApplication::translate("Interface", "Temps restant", nullptr));
        tmpRestZ1->setText(QCoreApplication::translate("Interface", "NULL", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Interface", "Zone 2", nullptr));
        label_11->setText(QCoreApplication::translate("Interface", "Etat", nullptr));
        stateZ2->setText(QCoreApplication::translate("Interface", "NULL", nullptr));
        bStateZ2->setText(QCoreApplication::translate("Interface", "PushButton", nullptr));
        label_13->setText(QCoreApplication::translate("Interface", "Mode", nullptr));
        modeZ2->setText(QCoreApplication::translate("Interface", "NULL", nullptr));
        bModeZ2->setText(QCoreApplication::translate("Interface", "PushButton", nullptr));
        label_15->setText(QCoreApplication::translate("Interface", "Temps restant", nullptr));
        tmpRestZ2->setText(QCoreApplication::translate("Interface", "NULL", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Interface: public Ui_Interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
