#include "tab.h"
#include "calculator.h"
#include "todolist.h"
#include "potato.h"
#include <QTabWidget>
#include <QSizePolicy>
#include <QLayout>
#include <QResizeEvent>

Tab::Tab(QWidget* parent)
    : QWidget(parent)
{
    maintab = new QTabWidget(this);
    maintab->setFixedSize(400,400);
    calpage = new Calculator(this);
    textpage = new Notepad(this);
    todopage = new ToDoList(this);
    potatoclock = new Potato(this);
    maintab->addTab(calpage,"Calculator");
    maintab->addTab(textpage,"Notepad");
    maintab->addTab(todopage,"ToDoList");
    maintab->addTab(potatoclock,"PotatoClock");
}


void Tab::resizeEvent(QResizeEvent *event)
{
    maintab->setFixedSize(event->size().width(),event->size().height());
}
