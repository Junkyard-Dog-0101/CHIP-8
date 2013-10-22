#include <unistd.h>
#include "../inc/SDLmanager.h"

int	main()
{
  SDL_Surface	*screen;
  SDL_Surface	*pixel[2048];
  SDL_Rect	location;

  loadSDL(screen, pixel, &location);
  (void)screen;
  sleep(3);
  unloadSDL(pixel);
  return (0);
}
