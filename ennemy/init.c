#include "init.h"

   /* Fonction qui initialise le jeu */

   void init(char *title)
   {
  

    if (SDL_Init(SDL_INIT_VIDEO ) < 0)
    {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }


    jeu.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE|SDL_DOUBLEBUF);

     /* Si on y arrive pas, on quitte */

    if (jeu.screen == NULL)
        {
            printf("Couldn't set screen mode to %d x %d: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
            exit(1);
        }


    /* On entre le titre de la fenêtre */

    SDL_WM_SetCaption(title, NULL);


    /* On cache le curseur de la souris */

    SDL_ShowCursor(SDL_DISABLE);

    }

   void loadGame(void)
    {

        /* Charge l'image du fond */
        map.background = loadImage("graphics/background.png");

     }


   /* Fonction qui quitte le jeu proprement */

    void cleanup()
   {
     /* Libère l'image du background */

      if (map.background != NULL)
      {
            SDL_FreeSurface(map.background);
      }

      /* Quitte la SDL */
      SDL_Quit();

    }
