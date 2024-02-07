#include <SDL.h>
#include <stdio.h>
#include "Game.h"

Game* game = nullptr;

int main(int argc, char* args[]) {

	// Create and initialize game to be displayed
	game = new Game();
	game->Init("CryptLocal", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (Game::isRunning) {
		game->HandleEvents();
		game->Update();
		game->Render();
	}

	game->Clean();

	return 0;
}