/********************************************************************************
** Form generated from reading UI file 'dialog_edit.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_EDIT_H
#define UI_DIALOG_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_edit
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QDateEdit *dateEdit;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *Dialog_edit)
    {
        if (Dialog_edit->objectName().isEmpty())
            Dialog_edit->setObjectName("Dialog_edit");
        Dialog_edit->resize(400, 300);
        buttonBox = new QDialogButtonBox(Dialog_edit);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(40, 250, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        gridLayoutWidget = new QWidget(Dialog_edit);
        gridLayoutWidget->setObjectName("gridLayoutWidget");
        gridLayoutWidget->setGeometry(QRect(9, 9, 371, 241));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        dateEdit = new QDateEdit(gridLayoutWidget);
        dateEdit->setObjectName("dateEdit");

        gridLayout->addWidget(dateEdit, 1, 1, 1, 1);

        plainTextEdit = new QPlainTextEdit(gridLayoutWidget);
        plainTextEdit->setObjectName("plainTextEdit");

        gridLayout->addWidget(plainTextEdit, 2, 1, 1, 1);


        retranslateUi(Dialog_edit);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog_edit, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog_edit, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog_edit);
    } // setupUi

    void retranslateUi(QDialog *Dialog_edit)
    {
        Dialog_edit->setWindowTitle(QCoreApplication::translate("Dialog_edit", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog_edit", "Due Date", nullptr));
        label->setText(QCoreApplication::translate("Dialog_edit", "To do", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog_edit", "Discription", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_edit: public Ui_Dialog_edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_EDIT_H
