#pragma once

#include <SDL.h>
#include "Debug.h"
#include "Window.h"

class Game
{
public:

	// The main game event
	static SDL_Event event;

	// Is the game currently running?
	// Toggles out of game loop
	static bool isRunning;

	Game();

	~Game();

	void Init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);

	void HandleEvents();

	void Update();

	void Render();

	void Clean();

private:
	Window* window = nullptr;
};

