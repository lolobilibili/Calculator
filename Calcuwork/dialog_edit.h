#ifndef DIALOG_EDIT_H
#define DIALOG_EDIT_H

#include <QDialog>
#include <QSqlDatabase>
#include <QDate>

namespace Ui {
class Dialog_edit;
}

class Dialog_edit : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_edit(QWidget *parent = nullptr);
    Dialog_edit(QWidget *parent,int,QDate,QString,QString);
    ~Dialog_edit();
    void setInfo(int,QDate,QString,QString);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Dialog_edit *ui;
    int currentID;
};

#endif // DIALOG_EDIT_H
