#include "utils.h"
/**
* Global init
*/

SDL_Window* window;
//SDL_Surface* ScreenSurface;
SDL_Surface* HelloWorld;
SDL_Renderer* s;



/**
 * init - initialises the window for the project
 * 
 * Return: 0 if succeful, -1 if not
 */
bool init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL couldn't init, Err: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		window = SDL_CreateWindow("TheMazeProject", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			800, 600, SDL_WINDOW_SHOWN);
		if (!window)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			/*ScreenSurface = SDL_GetWindowSurface(window);*/
			s = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (!s)
			{
				printf("SDL RENDERER NOT WORKING\n");
				success = false;
			}
		}

	}
	return success;
}

/**
 * loadMedia - Load a media to the window
 * 
 * Return: 0 if succeful, -1 if not
 */

bool LoadMedia()
{
	bool success = true;
	HelloWorld = SDL_LoadBMP("C:\\Users\\Yacin\\OneDrive\\Desktop\\imaget.bmp");
	if (!HelloWorld)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
		success = false;
	}
	return success;
}

/**
 * Close - Load a media to the window
 *
 */

void close()
{
	SDL_FreeSurface(HelloWorld);
	HelloWorld = NULL;
	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
}





int main(int argc, char* argv[])
{
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		if (!s)
		{
			printf("Rendered could not init %s\n", SDL_GetError());
		}
		SDL_Rect fillRect = { 380, 280, 20, 20 };


		SDL_Event e;
		bool quit = false;
		while (!quit)
		{
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT) quit = true;
			}

			SDL_SetRenderDrawColor(s, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderClear(s);
			SDL_SetRenderDrawColor(s, 0x33, 0x10, 0xf2, 0xFF);
			SDL_RenderFillRect(s, &fillRect);
			SDL_RenderPresent(s);
			SDL_Delay(16);
		}

		/* CLOSING */
		close();
	}
	return 0;
}
