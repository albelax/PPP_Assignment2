#include <iostream>
#include <SDL.h>
#include "window.h"
#include "GLFunctions.h"

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif


int main()
{
	float PosX = 0;
	float PosZ = 0;

	int width = 800;
	int height = 600;
	Window mainWindow(width,height);
	glViewport(0,0,width,height);

	bool quit = false;
	while (quit != true)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				quit = true;

			if (event.type == SDL_KEYDOWN)
			{
				switch (event.key.keysym.sym)
				{
					case SDLK_ESCAPE : quit = 1; break;
					case SDLK_LEFT : PosX -= 0.1f; break;
					case SDLK_RIGHT : PosX += 0.1f; break;
					case SDLK_UP : PosZ -= 0.1f; break;
					case SDLK_DOWN : PosZ += 0.1f; break;
					default: break;
				}
			}

			else if (event.type == SDL_WINDOWEVENT)
			{
				SDL_GetWindowSize(mainWindow.getWindow(), &width, &height);
				mainWindow.setWindowSize(width, height);
			}
		}


		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3f(0.21, 0.254, 0.258);

		glPushMatrix();
			glTranslatef(PosX,0,PosZ);
			glRotatef(-PosX*200,0,1,0);
			GLFunctions::cube(0.5,0.5,0.5);
		glPopMatrix();


		for (int i=0; i <= 2; ++i)
		{
				for (int j = 0; j <=2; ++j)
				{
					glColor3f(1,0,0);
					glPushMatrix();
						glTranslatef(-2 + j*2, 1, -2 + i*2);
						GLFunctions::cube(0.5,2,0.5);
					glPopMatrix();
				}
		}
		SDL_GL_SwapWindow(mainWindow.getWindow());
	}
	return 0;
}
