#include "main.h"

    int main( int argc, char *argv[ ] )
   {
    unsigned int frameLimit = SDL_GetTicks() + 16;
    int go;


    /* Initialisation de la SDL dans une fonction séparée (voir après) */
        init("ahmed kridiss");
   
        loadGame();
     
        initializeEnnemy();

   /* Appelle la fonction cleanup à la fin du programme */
         atexit(cleanup);

    go = 1;


    /* Boucle infinie, principale, du jeu */

    while (go == 1)
    {

        /* On vérifie l'état des entrées (clavier puis plus tard joystick */
        getInput();

        /* On affiche tout */
        draw();

        /* Gestion des 60 fps ( 60 images pas seconde : soit 1s ->1000ms/60 = 16.6 -> 16
        On doit donc attendre 16 ms entre chaque image (frame) */
        delay(frameLimit);
        frameLimit = SDL_GetTicks() + 16;

    }

    /* Exit */
    exit(0);

    }

