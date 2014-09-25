#include "SDL.h"
#include "iostream"

using namespace std;

//set the screen dimensions - necessary
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;


int main(int argc, char ** argv)
{
	// The window thing we're gonna be rendering to
	SDL_Window* window = NULL;

	//Surface contained by window  - basically just a 2d image
	SDL_Surface* screenSurface = NULL;

	//Initialize SDL  - when theres an error, SDL returns -1
	if (SDL_Init(SDL_INIT_VIDEO) < 0)	//Only gonna be passing the SDL_INIT_VIDEO flag if all we need is the SDL video subsystem.
		printf("SDL couldn't be initialized. SDL Error: %s\n", SDL_GetError());
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		//                      caption of window      x-pos of window         y-pos of window                  makes sure window is shown upon creation		
		// If we were unable to create the window successfully, display an error message
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		// If we WERE able to create the window successfully, we get the window surface so we can draw on it
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			//Update the surface - shows whatever we've drawn
			SDL_UpdateWindowSurface(window);

			//Wait two seconds - the code to handle mouse/keyboard not there yet 
			SDL_Delay(2000);
		}
		
	}
	//After we're done with the code, we destroy the window we created. What was created has to be destroyed.
	SDL_DestroyWindow(window);
	// We the need to quit the SDL subsystems
	SDL_Quit();
	return 0;
}