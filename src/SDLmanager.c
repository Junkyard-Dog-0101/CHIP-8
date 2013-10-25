#include "../inc/SDLmanager.h"

int	loadSDL(SDL_Surface *screen, SDL_Surface *pixel[2048], SDL_Rect *location)
{
  int	i;
  int	x;
  int	y;

  SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  screen = SDL_SetVideoMode((64 * MULTI), (32 * MULTI), 16, SDL_HWSURFACE | SDL_NOFRAME);
  for (i = 0; i < 2048; ++i)
    pixel[i] = SDL_CreateRGBSurface(SDL_HWSURFACE, MULTI, MULTI, 16, 0, 0, 0, 0);
  SDL_FillRect(screen, NULL, 255);
  i = 0;
  for (y = 0; y < (32 * MULTI); y = y + MULTI)
    {
      location->y = y;
      for (x = 0; x < (64 * MULTI); x = x + MULTI)
	{
	  location->x = x;
	  if (x % 2)
	    SDL_FillRect(pixel[i], NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	  else
	    SDL_FillRect(pixel[i], NULL, SDL_MapRGB(screen->format, 0, 0, 0));
	  SDL_BlitSurface(pixel[i], NULL, screen, location);
	  ++i;
	}
    }
  SDL_Flip(screen);
  return (0);
}

int	unloadSDL(SDL_Surface *pixel[2048])
{
  int	i;

  for (i = 0; i < 2048; ++i) 
    SDL_FreeSurface(pixel[i]);
  SDL_Quit();
  return (0);
}

int	eventSDL(SDL_Event *event)
{
  if ((SDL_PollEvent(event) != 0) && (event->type == SDL_KEYDOWN))
    {
      switch (event->key.keysym.sym)
	{
	  /* |1|2|3|C| */
	case SDLK_1:
	  //
	  break;
	case SDLK_2:
	  //
	  break;
	case SDLK_3:
	  //
	  break;
	case SDLK_4:
	  //
	  break;

	  /* |4|5|6|D| */
	case SDLK_a:
	  //
	  break;
	case SDLK_z:
	  //
	  break;
	case SDLK_e:
	  //
	  break;
	case SDLK_r:
	  //
	  break;

	  /* |7|8|9|E| */
	case SDLK_q:
	  //
	  break;
	case SDLK_s:
	  //
	  break;
	case SDLK_d:
	  //
	  break;
	case SDLK_f:
	  //
	  break;

	  /* |A|0|B|F| */
	case SDLK_w:
	  //
	  break;
	case SDLK_x:
	  //
	  break;
	case SDLK_c:
	  //
	  break;
	case SDLK_v:
	  //
	  break;
	}
    }
  return (0);
}
