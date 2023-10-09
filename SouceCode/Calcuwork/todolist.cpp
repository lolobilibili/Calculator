#include "todolist.h"
#include "ui_todolist.h"
#include "dialog.h"
#include "dialog_edit.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include <QDialog>
#include <QAction>
#include <QDate>
#include <QResizeEvent>
#include <QFile>
#include <QDesktopServices>
#include <QStandardPaths>

Todolist::Todolist(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Todolist)
{
    ui->setupUi(this);

    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        todoDB = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        todoDB = QSqlDatabase::addDatabase("QSQLITE");
        todoDB.setDatabaseName("todoDB.db");
    }

    if (!todoDB.open())
    {
        qDebug() << "Error: Failed to connect database." << todoDB.lastError();
    }
    else
    {
        QSqlQuery sql_query(todoDB);
        QString create_sql = "create table if not exists todo (id int primary key, content text, status bool, daysleft int, est_time time, discription text,start_date text);";
        sql_query.prepare(create_sql);
        todoDB.exec(create_sql);
        qDebug() << sql_query.lastError();
    }
    ui->toolBar->setContextMenuPolicy(Qt::NoContextMenu);
    global_max_todo = 0;
    QStringList header;
    header = {"代办事项" , "完成情况" , "剩余天数", "所需时间", "备注","添加顺序","开始日期"};
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    sync_sql();
    connect(ui->actionadd, &QAction::triggered, this, &Todolist::add);
    connect(ui->actionfinished, &QAction::triggered, this, &Todolist::finish);
    connect(ui->actionunfinished, &QAction::triggered, this, &Todolist::unfinish);
    connect(ui->actiondelete_cur, &QAction::triggered, this, &Todolist::deleteCurrent);
    connect(ui->actionclear, &QAction::triggered, this, &Todolist::clear);
    connect(ui->actionedit, &QAction::triggered, this, &Todolist::edit);
    connect(ui->tableWidget,&QTableWidget::doubleClicked,this, &Todolist::edit);
    connect(ui->actionClear_finished, &QAction::triggered, this, &Todolist::clearFinished);
    connect(ui->actionanalyze, &QAction::triggered, this, &Todolist::analyze);
}

Todolist::~Todolist()
{
    delete ui;
    todoDB.close();
}

void Todolist::add(){
    QSqlQuery check_max("SELECT * from todo order by id desc limit 1");
    if(check_max.exec()){
        while(check_max.next()){
            qDebug() << check_max.value(0).toInt();
            global_max_todo = check_max.value(0).toInt();
        }
    }else{
        qDebug() << check_max.lastError();
    }


    Dialog *dlg = new Dialog(this);
    dlg->setTemp_max_todo(this->global_max_todo);
    dlg->sql_link(&todoDB);
    dlg->setWindowTitle(QStringLiteral("Add new Todo"));
    dlg->exec();
    sync_sql();
}

void Todolist::finish(){
    int currentrow = ui->tableWidget->currentRow();
    QSqlQuery finish;
    QString finish_sql = "update todo set status = true where id = (?)";
    finish.prepare(finish_sql);
    finish.addBindValue(ui->tableWidget->model()->index(currentrow,5).data().toString());
    if (finish.exec()){
        qDebug() << finish.lastError();
    }
    else{
        qDebug() << "Finished!";
    }
    sync_sql();
}

void Todolist::unfinish(){
    int currentrow = ui->tableWidget->currentRow();
    QSqlQuery unfinish;
    QString unfinish_sql = "update todo set status = false where id = (?)";
    unfinish.prepare(unfinish_sql);
    unfinish.addBindValue(ui->tableWidget->model()->index(currentrow,5).data().toString());
    if (unfinish.exec()){
        qDebug() << "Unfinished!";
    }
    else{
        qDebug() << unfinish.lastError();
    }
    sync_sql();
}

void Todolist::deleteCurrent(){
    int currentrow = ui->tableWidget->currentRow();
    QSqlQuery delete_cur;
    QString deletecur_sql = "delete from todo where id = (?)";
    delete_cur.prepare(deletecur_sql);
    delete_cur.addBindValue(ui->tableWidget->model()->index(currentrow,5).data().toString());
    if (delete_cur.exec()){
        qDebug() << "Deleted!";
    }
    else{
        qDebug() << delete_cur.lastError();
    }
    sync_sql();
}

void Todolist::clear(){
    QSqlQuery clear("drop table todo");
    clear.exec();
    qDebug() << clear.lastError();
    clear.prepare("create table if not exists todo (id int primary key, content text, status bool, daysleft int, est_time time, discription text,start_date text);");
    clear.exec();
    global_max_todo = 0;
    qDebug() << clear.lastError();
    sync_sql();
}

