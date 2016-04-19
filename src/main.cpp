#include <iostream>
#include <vector>
#include <SDL.h>
#include "window.h"
#include "GLFunctions.h"
#include "player.h"
#include "utilityfunctions.h"
#include "mesh.h"
#include "obstacle.h"
#include "level.h"
#include "bullet.h"

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

Uint32 Update(Uint32 _interval, void * _param)
{
	Player * mainPlayer = (Player*)_param;
	if (mainPlayer != nullptr)
	{
		mainPlayer->updateRotation();
		mainPlayer->updatePosition();
	}
	return _interval;
}


int main()
{
	int width = 800;
	int height = 600;

	Mesh asteroidMesh("models/Asteroid.obj");
	Mesh shipMesh("models/ship2.obj");
	Mesh bulletMesh("models/bullet.obj");

	Window mainWindow(width,height);
	glViewport(0,0,width,height);

	Player mainPlayer(Vec4(24,0,156,0), Vec4(0,0,0,0), 0.2f, false, 3, &shipMesh);
	Level level("map.txt", &mainPlayer, &asteroidMesh);

	//std::cout << sizeof(mainPlayer) << std::endl;

	bool quit = false;
	SDL_Event event;
	SDL_TimerID my_timer_id = SDL_AddTimer(10, Update, &mainPlayer);

	while (quit != true)
	{
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

		//if (std::abs(mainPlayer.getPosition().m_x - obstacle.getPosition().m_x) < mainPlayer.getCollisionLimitX() + obstacle.getCollisionLimitX()
		//&& std::abs(mainPlayer.getPosition().m_z - obstacle.getPosition().m_z) < mainPlayer.getCollisionLimitZ()+obstacle.getCollisionLimitZ())
			//mainPlayer.checkCollision(true);

		Vec4 p_pos = mainPlayer.getPosition();
		Vec4 p_rot = mainPlayer.getRotation();

		//p_rot[0] -= 90;
		GLFunctions::lookAt(Vec4(p_pos[0],20*(mainWindow.getWidth()/mainWindow.getHeight()),p_pos[2]+0.1f, 1),Vec4(p_pos[0],0,p_pos[2]),Vec4(0,1,0));
		//GLFunctions::lookAt(Vec4(p_pos[0] + std::cos((p_rot[0] * M_PI)/180), 0.8f, p_pos[2] - std::sin((p_rot[0]* M_PI)/180), 1),Vec4(p_pos[0] ,0.5f,p_pos[2]),Vec4(0,1,0));
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		level.wallCollision(&mainPlayer);
		mainPlayer.draw();
		level.draw();

		SDL_GL_SwapWindow(mainWindow.getWindow());
	}

	return 0;
}
