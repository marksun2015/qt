#TEMPLATE = currentymodel 
QT += core gui network opengl qml quick svg xml widgets
QT += widgets

LIBS += -lsqlite3 
LIBS += -lcurl
LIBS += -ldl

HEADERS += ./currencymodel.h
SOURCES += ./main.cpp \
			./currencymodel.cpp
