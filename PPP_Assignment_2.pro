TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
isEqual(QT_MAJOR_VERSION, 5) {cache() }
QT += core

SOURCES += main.cpp \
    window.cpp \
    gameobject.cpp \
    player.cpp

#INCLUDEPATH += /Library/Frameworks/SDL2_image.framework/Headers
#INCLUDEPATH += /Library/Frameworks/

CONFIG+=opengl
# turn on c++11
CONFIG+=c++11

HEADERS += \
		window.h \
    gameobject.h \
    player.h

INCLUDEPATH += $$PWD/include

QMAKE_CXXFLAGS+= -msse -msse2 -msse3
macx:QMAKE_CXXFLAGS+= -arch x86_64

LIBS += -F/Library/Frameworks -framework SDL2
INCLUDEPATH += /Library/Frameworks/SDL.framework/Headers
INCLUDEPATH += /usr/local/include/SDL2

INCLUDEPATH += GLFunctionsLib/include
LIBS+= -L GLFunctionsLib/lib -lGLFunctionsLib

QMAKE_CXXFLAGS += $$system(sdl2-config --cflags)
LIBS += $$system(sdl2-config --libs)

LIBS += -L/usr/local/lib

macx:LIBS+= -framework OpenGL

# now if we are under unix and not on a Mac (i.e. linux) define GLEW
linux-g++:linux-g++-64
{
		LIBS+= -lGLEW
}
linux-clang
{
		LIBS+= -lGLEW
}
