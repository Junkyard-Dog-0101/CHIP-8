#include <unistd.h>
#include "SDL/SDL.h"

#define MULTI 9

int	main()
{
  SDL_Surface	*screen;
  SDL_Surface	*pixel[2048];
  SDL_Rect	location;
  int		i;
  int		x;
  int		y;

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  screen = SDL_SetVideoMode((64 * MULTI), (32 * MULTI), 16, SDL_HWSURFACE | SDL_NOFRAME);
  for (i = 0; i < 2048; ++i)
    pixel[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, MULTI, MULTI, 16, 0, 0, 0, 0);
  SDL_FillRect(screen, NULL, 255);
  i = 0;
  for (y = 0; y < (32 * MULTI); y = y + MULTI)
    {
      location.y = y;
      for (x = 0; x < (64 * MULTI); x = x + MULTI)
	{
	  location.x = x;
	  if (x % 2)
	    SDL_FillRect(pixel[i], NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	  else
	    SDL_FillRect(pixel[i], NULL, SDL_MapRGB(screen->format, 0, 0, 0));
	  SDL_BlitSurface(pixel[i], NULL, screen, &location);
	  ++i;
	}
    }
  SDL_Flip(screen);
  sleep(3);
  for (i = 0; i < 2048;  ++i) 
    SDL_FreeSurface(pixel[i]);
  SDL_Quit();
  return (0);
}