void Todolist::edit(){
    int currentrow = ui->tableWidget->currentRow();
    int id = ui->tableWidget->model()->index(currentrow,5).data().toInt();
    QString discrip = ui->tableWidget->model()->index(currentrow,4).data().toString();
    QString est_time = ui->tableWidget->model()->index(currentrow,3).data().toString();
    QDate date = QDate::currentDate().addDays((ui->tableWidget->model()->index(currentrow,2).data().toInt()));
    QString todo = ui->tableWidget->model()->index(currentrow,0).data().toString();
    QString startdate = ui->tableWidget->model()->index(currentrow,6).data().toString();
    Dialog_edit* dlg_ed = new Dialog_edit(this,id,date,todo,est_time,discrip,startdate);
    dlg_ed->setWindowTitle(QStringLiteral("Edit Todo"));
    dlg_ed->exec();
    sync_sql();
}

void Todolist::clearFinished(){
    QSqlQuery selectFinished;
    selectFinished.exec("DELETE FROM todo where status = true");
    if(selectFinished.exec()){
        qDebug() << "DELETED";
    }
    else{
        qDebug() << selectFinished.lastError();
    }
    sync_sql();
}
void Todolist::setMax_todo(int max_todo){
    this->global_max_todo = max_todo;
}

void Todolist::sync_sql(){
    QSqlQuery sync;
    sync.exec("select * from todo");
    qDebug() << sync.lastError();
    int rownum = 0;
    while(sync.next()){
        rownum ++;
    }
    qDebug() << rownum;
    ui->tableWidget->setRowCount(rownum);
    sync.exec("select id, content, status, daysleft ,est_time, discription,start_date from todo order by status desc, daysleft,est_time");
    qDebug()<< sync.lastError();
    int row = 0;

    while(sync.next()){
        QString todo = sync.value(1).toString();
        bool status = sync.value(2).toBool();
        QString duedate = sync.value(3).toString();
        QString est_time = QString(sync.value(4).toTime().toString());
        QString disc = sync.value(5).toString();
        QString order = sync.value(0).toString();
        QString start = sync.value(6).toString();
        createANewRow(row,todo,status,duedate,est_time,disc,order,start);
        row ++;
    }
}

void Todolist::createANewRow(int row, QString todo, bool status, QString duedate,QString est_time, QString disc, QString order,QString start){
    QTableWidgetItem *item;
    item = new QTableWidgetItem(todo);
    ui->tableWidget->setItem(row,0,item);

    QString sta_str;
    if(status){
        sta_str = "已完成";
    }else{
        sta_str = "未完成";
    }
    item = new QTableWidgetItem(sta_str);
    ui->tableWidget->setItem(row,1,item);

    item = new QTableWidgetItem(duedate);
    ui->tableWidget->setItem(row,2,item);

    item = new QTableWidgetItem(est_time);
    ui->tableWidget->setItem(row,3,item);

    item = new QTableWidgetItem(disc);
    ui->tableWidget->setItem(row,4,item);

    item = new QTableWidgetItem(order);
    ui->tableWidget->setItem(row,5,item);

    item = new QTableWidgetItem(start);
    ui->tableWidget->setItem(row,6,item);
}

void Todolist::analyze(){

    if (ui->tableWidget->rowCount() == 0){
        return;
    }
    QSqlQuery analyze;
    analyze.exec("select content,est_time,start_date,status from todo where status != true");
    qDebug() << analyze.lastError();
    QString content_str;
    QString time_str;
    QString duration_str;

    while(analyze.next()){
        content_str += analyze.value(0).toString();
        content_str += "|";
        duration_str += QString::number(abs(analyze.value(1).toTime().secsTo(QTime::fromString("00:00:00","hh:mm:ss")))/1800);
        duration_str += "|";
        time_str += ("'" + analyze.value(2).toString() + "'");
        time_str += "|";
        qDebug() << "Status:" << analyze.value(3).toString();
    }
    qDebug() << content_str << duration_str << time_str;

    QString path = QCoreApplication::applicationDirPath();
    qDebug() << path;

    std::string arrays = content_str.toStdString();
    arrays = arrays.substr(0,arrays.length() - 1);
    std::string dates = time_str.toStdString();
    dates = dates.substr(0,dates.length() - 1);
    std::string durations = duration_str.toStdString();
    durations = durations.substr(0,durations.length() - 1);
    qDebug()<<arrays << dates << durations;

    QFile file(QStandardPaths::writableLocation(QStandardPaths::HomeLocation) + "/Releaseanalyze.txt");
    file.rename("Releaseanalyze.txt");
    file.resize(0);
    file.open(QIODevice::ReadWrite | QIODevice::Text);
    QByteArray str = QString::fromStdString(arrays + '\t').toUtf8();
    file.write(str);
    str = QString::fromStdString(dates+'\t').toUtf8();
    file.write(str);
    str = QString::fromStdString(durations).toUtf8();
    file.write(str);
    QDesktopServices::openUrl(QUrl::fromLocalFile(path + "./script_new/script_new.exe"));

}
