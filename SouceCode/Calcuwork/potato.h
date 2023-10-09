#ifndef POTATO_H
#define POTATO_H

#include <QMainWindow>
#include <QWidget>
#include <QMouseEvent>
#include <QTime>
#include <QTimer>
#include <QPainter>
#include <QFont>
#include <QVBoxLayout>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class Potato; }
QT_END_NAMESPACE

class Potato : public QMainWindow
{
    Q_OBJECT

public:
    Potato(QWidget *parent = nullptr);
    ~Potato();
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

private slots:
    void updateTime();
    void InitTime();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Potato *ui;
    bool state; //暂停
    int potato_num; //土豆计数
    int start_num; //启动计数，只有第一次记录才有connect操作
    QString current_color;
    QPoint clickPos;
    QTimer *timer;
    QTime time;
    QPushButton *startbutton;

};



#endif // POTATO_H
