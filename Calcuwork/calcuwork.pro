QT += widgets

HEADERS       = button.h \
                calculator.h \
                tab.h
SOURCES       = button.cpp \
                calculator.cpp \
                main.cpp \
                tab.cpp

# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/widgets/calculator
INSTALLS += target

FORMS +=
