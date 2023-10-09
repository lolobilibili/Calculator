#ifndef TODOLIST_H
#define TODOLIST_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class Todolist; }
QT_END_NAMESPACE

class Todolist : public QMainWindow
{
    Q_OBJECT

public:
    Todolist(QWidget *parent = nullptr);
    ~Todolist();

    void setMax_todo(int);
    void sync_sql();
    void createANewRow(int,QString,bool,QString,QString,QString,QString,QString);
public slots:
    void add();
    void finish();
    void unfinish();
    void deleteCurrent();
    void clear();
    void edit();
    void clearFinished();
    void analyze();
private:
    Ui::Todolist *ui;
    QSqlDatabase todoDB;
    int global_max_todo;

    // QWidget interface
};
#endif // TODOLIST_H
