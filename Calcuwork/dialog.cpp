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
    QString insert_sql = "insert into todo values (?, ?, ?, ?, ?)";
    add.prepare(insert_sql);
    qDebug() << temp_max_todo;
    add.addBindValue(this->temp_max_todo + 1);
    add.addBindValue(ui->lineEdit->text());
    add.addBindValue("False");
    add.addBindValue(days);
    add.addBindValue(ui->plainTextEdit->toPlainText());

    if(!add.exec())
    {
        qDebug() << add.lastError();
    }
    else
    {
        qDebug() << "inserted!";
    }

}
void Dialog::sql_link(QSqlDatabase* db){
    this->parent_database = db;
}

