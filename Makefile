#############################################################################
# Makefile for building: PPP_Assignment_2
# Generated by qmake (3.1) (Qt 5.9.1)
# Project:  PPP_Assignment_2.pro
# Template: app
# Command: /home/alberto/Qt/5.9.1/gcc_64/bin/qmake -o Makefile PPP_Assignment_2.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_QML_DEBUG
CFLAGS        = -pipe -g -Wall -W -fPIC $(DEFINES)
CXXFLAGS      = -pipe -msse -msse2 -msse3 -I/usr/local/include/SDL2 -I/usr/include -D_REENTRANT -g -std=gnu++11 -Wall -W -fPIC $(DEFINES)
INCPATH       = -I. -Iinclude -Iinclude -IGLFunctionsLib/include -isystem /usr/include/libdrm -I/home/alberto/Qt/5.9.1/gcc_64/mkspecs/linux-g++
QMAKE         = /home/alberto/Qt/5.9.1/gcc_64/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /home/alberto/Qt/5.9.1/gcc_64/bin/qmake -install qinstall
QINSTALL_PROGRAM = /home/alberto/Qt/5.9.1/gcc_64/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = PPP_Assignment_21.0.0
DISTDIR = /home/alberto/PPP_Assignment2/obj/PPP_Assignment_21.0.0
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS) -L /home/alberto/PPP_Assignment2/GLFunctionsLib/lib -lGLFunctionsLib -L/usr/local/lib -Wl,-rpath,/usr/local/lib -Wl,--enable-new-dtags -pthread -lSDL2 -lGLU -lGLEW -lGL 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = obj/

####### Files

SOURCES       = src/main.cpp \
		src/Window.cpp \
		src/GameObject.cpp \
		src/Player.cpp \
		src/UtilityFunctions.cpp \
		src/Mesh.cpp \
		src/Obstacle.cpp \
		src/Level.cpp \
		src/Bullet.cpp \
		src/Enemy.cpp \
		src/Enemysatellite.cpp \
		src/Particles.cpp \
		src/Particle.cpp 
OBJECTS       = obj/main.o \
		obj/Window.o \
		obj/GameObject.o \
		obj/Player.o \
		obj/UtilityFunctions.o \
		obj/Mesh.o \
		obj/Obstacle.o \
		obj/Level.o \
		obj/Bullet.o \
		obj/Enemy.o \
		obj/Enemysatellite.o \
		obj/Particles.o \
		obj/Particle.o
DIST          = .qmake.stash \
		PPP_Assignment_2.pro include/Window.h \
		include/GameObject.h \
		include/Player.h \
		include/UtilityFunctions.h \
		include/Mesh.h \
		include/Obstacle.h \
		include/Level.h \
		include/Bullet.h \
		include/Enemy.h \
		include/EnemySatellite.h \
		include/Particles.h \
		include/Particle.h src/main.cpp \
		src/Window.cpp \
		src/GameObject.cpp \
		src/Player.cpp \
		src/UtilityFunctions.cpp \
		src/Mesh.cpp \
		src/Obstacle.cpp \
		src/Level.cpp \
		src/Bullet.cpp \
		src/Enemy.cpp \
		src/Enemysatellite.cpp \
		src/Particles.cpp \
		src/Particle.cpp
QMAKE_TARGET  = PPP_Assignment_2
DESTDIR       = 
TARGET        = PPP_Assignment_2


