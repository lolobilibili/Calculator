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

Dialog_edit::Dialog_edit(QWidget *parent,int id, QDate date, QString todo, QString est_time,QString discrip,QString start):
    QDialog(parent),
    ui(new Ui::Dialog_edit)
{
    ui->setupUi(this);
    this->currentID = id;
    ui->lineEdit->setText(todo);
    ui->dateEdit->setDate(date);
    ui->timeEdit->setTime(QTime::fromString(est_time));
    ui->plainTextEdit->setPlainText(discrip);
    ui->dateEdit_2->setDate(QDate::fromString(start,"yyyy-MM-dd"));
    ui->timeEdit->setMinimumTime(QTime::fromString("00:30:00","hh:mm:ss"));
    ui->timeEdit->setMaximumTime(QTime::fromString("05:00:00","hh:mm:ss"));
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
    QString edit_sql = "update todo set content = (?), daysleft = (?), est_time = (?),discription = (?) ,start_date = (?) where id = (?)";
    edit.prepare(edit_sql);
    edit.addBindValue(ui->lineEdit->text());
    edit.addBindValue(QString::number(days));
    edit.addBindValue(ui->timeEdit->time().toString("hh:mm:ss"));
    edit.addBindValue(ui->plainTextEdit->toPlainText());
    edit.addBindValue(ui->dateEdit_2->date().toString("yyyy-MM-dd"));
    edit.addBindValue(QString::number(currentID));
    if(edit.exec()){
        qDebug()<<"Edited!";
    }else{
        qDebug()<< edit.lastError();
    }
}

