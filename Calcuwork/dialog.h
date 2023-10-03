#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void setTemp_max_todo(int);
    void sql_link(QSqlDatabase*);

private slots:
    void on_buttonBox_accepted();
private:
    Ui::Dialog *ui;
    int temp_max_todo;
    QSqlDatabase *parent_database;
};

#endif // DIALOG_H
