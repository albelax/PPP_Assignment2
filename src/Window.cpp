#include "Window.h"

Window::Window(const int _width, const int _height)
{
	m_width = _width;
	m_height = _height;
	SDL_Init(SDL_INIT_TIMER);
	m_window = SDL_CreateWindow("pippo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_width, m_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
	if (m_window == 0)
	{
		printf("%s\n",SDL_GetError());
	}

//	this ->m_renderer = SDL_CreateRenderer(m_window, 0, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
//	if (m_renderer == 0)
//	{
//		m_renderer = SDL_GetRenderer(m_window);
//		printf("%s\n",SDL_GetError());
//	}

	m_context = SDL_GL_CreateContext(m_window);
	glInit();
}

//----------------------------------------------------------------------------------------------------------------------

void Window::setWindowSize(const int &_width, const int &_height)
{
	m_width = _width;
	m_height = _height;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  gluPerspective(60.0f, float(m_width) / float(m_height), 0.1f, 100.0f);

  glViewport(0,0,m_width,m_height);
	glMatrixMode(GL_MODELVIEW);
}

//----------------------------------------------------------------------------------------------------------------------

SDL_GLContext Window::createContext()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);
	SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	return SDL_GL_CreateContext(m_window);
}

//----------------------------------------------------------------------------------------------------------------------

void Window::glInit()
{
	/*
	 * init is needed to initialize openGL,
	 * glMatrixMode dpecifies which matrix will be affected
	 * glLoadIdentity initializes the current matrix to an identity
	 * glOrtho lets me set the new coordinate system
	 */

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0,0,m_width,m_height);

  gluPerspective(60.0f, float(m_width) / float(m_height), 0.1f, 100.0f); // 10 if topdown
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glColor3f(1,1,0);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glMatrixMode(GL_MODELVIEW);
  glEnable (GL_BLEND);
  glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

//----------------------------------------------------------------------------------------------------------------------
