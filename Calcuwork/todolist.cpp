/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include "todolist.h"
#include <QTimer>
#include <QDateTime>
ToDoList::ToDoList(QWidget *parent)
    : QWidget(parent)
{
    QLabel *dueLabel = new QLabel(tr("今天你有几个due:"));
    dueLine = new QLineEdit;
    dueLine->setReadOnly(true);

    QLabel *affairsLabel = new QLabel(tr("速速拿下:\n注意时间哦，\n摆烂千万条，\n绩点第一条(笑死，fw一个)，\n摸鱼不规范，\n队友两行泪。"));
    affairsText = new QTextEdit;
    affairsText->setReadOnly(true);

    addButton = new QPushButton(tr("&Add"));
//! [edit and remove buttons]
    editButton = new QPushButton(tr("&Edit"));
    editButton->setEnabled(false);
    removeButton = new QPushButton(tr("&Remove"));
    removeButton->setEnabled(false);
//! [edit and remove buttons]
    submitButton = new QPushButton(tr("&Submit"));
    submitButton->hide();
    cancelButton = new QPushButton(tr("&Cancel"));
    cancelButton->hide();

    nextButton = new QPushButton(tr("&Next"));
    nextButton->setEnabled(false);
    previousButton = new QPushButton(tr("&Previous"));
    previousButton->setEnabled(false);

    connect(addButton, &QPushButton::clicked,
            this, &ToDoList::addContact);
    connect(submitButton, &QPushButton::clicked,
            this, &ToDoList::submitContact);
//! [connecting edit and remove]
    connect(editButton, &QPushButton::clicked,
            this, &ToDoList::editContact);
    connect(removeButton, &QPushButton::clicked,
            this, &ToDoList::removeContact);
//! [connecting edit and remove]
    connect(cancelButton, &QPushButton::clicked,
            this, &ToDoList::cancel);
    connect(nextButton, &QPushButton::clicked,
            this, &ToDoList::next);
    connect(previousButton, &QPushButton::clicked,
            this, &ToDoList::previous);

    QVBoxLayout *buttonLayout1 = new QVBoxLayout;
    buttonLayout1->addWidget(addButton);
//! [adding edit and remove to the layout]
    buttonLayout1->addWidget(editButton);
    buttonLayout1->addWidget(removeButton);
//! [adding edit and remove to the layout]
    buttonLayout1->addWidget(submitButton);
    buttonLayout1->addWidget(cancelButton);
    buttonLayout1->addStretch();

    QHBoxLayout *buttonLayout2 = new QHBoxLayout;
    buttonLayout2->addWidget(previousButton);
    buttonLayout2->addWidget(nextButton);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(dueLabel, 0, 0);
    mainLayout->addWidget(dueLine, 0, 1);
    mainLayout->addWidget(affairsLabel, 1, 0,Qt::AlignTop);
    mainLayout->addWidget(affairsText, 1, 1);
    mainLayout->addLayout(buttonLayout1, 1, 2);
    mainLayout->addLayout(buttonLayout2, 2, 1);
//! [adding time to the layout]

    QLabel *timeLabel = new QLabel{this};

    QTimer *timer = new QTimer(this);
    timer->start(1000);
    QDateTime datetime = QDateTime::currentDateTime();
    timeLabel->setText(datetime.toString("t yyyy-MM-dd hh:mm:ss a dddd"));

    connect(timer, &QTimer::timeout, this, [=]() {
        QDateTime datetime = QDateTime::currentDateTime();
        timeLabel->setText(datetime.toString("t yyyy-MM-dd hh:mm:ss a dddd"));
    });
    mainLayout->addWidget(timeLabel, 2, 0);

//版权声明：显示时间的函数为CSDN博主「❀云坠入雾里」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https://blog.csdn.net/qq_63884259/article/details/130276713
    setLayout(mainLayout);
    setWindowTitle(tr("To Do List"));
}

