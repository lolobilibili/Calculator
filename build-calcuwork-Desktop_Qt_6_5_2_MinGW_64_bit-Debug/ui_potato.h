/********************************************************************************
** Form generated from reading UI file 'potato.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POTATO_H
#define UI_POTATO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Potato
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLCDNumber *Timer;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Potato)
    {
        if (Potato->objectName().isEmpty())
            Potato->setObjectName("Potato");
        Potato->resize(800, 600);
        centralwidget = new QWidget(Potato);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        Timer = new QLCDNumber(centralwidget);
        Timer->setObjectName("Timer");

        verticalLayout->addWidget(Timer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");

        verticalLayout->addWidget(pushButton_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        Potato->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Potato);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        Potato->setMenuBar(menubar);
        statusbar = new QStatusBar(Potato);
        statusbar->setObjectName("statusbar");
        Potato->setStatusBar(statusbar);

        retranslateUi(Potato);

        QMetaObject::connectSlotsByName(Potato);
    } // setupUi

    void retranslateUi(QMainWindow *Potato)
    {
        Potato->setWindowTitle(QCoreApplication::translate("Potato", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("Potato", "Start", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Potato", "Reset", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Potato", "Pause", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Potato: public Ui_Potato {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POTATO_H
