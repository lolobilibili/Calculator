# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.16)
project(calculator LANGUAGES CXX)

if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()

set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/widgets/widgets/calculator")

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_standard_project_setup()

qt_add_executable(calculator
    button.cpp button.h
    calculator.cpp calculator.h
    main.cpp
)

set_target_properties(calculator PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(calculator PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

install(TARGETS calculator
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)

set(notepad_resource_files
    "images/bold.png"
    "images/copy.png"
    "images/create.png"
    "images/cut.png"
    "images/edit_redo.png"
    "images/edit_undo.png"
    "images/exit.png"
    "images/font.png"
    "images/info.png"
    "images/italic.png"
    "images/new.png"
    "images/open.png"
    "images/paste.png"
    "images/pencil.png"
    "images/print.png"
    "images/save.png"
    "images/save_as.png"
    "images/underline.png"
)
