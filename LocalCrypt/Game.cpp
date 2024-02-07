#include <string>
#include "Game.h"

SDL_Event Game::event;
bool Game::isRunning = false;

Game::Game()
{
}

Game::~Game()
{
}

void Game::Init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		Debug::Log("Subsystems initialized!");

		window = new Window();

		if (window->Init(title, xPos, yPos, width, height, fullScreen))
		{
			isRunning = true;
		}
	}
}

/// <summary>
/// Handles user input
/// Will be delegated later to external controllers
/// </summary>
void Game::HandleEvents()
{
	SDL_PollEvent(&event);

	if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
			case SDLK_ESCAPE:
				isRunning = false;
				break;
		}
	}

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

void Game::Update()
{
	// TODO: UPDATE
}

void Game::Render()
{
	// TODO: RENDER
}

/// <summary>
/// Scrubs the window and properly exits SDL
/// </summary>
void Game::Clean()
{
	window->Clean();
	SDL_Quit();

	Debug::Log("Game cleaned!");
}
