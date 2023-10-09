#include "dialog.h"
#include "ui_dialog.h"
#include "todolist.h"

#include <QSqlDatabase>
#include <QDate>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->dateEdit->setDate(QDate::currentDate());
    ui->dateEdit_2->setDate(QDate::currentDate());
    ui->timeEdit->setTime(QTime::fromString("00:30:00","hh:mm:ss"));
    ui->timeEdit->setMinimumTime(QTime::fromString("00:00:01","hh:mm:ss"));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setTemp_max_todo(int max_todo){
    this->temp_max_todo = max_todo;
}
void Dialog::on_buttonBox_accepted()
{
    QSqlQuery add;
    QDate now = QDate::currentDate();
    int days = now.daysTo(ui->dateEdit->date());
    QString est_time = ui->timeEdit->time().toString("hh:mm:ss");
    QString insert_sql = "insert into todo values (?, ?, ?, ?, ?, ?,?)";
    add.prepare(insert_sql);
    qDebug() << temp_max_todo;
    add.addBindValue(this->temp_max_todo + 1);
    add.addBindValue(ui->lineEdit->text());
    add.addBindValue("False");
    add.addBindValue(days);
    add.addBindValue(est_time);
    add.addBindValue(ui->plainTextEdit->toPlainText());
    add.addBindValue(ui->dateEdit_2->date().toString("yyyy-MM-dd"));

    if(!add.exec())
    {
        qDebug() << add.lastError();
    }
    else
    {
        qDebug() << "inserted!" << add.value(5);
    }

}
void Dialog::sql_link(QSqlDatabase* db){
    this->parent_database = db;
}

