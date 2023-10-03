#include "tab.h"
#include "calculator.h"
#include "notepad.h"
#include "todolist.h"

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
    todopage = new Todolist(this);
    textpage = new Notepad(this);
    maintab->addTab(calpage,"Calculator");
    maintab->addTab(todopage,"Todo-list");
    maintab->addTab(textpage,"Notepad");
}


void Tab::resizeEvent(QResizeEvent *event)
{
    maintab->setFixedSize(event->size().width(),event->size().height());
}
