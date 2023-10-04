#ifndef TAB_H
#define TAB_H

#endif // TAB_H
#include "calculator.h"
#include "notepad.h"
#include "todolist.h"
#include <QTabWidget>

class Tab : public QWidget{

    Q_OBJECT
public:
    Tab(QWidget *parent = nullptr);


private:
    QTabWidget* maintab;
    Calculator* calpage;
    Todolist* todopage;
    Notepad* textpage;

    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
};
