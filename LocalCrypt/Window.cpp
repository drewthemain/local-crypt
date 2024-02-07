#include "Window.h"

SDL_Window* Window::window = nullptr;
SDL_Renderer* Window::renderer = nullptr;

Window::Window() {
}

Window::~Window() {
}

bool Window::Init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen) {
	int flags = fullScreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0;
	window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

	if (window) {
		Debug::Log("Window created!");

		renderer = SDL_CreateRenderer(window, -1, 0);
		SDL_RenderSetLogicalSize(renderer, width, height);

		if (renderer) {
			// Set renderer to white
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			Debug::Log("Renderer created!");

			return true;
		}
	}

	return false;
}

/// <summary>
/// Destroys and cleans remaining SDL references
/// </summary>
void Window::Clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	window = nullptr;
	renderer = nullptr;
}

/// <summary>
/// Getter for the game windows width
/// </summary>
/// <returns>Game width as a float</returns>
float Window::GetWindowWidth() {
	return SDL_GetWindowSurface(window)->w;
}

/// <summary>
/// Getter for the game windows height
/// </summary>
/// <returns>Game height as a float</returns>
float Window::GetWindowHeight() {
	return SDL_GetWindowSurface(window)->h;
}