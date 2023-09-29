QT += widgets

HEADERS       = button.h \
                calculator.h \
                notepad.h \
                tab.h
SOURCES       = button.cpp \
                calculator.cpp \
                main.cpp \
                notepad.cpp \
                tab.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/calculator
INSTALLS += target

FORMS += \
    notepad.ui

DISTFILES += \
    images/bold.png \
    images/copy.png \
    images/create.png \
    images/cut.png \
    images/edit_redo.png \
    images/edit_undo.png \
    images/exit.png \
    images/font.png \
    images/info.png \
    images/italic.png \
    images/new.png \
    images/open.png \
    images/paste.png \
    images/pencil.png \
    images/print.png \
    images/save.png \
    images/save_as.png \
    images/underline.png

RESOURCES += \
    notpad.qrc
