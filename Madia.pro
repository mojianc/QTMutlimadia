#-------------------------------------------------
#
# Project created by QtCreator 2019-05-28T21:38:12
#
#-------------------------------------------------

QT       += core gui
QT       += core gui
#QT       += multimedia
#QT       += multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = Madia
TEMPLATE = app

#QTPLUGIN     += dsengine


INCLUDEPATH += E:\Qt5.11.2\Qt-msvc2015-x64-static\include
INCLUDEPATH += E:\Qt5.11.2\Qt-msvc2015-x64-static\include\QtMultimedia
INCLUDEPATH += E:\Qt5.11.2\Qt-msvc2015-x64-static\include\QtMultimediaWidgets

LIBS += E:\Qt5.11.2\Qt-msvc2015-x64-static\lib\Qt5Multimedia.lib
LIBS += E:\Qt5.11.2\Qt-msvc2015-x64-static\lib\Qt5MultimediaWidgets.lib
LIBS += -LE:\Qt5.11.2\Qt-msvc2015-x64-static\lib

LIBS += -LE:\Qt5.11.2\Qt-msvc2015-x64-static\plugins\mediaservice
LIBS += -lQt5Network -lQt5OpenGL  -ldsengine
#Qt5AccessibilitySupportd -lqtpcre2d -lqtmaind -lqwindowsd -lQt5PlatformCompositorSupportd -lQt5EventDispatcherSupportd -lQt5FontDatabaseSupportd -lQt5ThemeSupportd -lQt5WindowsUIAutomationSupportd
SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h
