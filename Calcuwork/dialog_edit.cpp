#include "dialog_edit.h"
#include "ui_dialog_edit.h"
#include "todolist.h"

#include <QSqlDatabase>
#include <QDate>
#include <QSqlQuery>
#include <QDebug>

Dialog_edit::Dialog_edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_edit)
{
    ui->setupUi(this);
}

Dialog_edit::Dialog_edit(QWidget *parent,int id, QDate date, QString todo, QString discrip):
    QDialog(parent),
    ui(new Ui::Dialog_edit)
{
    ui->setupUi(this);
    this->currentID = id;
    ui->lineEdit->setText(todo);
    ui->dateEdit->setDate(date);
    ui->plainTextEdit->setPlainText(discrip);
}

Dialog_edit::~Dialog_edit()
{
    delete ui;
}




void Dialog_edit::on_buttonBox_accepted()
{
    QSqlQuery edit;
    QDate now = QDate::currentDate();
    int days = now.daysTo(ui->dateEdit->date());
    QString edit_sql = "update todo set content = (?), daysleft = (?), discription = (?) where id = (?)";
    edit.prepare(edit_sql);
    edit.addBindValue(ui->lineEdit->text());
    edit.addBindValue(QString::number(days));
    edit.addBindValue(ui->plainTextEdit->toPlainText());
    edit.addBindValue(QString::number(currentID));
    if(edit.exec()){
        qDebug()<<"Edited!";
    }else{
        qDebug()<< edit.lastError();
    }
}

