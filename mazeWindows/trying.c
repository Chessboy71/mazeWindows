#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

//typedef struct SDL_Instance
//{
//	SDL_Window* window;
//	SDL_Renderer* renderer;
//} SDL_Instance;


int main(void)
{
	SDL_Window* window;
	SDL_Renderer* renderer;

	/*init SDL*/
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf(stderr, "unable to initialize SDL: %s\n", SDL_GetError());
		return(1);
	}

	/*Create a window instance*/
	window = SDL_CreateWindow("Trying", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 1200, 720, 0);
	if (!window)
	{
		printf("SDL window not inited correctly err: %s\n", SDL_GetError());
		SDL_Quit();
		return(1);
	}
	renderer = SDL_CreateRenderer(window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!renderer)
	{
		SDL_DestroyWindow(window);
		printf("SDL renderer not created correctly err:%s\n", SDL_GetError());
		SDL_Quit();
		return(1);
	}
	while ("C")
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0x00);
		SDL_RenderDrawLine(renderer, 10, 10, 10, 100);
		SDL_RenderPresent(renderer);
	}
	return(0);
}