void ToDoList::addContact()
{
    oldDue = dueLine->text();
    oldAffairs = affairsText->toPlainText();

    dueLine->clear();
    affairsText->clear();

    updateInterface(AddingMode);
}
//! [editContact() function]
void ToDoList::editContact()
{
    oldDue = dueLine->text();
    oldAffairs = affairsText->toPlainText();

    updateInterface(EditingMode);
}
//! [editContact() function]
//! [submitContact() function beginning]
void ToDoList::submitContact()
{
//! [submitContact() function beginning]
    QString due = dueLine->text();
    QString affairs = affairsText->toPlainText();

    if (due.isEmpty() || affairs.isEmpty()) {
        QMessageBox::information(this, tr("Empty Field"),
            tr("你到底要干嘛，能不能好好搞！"));
        return;
    }
//! [submitContact() function part1]
    if (currentMode == AddingMode) {

        if (!contacts.contains(affairs)) {
            contacts.insert(affairs,due);
            QMessageBox::information(this, tr("Add Successful"),
                tr("\"%1\" 已经给你加到To-Do-List里面了。").arg(affairs));
        } else {
            QMessageBox::information(this, tr("Add Unsuccessful"),
                tr("6, \"%1\" 已经在To-Do-List里面了，别搁这儿浪费时间了！").arg(affairs));
        }
//! [submitContact() function part1]
//! [submitContact() function part2]
    } else if (currentMode == EditingMode) {

        if (oldAffairs != affairs) {
            if (!contacts.contains(affairs)) {
                QMessageBox::information(this, tr("Edit Successful"),
                    tr("\"%1\" 已经更新了当前事务，继续加油。").arg(oldAffairs));
                contacts.remove(oldAffairs);
                contacts.insert(affairs,due);
            } else {
                QMessageBox::information(this, tr("Edit Unsuccessful"),
                    tr("6, \"%1\"已经在To-Do-List里面了，别搁这儿浪费时间了！").arg(affairs));
            }
        } else if (oldDue != due) {
            QMessageBox::information(this, tr("Edit Successful"),
                tr("\"%1\" 已经更新了截止时间，继续加油。").arg(affairs));
            contacts[affairs] = due;
        }
    }

    updateInterface(NavigationMode);
}
//! [submitContact() function part2]

void ToDoList::cancel()
{
    dueLine->setText(oldDue);
    affairsText->setText(oldAffairs);
    updateInterface(NavigationMode);
}
//! [removeContact() function]
void ToDoList::removeContact()
{
    QString due = dueLine->text();
    QString affairs = affairsText->toPlainText();

    if (contacts.contains(affairs)) {

        int button = QMessageBox::question(this,
            tr("Confirm Remove"),
            tr("你确定要删掉\"%1\"?").arg(affairs),
            QMessageBox::Yes | QMessageBox::No);

        if (button == QMessageBox::Yes) {

            previous();
            contacts.remove(affairs);

            QMessageBox::information(this, tr("Remove Successful"),
                tr("\"%1\" 已经从To-Do-List中删掉了。这下你高兴了吧，你这个冷漠无情的人！").arg(affairs));
        }
    }

    updateInterface(NavigationMode);
}
//! [removeContact() function]
void ToDoList::next()
{
    QString affairs = affairsText->toPlainText();
    QMap<QString, QString>::iterator i = contacts.find(affairs);

    if (i != contacts.end())
        i++;

    if (i == contacts.end())
        i = contacts.begin();

    affairsText->setText(i.key());
    dueLine->setText(i.value());
}

void ToDoList::previous()
{
    QString affairs = affairsText->toPlainText();
    QMap<QString, QString>::iterator i = contacts.find(affairs);

    if (i == contacts.end()) {
        dueLine->clear();
        affairsText->clear();
        return;
    }

    if (i == contacts.begin())
        i = contacts.end();

    i--;
    affairsText->setText(i.key());
    dueLine->setText(i.value());
}
//! [update interface() part 1]
void ToDoList::updateInterface(Mode mode)
{
    currentMode = mode;

    switch (currentMode) {

    case AddingMode:
    case EditingMode:

        dueLine->setReadOnly(false);
        affairsText->setFocus(Qt::OtherFocusReason);
        affairsText->setReadOnly(false);

        addButton->setEnabled(false);
        editButton->setEnabled(false);
        removeButton->setEnabled(false);

        nextButton->setEnabled(false);
        previousButton->setEnabled(false);

        submitButton->show();
        cancelButton->show();
        break;
//! [update interface() part 1]
//! [update interface() part 2]
    case NavigationMode:

        if (contacts.isEmpty()) {
            dueLine->clear();
            affairsText->clear();
        }

        dueLine->setReadOnly(true);
        affairsText->setReadOnly(true);
        addButton->setEnabled(true);

        int number = contacts.size();
        editButton->setEnabled(number >= 1);
        removeButton->setEnabled(number >= 1);
        nextButton->setEnabled(number > 1);
        previousButton->setEnabled(number >1 );

        submitButton->hide();
        cancelButton->hide();
        break;
    }
}
//! [update interface() part 2]
