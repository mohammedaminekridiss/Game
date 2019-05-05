#include "defs.h"

typedef struct Input
  {

    int left, right, up, down, jump, attack, enter, erase, pause;

  } Input;

typedef struct Gestion
  {

    SDL_Surface *screen;

  } Gestion;

typedef struct Map
  {

      SDL_Surface *background;

  } Map;

typedef struct ENNEMY
   {
       
       SDL_Surface *sprite;
       int x, y;
       int frameNumber, frameTimer;
       int direction ;

   } ENNEMY;
