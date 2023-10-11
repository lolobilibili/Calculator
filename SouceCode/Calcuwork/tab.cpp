#include "tab.h"
#include "calculator.h"
#include "notepad.h"
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
    calpage = new Calculator(this);
    todopage = new Todolist(this);
    textpage = new Notepad(this);
    potatopage = new Potato(this);
    maintab->addTab(calpage,"计算器");
    maintab->addTab(todopage,"待办事项");
    maintab->addTab(potatopage,"番茄钟");
    maintab->addTab(textpage,"记事本");
    maintab->setFixedSize(600,400);
}


void Tab::resizeEvent(QResizeEvent *event)
{
    maintab->setFixedSize(event->size().width(),event->size().height());
}
