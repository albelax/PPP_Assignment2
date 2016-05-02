#include <iostream>
#include <vector>
#include <SDL.h>
#include "Window.h"
#include "GLFunctions.h"
#include "Player.h"
#include "UtilityFunctions.h"
#include "Mesh.h"
#include "Obstacle.h"
#include "Level.h"
#include "Bullet.h"

#ifdef __APPLE__
	#include <OpenGL/gl.h>
	#include <OpenGL/glu.h>
#else
	#include <GL/gl.h>
	#include <GL/glu.h>
#endif

Uint32 Update(Uint32 _interval, void * _param)
{
	// the update function calls the update of the level based on a timer
	// the level will take care of updating all other objects
  Level * level = (Level*)_param;
  if (level != nullptr)
  {
		level->update();

  }
	return _interval;
}

Uint32 ActivateBullets(Uint32 _interval, void * _param)
{
	// lets enemy and players shoot
  Level * level = (Level*)_param;
  if (level != nullptr)
  {
		level->getPlayer()->canShoot(true);
    level->enemyCanShoot();
  }
  return _interval;
}

Uint32 DeactivateParticles(Uint32 _interval, void * _param)
{
	Level * level = (Level*)_param;
	if (level != nullptr)
	{
		if (level->getParticles() != nullptr)
		{
			level->getParticles()->deactivateParticles();
		}
	}
	return _interval;
}

int main()
{
	int width = 800;
	int height = 600;
	int cellSize = 11;
  std::vector<Mesh*> meshes;
	Mesh shipMesh("models/car.obj", "ship");
  meshes.push_back(&shipMesh);
  Mesh asteroidMesh("models/Asteroid.obj", "obstacle");
  meshes.push_back(&asteroidMesh);
  Mesh bulletMesh("models/bullet.obj", "bullet");
  meshes.push_back(&bulletMesh);

	Player mainPlayer(Vec4(cellSize*4,0,cellSize*27,0), Vec4(0,0,0,0), 0.3f, true, 20, &shipMesh);
	Level level("map.txt", &mainPlayer, meshes, cellSize);

	bool quit = false;
	SDL_Event event;

	Window mainWindow(width,height);
	glViewport(0,0,width,height);

	SDL_TimerID update = SDL_AddTimer(10, Update, &level);
	SDL_TimerID activateBullets = SDL_AddTimer(250, ActivateBullets, &level);
	SDL_TimerID deactivateParticles = SDL_AddTimer(10000, DeactivateParticles, &level);

	while (quit != true)
	{
		while(SDL_PollEvent(&event))
		{
      if (event.type == SDL_QUIT)
      {
        quit = true;
        SDL_RemoveTimer(update);
        SDL_RemoveTimer(activateBullets);
				SDL_RemoveTimer(deactivateParticles);
      }
			else if (event.type == SDL_WINDOWEVENT)
			{
				SDL_GetWindowSize(mainWindow.getWindow(), &width, &height);
				mainWindow.setWindowSize(width, height);
			}
			mainPlayer.input(event);
		}

		Vec4 p_pos = mainPlayer.getPosition();
		Vec4 p_rot = mainPlayer.getRotation();

    p_rot[0] -= 90;
		GLFunctions::lookAt(Vec4(p_pos[0],35*(mainWindow.getWidth()/mainWindow.getHeight()),p_pos[2]+0.1f, 1),Vec4(p_pos[0],0,p_pos[2]),Vec4(0,1,0));
		//GLFunctions::lookAt(Vec4(p_pos[0] + std::cos((p_rot[0] * M_PI)/180), 0.8f, p_pos[2] - std::sin((p_rot[0]* M_PI)/180), 1),Vec4(p_pos[0],0.5f,p_pos[2]),Vec4(0,1,0));

		glClearColor(0.5f, 0.5f, 0.5f, 1);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		level.draw();

		SDL_GL_SwapWindow(mainWindow.getWindow());
    glFinish();
	}
	return 0;
}
