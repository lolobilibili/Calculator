#include "potato.h"
#include "ui_potato.h"

#define BORDER_COLOR QColor(222, 222, 222, 222)
#define BACKGROUND_COLOR QColor(255, 255, 255, 255)
#define RADIUS 15

Potato::Potato(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Potato)
{
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint | Qt::WindowStaysOnTopHint);
    state = true; //暂停
    potato_num = 0;
    start_num = 0;
    ui->setupUi(this);
    QFont font("Rockwell", 13);
    font.setBold(true);
    timer = new QTimer;
    ui->Timer->setFont(font);
    ui->Timer->setDigitCount(5);
    ui->Timer->setLineWidth(0);
    ui->Timer->setSegmentStyle(QLCDNumber::Filled);
    timer->setInterval(1000);
    InitTime();
}


void Potato::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);  // 抗锯齿

    QPen pen(BORDER_COLOR);
    pen.setWidth(1);  // 设置边框
    painter.setPen(pen);

    QBrush brush(BACKGROUND_COLOR);
    painter.setBrush(brush);

    QRectF rect(0, 0, this->width(), this->height());
    painter.drawRoundedRect(rect, RADIUS, RADIUS);  // 设置矩形的圆角
}

void Potato::mouseMoveEvent(QMouseEvent * e)
{
    if(e->buttons()&Qt::LeftButton)
        move(e->globalPos()-clickPos);
}

void Potato::mousePressEvent(QMouseEvent * e)
{
    if(e->button()&Qt::LeftButton)
    {

        clickPos=e->globalPos()-this->geometry().topLeft();
    }
}

Potato::~Potato()
{
    delete ui;
}

void Potato::InitTime()
{
    time.setHMS(0,25,0);
    ui->Timer->display(time.toString("mm:ss"));
    ui->Timer->setStyleSheet ("color:red");
}

void Potato::updateTime()
{
    time = time.addSecs(-1);
    ui->Timer->display(time.toString("mm:ss"));
    if(time.minute() == 0  && time.second() == 0 && potato_num==1)
    {
//        休息完毕
        potato_num = 0;
        InitTime();
        timer->stop();
        state = false;
//        ui->pushButton->setStyleSheet("QPushButton{border-image: url(:/imgs/startt.png);border:none;}");
    }
    if(time.minute() == 0  && time.second() == 0 && potato_num==0)
    {
//        进入休息
        potato_num = 1;
        time.setHMS(0,5,0);
        ui->Timer->setStyleSheet ("color:green");
    }
}





void Potato::on_pushButton_clicked()
{
    start_num++;
    if(state)
    {
        timer->start();
        if(start_num==1)
        {
            connect(timer,SIGNAL(timeout()),this,SLOT(updateTime()));
        }
//        ui->pushButton->setStyleSheet("QPushButton{border-image: url(:/imgs/stop.png);border:none;}");
    }
    else
    {
        timer->start();
//        ui->pushButton->setStyleSheet("QPushButton{border-image: url(:/imgs/startt.png);border:none;}");
//        InitTime();
    }
    state = !state;
}


void Potato::on_pushButton_2_clicked()
{
    timer->stop();
    InitTime();
}



void Potato::on_pushButton_3_clicked()
{
//  进入暂停
    timer->stop();
}

