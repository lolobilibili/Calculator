/********************************************************************************
** Form generated from reading UI file 'todolist.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TODOLIST_H
#define UI_TODOLIST_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Todolist
{
public:
    QAction *actionadd;
    QAction *actionfinished;
    QAction *actionunfinished;
    QAction *actiondelete_cur;
    QAction *actionclear;
    QAction *actionedit;
    QAction *actionClear_finished;
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *Todolist)
    {
        if (Todolist->objectName().isEmpty())
            Todolist->setObjectName("Todolist");
        Todolist->resize(800, 600);
        actionadd = new QAction(Todolist);
        actionadd->setObjectName("actionadd");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionadd->setIcon(icon);
        actionfinished = new QAction(Todolist);
        actionfinished->setObjectName("actionfinished");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/images/finished.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionfinished->setIcon(icon1);
        actionunfinished = new QAction(Todolist);
        actionunfinished->setObjectName("actionunfinished");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/images/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionunfinished->setIcon(icon2);
        actiondelete_cur = new QAction(Todolist);
        actiondelete_cur->setObjectName("actiondelete_cur");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/images/minus.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiondelete_cur->setIcon(icon3);
        actionclear = new QAction(Todolist);
        actionclear->setObjectName("actionclear");
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/images/images/delete_all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionclear->setIcon(icon4);
        actionedit = new QAction(Todolist);
        actionedit->setObjectName("actionedit");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/images/images/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionedit->setIcon(icon5);
        actionClear_finished = new QAction(Todolist);
        actionClear_finished->setObjectName("actionClear_finished");
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/images/images/clear.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear_finished->setIcon(icon6);
        centralwidget = new QWidget(Todolist);
        centralwidget->setObjectName("centralwidget");
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(20, 10, 761, 511));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy);
        tableWidget->setSizeIncrement(QSize(0, 0));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        Todolist->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Todolist);
        statusbar->setObjectName("statusbar");
        Todolist->setStatusBar(statusbar);
        toolBar = new QToolBar(Todolist);
        toolBar->setObjectName("toolBar");
        Todolist->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionadd);
        toolBar->addAction(actiondelete_cur);
        toolBar->addSeparator();
        toolBar->addAction(actionfinished);
        toolBar->addAction(actionunfinished);
        toolBar->addAction(actionedit);
        toolBar->addAction(actionClear_finished);
        toolBar->addAction(actionclear);

        retranslateUi(Todolist);

        QMetaObject::connectSlotsByName(Todolist);
    } // setupUi

    void retranslateUi(QMainWindow *Todolist)
    {
        Todolist->setWindowTitle(QCoreApplication::translate("Todolist", "Todolist", nullptr));
        actionadd->setText(QCoreApplication::translate("Todolist", "add", nullptr));
        actionadd->setIconText(QCoreApplication::translate("Todolist", "Add", nullptr));
#if QT_CONFIG(whatsthis)
        actionadd->setWhatsThis(QCoreApplication::translate("Todolist", "Add new ToDo", nullptr));
#endif // QT_CONFIG(whatsthis)
        actionfinished->setText(QCoreApplication::translate("Todolist", "finished", nullptr));
        actionfinished->setIconText(QCoreApplication::translate("Todolist", "Finished", nullptr));
#if QT_CONFIG(whatsthis)
        actionfinished->setWhatsThis(QCoreApplication::translate("Todolist", "Set current Todo finished", nullptr));
#endif // QT_CONFIG(whatsthis)
        actionunfinished->setText(QCoreApplication::translate("Todolist", "unfinished", nullptr));
        actionunfinished->setIconText(QCoreApplication::translate("Todolist", "Unfinished", nullptr));
#if QT_CONFIG(whatsthis)
        actionunfinished->setWhatsThis(QCoreApplication::translate("Todolist", "Set current Todo unfinished", nullptr));
#endif // QT_CONFIG(whatsthis)
        actiondelete_cur->setText(QCoreApplication::translate("Todolist", "delete_cur", nullptr));
        actiondelete_cur->setIconText(QCoreApplication::translate("Todolist", "Delete selected", nullptr));
#if QT_CONFIG(whatsthis)
        actiondelete_cur->setWhatsThis(QCoreApplication::translate("Todolist", "Delete current Todo", nullptr));
#endif // QT_CONFIG(whatsthis)
        actionclear->setText(QCoreApplication::translate("Todolist", "clear", nullptr));
        actionclear->setIconText(QCoreApplication::translate("Todolist", "Clear all", nullptr));
        actionedit->setText(QCoreApplication::translate("Todolist", "edit", nullptr));
        actionedit->setIconText(QCoreApplication::translate("Todolist", "Edit selected", nullptr));
#if QT_CONFIG(whatsthis)
        actionedit->setWhatsThis(QCoreApplication::translate("Todolist", "Edit current Todo", nullptr));
#endif // QT_CONFIG(whatsthis)
        actionClear_finished->setText(QCoreApplication::translate("Todolist", "Clear finished", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("Todolist", "toolBar", nullptr));
#if QT_CONFIG(whatsthis)
        toolBar->setWhatsThis(QCoreApplication::translate("Todolist", "set current todo unfinished", nullptr));
#endif // QT_CONFIG(whatsthis)
    } // retranslateUi

};

namespace Ui {
    class Todolist: public Ui_Todolist {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TODOLIST_H
