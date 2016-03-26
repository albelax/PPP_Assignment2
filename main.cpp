#include <iostream>
#include <vector>
#include <SDL.h>
#include "window.h"
#include "GLFunctions.h"
#include "player.h"
#include "utilityfunctions.h"
#include "mesh.h"

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

	Player mainPlayer(Vec4(0,0,0,0), Vec4(0,0,0,0), 0.1, true, 3);

	std::vector<char> v = utilityFunctions::generateObstacles(10,10);

	Mesh asteroid("Asteroid.obj");
	//Mesh car("car.obj");
	Mesh ship("ship.obj");


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

		Vec4 p_pos = mainPlayer.getPosition();
		Vec4 p_rot = mainPlayer.getRotation();
		p_rot[0] -= 90;

		GLFunctions::lookAt(Vec4(p_pos[0],10*(mainWindow.getWidth()/mainWindow.getHeight()),p_pos[2]+0.1f, 1),Vec4(p_pos[0],0,p_pos[2]),Vec4(0,1,0));
		//GLFunctions::lookAt(Vec4(p_pos[0] + std::cos((p_rot[0] * M_PI)/180), 0.5f, p_pos[2] - std::sin((p_rot[0]* M_PI)/180), 1),Vec4(p_pos[0] ,0.5f,p_pos[2]),Vec4(0,1,0));

		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		mainPlayer.draw();
		float x = 0;
		float z = 0;
		for (int i = 0; i < 25; ++i)
		{
			if ( i % 5 == 0)
			{
				z += 2;
				x = 0;
			}
			glColor3f(1, 0, 0);
			glPushMatrix();
			glTranslatef(-10 + x*2, 0, -10+ z*2);
				asteroid.draw(2);
			glPopMatrix();

			x += 2;
		}
		//utilityFunctions::DrawLevel(v, 10);

		//car.draw(0.5f);
		SDL_GL_SwapWindow(mainWindow.getWindow());
	}

	return 0;
}
