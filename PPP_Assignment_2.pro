TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
isEqual(QT_MAJOR_VERSION, 5) {cache() }
QT += core

INCLUDEPATH += $$PWD/include/
#INCLUDEPATH += $$PWD/mesh/

SOURCES += src/main.cpp \
		src/window.cpp \
		src/gameobject.cpp \
		src/player.cpp \
		src/utilityfunctions.cpp \
		src/mesh.cpp \
		src/obstacle.cpp \
		src/level.cpp \
    src/bullet.cpp

CONFIG+=opengl
# turn on c++11
CONFIG+=c++11

HEADERS += \
		include/window.h \
		include/gameobject.h \
		include/player.h \
		include/utilityfunctions.h \
		include/mesh.h \
		include/obstacle.h \
		include/level.h \
		include/bullet.h




macx:LIBS += -F/Library/Frameworks -framework SDL2
macx:INCLUDEPATH += /Library/Frameworks/SDL.framework/Headers
macx:INCLUDEPATH += /usr/local/include/SDL2

QMAKE_CXXFLAGS+= -msse -msse2 -msse3
macx:QMAKE_CXXFLAGS+= -arch x86_64

INCLUDEPATH +=$$PWD/include
INCLUDEPATH += $$PWD/GLFunctionsLib/include
LIBS+= -L $$PWD/GLFunctionsLib/lib -lGLFunctionsLib


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
