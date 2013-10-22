#ifndef		__SDLMANAGER_H__
#define		__SDLMANAGER_H__

#include <SDL/SDL.h>

#define MULTI 4

int	loadSDL(SDL_Surface *screen, SDL_Surface *pixel[2048], SDL_Rect *location);
int	unloadSDL(SDL_Surface *pixel[2048]);

#endif
