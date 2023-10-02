// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include <QApplication>

#include "tab.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Tab tabpage;
    tabpage.show();
    return app.exec();
}