first: all
####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: PPP_Assignment_2.pro .qmake.cache /home/alberto/Qt/5.9.1/gcc_64/mkspecs/linux-g++/qmake.conf /home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/spec_pre.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/common/unix.conf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/common/linux.conf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/common/sanitize.conf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/common/gcc-base.conf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/common/gcc-base-unix.conf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/common/g++-base.conf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/common/g++-unix.conf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/qconfig.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3danimation.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3danimation_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dcore.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dcore_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dextras.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dextras_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dinput.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dinput_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dlogic.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dlogic_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquick.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquick_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickanimation.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickanimation_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickextras.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickextras_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickinput.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickinput_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickrender.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickrender_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickscene2d.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickscene2d_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3drender.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3drender_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_charts.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_charts_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_concurrent.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_core.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_core_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_datavisualization.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_datavisualization_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_dbus.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_designer.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_designer_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_egl_support_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_fb_support_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_gamepad.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_gamepad_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_glx_support_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_gui.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_gui_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_help.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_help_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_input_support_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_kms_support_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_location.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_location_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_multimedia.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_network.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_network_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_networkauth.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_networkauth_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_nfc.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_opengl.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_positioning.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_printsupport.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_purchasing.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_purchasing_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_qml.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_qml_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_qmldebug_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_qmltest.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quick.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quick_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quickcontrols2.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_remoteobjects.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_remoteobjects_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_repparser.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_repparser_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_script.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_script_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_scripttools.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_scxml.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_scxml_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_sensors.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_serialbus.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_serialbus_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_serialport.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_service_support_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_sql.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_sql_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_svg.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_svg_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_testlib.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_texttospeech.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_texttospeech_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_theme_support_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_uiplugin.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_uitools.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webchannel.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webengine.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webengine_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webenginecore.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webenginecore_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webenginecoreheaders_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webenginewidgets.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_websockets.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webview.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webview_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_widgets.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_x11extras.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_xml.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_xml_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/qt_functions.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/qt_config.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/linux-g++/qmake.conf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/spec_post.prf \
		.qmake.cache \
		.qmake.stash \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/exclusive_builds.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/toolchain.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/default_pre.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/resolve_config.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/default_post.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/unix/opengl.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/qml_debug.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/warn_on.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/qmake_use.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/file_copies.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/testcase_targets.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/exceptions.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/yacc.prf \
		/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/lex.prf \
		PPP_Assignment_2.pro
	$(QMAKE) -o Makefile PPP_Assignment_2.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/spec_pre.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/common/unix.conf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/common/linux.conf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/common/sanitize.conf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/common/gcc-base.conf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/common/gcc-base-unix.conf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/common/g++-base.conf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/common/g++-unix.conf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/qconfig.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3danimation.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3danimation_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dcore.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dcore_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dextras.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dextras_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dinput.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dinput_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dlogic.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dlogic_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquick.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquick_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickanimation.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickanimation_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickextras.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickextras_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickinput.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickinput_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickrender.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickrender_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickscene2d.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3dquickscene2d_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3drender.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_3drender_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_bluetooth.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_bluetooth_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_bootstrap_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_charts.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_charts_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_concurrent.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_concurrent_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_core.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_core_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_datavisualization.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_datavisualization_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_dbus.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_dbus_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_designer.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_designer_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_egl_support_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_fb_support_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_gamepad.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_gamepad_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_glx_support_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_gui.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_gui_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_help.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_help_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_input_support_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_kms_support_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_location.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_location_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_multimedia.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_multimedia_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_multimediawidgets.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_network.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_network_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_networkauth.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_networkauth_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_nfc.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_nfc_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_opengl.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_opengl_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_openglextensions.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_openglextensions_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_packetprotocol_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_positioning.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_positioning_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_printsupport.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_printsupport_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_purchasing.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_purchasing_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_qml.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_qml_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_qmldebug_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_qmldevtools_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_qmltest.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_qmltest_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quick.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quick_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quickcontrols2.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quickwidgets.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_remoteobjects.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_remoteobjects_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_repparser.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_repparser_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_script.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_script_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_scripttools.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_scripttools_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_scxml.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_scxml_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_sensors.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_sensors_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_serialbus.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_serialbus_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_serialport.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_serialport_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_service_support_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_sql.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_sql_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_svg.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_svg_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_testlib.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_testlib_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_texttospeech.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_texttospeech_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_theme_support_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_uiplugin.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_uitools.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_uitools_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webchannel.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webchannel_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webengine.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webengine_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webenginecore.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webenginecore_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webenginecoreheaders_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webenginewidgets.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webenginewidgets_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_websockets.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_websockets_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webview.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_webview_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_widgets.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_widgets_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_x11extras.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_x11extras_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_xml.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_xml_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_xmlpatterns.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/qt_functions.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/qt_config.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/linux-g++/qmake.conf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/spec_post.prf:
.qmake.cache:
.qmake.stash:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/exclusive_builds.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/toolchain.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/default_pre.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/resolve_config.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/default_post.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/unix/opengl.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/qml_debug.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/warn_on.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/qmake_use.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/file_copies.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/testcase_targets.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/exceptions.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/yacc.prf:
/home/alberto/Qt/5.9.1/gcc_64/mkspecs/features/lex.prf:
PPP_Assignment_2.pro:
qmake: FORCE
	@$(QMAKE) -o Makefile PPP_Assignment_2.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

