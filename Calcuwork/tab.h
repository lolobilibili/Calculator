#ifndef TAB_H
#define TAB_H

#endif // TAB_H
#include <QTabWidget>
#include "calculator.h"

class Tab : public QWidget{

    Q_OBJECT
public:
    Tab(QWidget *parent = nullptr);


private:
    QTabWidget* maintab;
    Calculator* calpage;

    // QWidget interface
protected:
    virtual void resizeEvent(QResizeEvent *event) override;
};
