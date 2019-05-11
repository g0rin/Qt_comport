QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qt_comport
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS

CONFIG += c++11

FORMS += main_window_form.ui \
	 command_form.ui \
	 crc_form.ui

HEADERS += 	mainwindow.h \
                command_form.h \
                crc_form.h

SOURCES += 	main.cpp \
    command_form.cpp \
		crc_form.cpp \
                mainwindow.cpp

RESOURCES     = resources.grc

win32-msvc*:{
RC_FILE = Qt_comport.rc
}


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
