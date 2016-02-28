#ifndef WINDOW_H
#define WINDOW_H

#include <stdio.h>
#include <iostream>
#include <SDL.h>
#include <GLFunctions.h>
#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

class Window
{
private:
	int m_width;
	int m_height;
	SDL_Window * m_window;
	SDL_Renderer * m_renderer;
	SDL_GLContext m_context;
	SDL_GLContext createContext();
	void glInit();
public:
	Window(const int _width, const int _height);
	const int getWidth(){ return this -> m_width;}
	const int getHeight(){ return this -> m_height;}
	void setWindowSize(const int &_width, const int &_height);
	SDL_Window * const getWindow(){ return m_window;}
	SDL_Renderer * const getRenderer() { return m_renderer;}
};
#endif // WINDOW_H