check: first

benchmark: first

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: 

####### Compile

obj/main.o: src/main.cpp include/Window.h \
		GLFunctionsLib/include/GLFunctions.h \
		GLFunctionsLib/include/Vec4.h \
		include/Player.h \
		include/GameObject.h \
		include/UtilityFunctions.h \
		include/Mesh.h \
		include/Obstacle.h \
		include/Level.h \
		include/Bullet.h \
		include/Enemy.h \
		include/EnemySatellite.h \
		include/Particles.h \
		include/Particle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/main.o src/main.cpp

obj/Window.o: src/Window.cpp include/Window.h \
		GLFunctionsLib/include/GLFunctions.h \
		GLFunctionsLib/include/Vec4.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/Window.o src/Window.cpp

obj/GameObject.o: src/GameObject.cpp include/GameObject.h \
		GLFunctionsLib/include/Vec4.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/GameObject.o src/GameObject.cpp

obj/Player.o: src/Player.cpp include/Player.h \
		include/GameObject.h \
		GLFunctionsLib/include/Vec4.h \
		GLFunctionsLib/include/GLFunctions.h \
		include/UtilityFunctions.h \
		include/Mesh.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/Player.o src/Player.cpp

obj/UtilityFunctions.o: src/UtilityFunctions.cpp include/UtilityFunctions.h \
		GLFunctionsLib/include/GLFunctions.h \
		GLFunctionsLib/include/Vec4.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/UtilityFunctions.o src/UtilityFunctions.cpp

obj/Mesh.o: src/Mesh.cpp include/Mesh.h \
		GLFunctionsLib/include/GLFunctions.h \
		GLFunctionsLib/include/Vec4.h \
		include/UtilityFunctions.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/Mesh.o src/Mesh.cpp

obj/Obstacle.o: src/Obstacle.cpp include/Obstacle.h \
		include/GameObject.h \
		GLFunctionsLib/include/Vec4.h \
		GLFunctionsLib/include/GLFunctions.h \
		include/UtilityFunctions.h \
		include/Mesh.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/Obstacle.o src/Obstacle.cpp

obj/Level.o: src/Level.cpp include/Level.h \
		GLFunctionsLib/include/GLFunctions.h \
		GLFunctionsLib/include/Vec4.h \
		include/UtilityFunctions.h \
		include/Player.h \
		include/GameObject.h \
		include/Mesh.h \
		include/Obstacle.h \
		include/Bullet.h \
		include/Enemy.h \
		include/EnemySatellite.h \
		include/Particles.h \
		include/Particle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/Level.o src/Level.cpp

obj/Bullet.o: src/Bullet.cpp include/Bullet.h \
		include/GameObject.h \
		GLFunctionsLib/include/Vec4.h \
		GLFunctionsLib/include/GLFunctions.h \
		include/UtilityFunctions.h \
		include/Mesh.h \
		include/Player.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/Bullet.o src/Bullet.cpp

obj/Enemy.o: src/Enemy.cpp include/Enemy.h \
		include/GameObject.h \
		GLFunctionsLib/include/Vec4.h \
		GLFunctionsLib/include/GLFunctions.h \
		include/UtilityFunctions.h \
		include/Mesh.h \
		include/Player.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/Enemy.o src/Enemy.cpp

obj/Enemysatellite.o: src/Enemysatellite.cpp include/EnemySatellite.h \
		include/GameObject.h \
		GLFunctionsLib/include/Vec4.h \
		GLFunctionsLib/include/GLFunctions.h \
		include/UtilityFunctions.h \
		include/Mesh.h \
		include/Player.h \
		include/Enemy.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/Enemysatellite.o src/Enemysatellite.cpp

obj/Particles.o: src/Particles.cpp include/Particles.h \
		GLFunctionsLib/include/GLFunctions.h \
		GLFunctionsLib/include/Vec4.h \
		include/Mesh.h \
		include/UtilityFunctions.h \
		include/Particle.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/Particles.o src/Particles.cpp

obj/Particle.o: src/Particle.cpp include/Particle.h \
		GLFunctionsLib/include/GLFunctions.h \
		GLFunctionsLib/include/Vec4.h \
		include/Mesh.h \
		include/UtilityFunctions.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o obj/Particle.o src/Particle.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:
