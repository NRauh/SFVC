#-------------------------------------------------
#
# Project created by QtCreator 2014-09-29T22:55:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SFVC
TEMPLATE = app

SOURCES += main.cpp\
		mainwindow.cpp \
	ffmpegwrapper.cpp \
    errordialog.cpp

HEADERS  += mainwindow.h \
	ffmpegwrapper.h \
    errordialog.h

FORMS    += mainwindow.ui \
    errordialog.ui

QMAKE_CXXFLAGS+=-v

OTHER_FILES += \
	LICENSE.md \
	README.md
