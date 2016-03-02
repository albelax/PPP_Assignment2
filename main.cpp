#include <iostream>
#include <SDL.h>
#include "window.h"
#include "GLFunctions.h"
#include "player.h"

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif


int main()
{
	int width = 800;
	int height = 600;
	Window mainWindow(width,height);
	glViewport(0,0,width,height);

	Player mainPlayer(Vec4(0,0,0,0), Vec4(0,0,0,0),0.1,true,3);

	bool quit = false;
	while (quit != true)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				quit = true;
			else if (event.type == SDL_WINDOWEVENT)
			{
				SDL_GetWindowSize(mainWindow.getWindow(), &width, &height);
				mainWindow.setWindowSize(width, height);
			}
			mainPlayer.input(event);
		}
		mainPlayer.updateRotation();

		mainPlayer.updatePosition();

		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		mainPlayer.draw();
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
