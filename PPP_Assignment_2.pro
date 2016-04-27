TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
isEqual(QT_MAJOR_VERSION, 5) {cache() }
QT += core

INCLUDEPATH += $$PWD/include/
#INCLUDEPATH += $$PWD/mesh/

SOURCES += \
		src/main.cpp \
		src/Window.cpp \
		src/GameObject.cpp \
		src/Player.cpp \
		src/UtilityfFunctions.cpp \
		src/Mesh.cpp \
		src/Obstacle.cpp \
		src/Level.cpp \
    		src/Bullet.cpp \
    		src/Enemy.cpp \
    		src/EnemySatellite.cpp

CONFIG+=opengl
# turn on c++11
CONFIG+=c++11

HEADERS += \
		include/Window.h \
		include/GameObject.h \
		include/Player.h \
		include/UtilityFunctions.h \
		include/Mesh.h \
		include/Obstacle.h \
		include/Level.h \
		include/Bullet.h \
		include/Enemy.h \
		include/EnemySatellite.h




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

linux-g++:linux-g++-64:LIBS+= -lGLU
linux-clang : LIBS+= -lGLU

