QT       += core

QT       -= gui

TARGET = Sobolev
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv2/
LIBS += -lopencv_imgproc -L/usr/local/lib/
LIBS += -lopencv_highgui -L/usr/local/lib/
LIBS += -lopencv_ml -L/usr/local/lib/
LIBS += -lopencv_video -L/usr/local/lib/
LIBS += -lopencv_features2d -L/usr/local/lib/
LIBS += -lopencv_calib3d -L/usr/local/lib/
LIBS += -lopencv_objdetect  -L/usr/local/lib/
LIBS += -lopencv_flann -L/usr/local/lib/

SOURCES += main.cpp

DISTFILES += \
    CMakeLists.txt
