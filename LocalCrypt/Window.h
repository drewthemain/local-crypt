#pragma once

#include <SDL.h>
#include "Debug.h"

class Window {
public:
	// Reference to the game window
	static SDL_Window* window;

	// Reference to the games renderer
	static SDL_Renderer* renderer;

	Window();
	~Window();

	static float GetWindowWidth();
	static float GetWindowHeight();

	bool Init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);

	void Clean();
};

