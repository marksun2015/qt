#TEMPLATE = currentymodel 
QT += core gui network opengl qml quick svg xml widgets
QT += widgets

LIBS += -lsqlite3 
LIBS += -lcurl
LIBS += -ldl

HEADERS += ./citymodel.h
SOURCES += ./main.cpp \
		   ./citymodel.cpp
