#include "SDL.h"
#include "iostream"

using namespace std;

//set the screen dimensions - necessary
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//---------------------------------------------------------Global Variables-------------------------------------------------------

//Generally -dont- want to put these in Globals but since this is a small one it doesnt make a difference

// The window thing we're gonna be rendering to
SDL_Window* gWindow = NULL;

//Surface contained by window  - basically just a 2d image
SDL_Surface* gScreenSurface = NULL;

// the image that's gonna be put on the screen
SDL_Surface* gHelloWorld = NULL;
//---------------------------------------------------------Helper Functions-------------------------------------------------------

//_________________________________________________ starts SDL and creates window ________________________________________________
bool init()
{
	// Initializaton flag
	bool success = true;		

	//Initialize SDL  - when theres an error, SDL returns -1
	if (SDL_Init(SDL_INIT_VIDEO) < 0)	//Only gonna be passing the SDL_INIT_VIDEO flag if all we need is the SDL video subsystem.
		printf("SDL couldn't be initialized. SDL Error: %s\n", SDL_GetError());
	
	else
	{
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		//                      caption of window      x-pos of window         y-pos of window                  makes sure window is shown upon creation		
		// If we were unable to create the window successfully, display an error message
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			
			//Wasn't able to create window so naturally you didn't succeed
			success = false;
		}
		
		// If we WERE able to create the window successfully, we get the window surface so we can draw on it
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;

}


//_________________________________________________________ Loads media ________________________________________________________
bool loadMedia()
{
	bool success = true;
	//load splash image
	gHelloWorld = SDL_LoadBMP("league-of-legends-logo1.bmp");

	printf("here\n");

	// If image fails to load
	if (gHelloWorld = NULL)
	{
		printf("Unable to load image! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	return success;

}

//_________________________________________________ Frees media, shuts down SDL ________________________________________________
void close()
{
	//Dealloc surface
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;

	// Destroy window
	SDL_DestroyWindow(gWindow);

	//Quit SDL Subsystems
	SDL_Quit();
}

//-------------------------------------------------------------- Main -----------------------------------------------------------
int main(int argc, char ** argv)
{
	//Start up SDL, creat window

	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media\n");
		}
		else
		{
			//Apply the image
			// Blitting = making a copy of the image and putting it on the screen surface
			SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);
			
			//Update the surface
			SDL_UpdateWindowSurface(gWindow);
			// Wait 2 seconds
			SDL_Delay(6000);
		}
	}
	// Free resources and close SDL
	close();
	return 0;
}