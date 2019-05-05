
#include "animation.h"


void drawanimatedEnnemy()
{
    
    /* Gestion du timer */

    // Si notre timer (un compte à rebours en fait) arrive à zéro

    if (monstre.frameTimer <= 0)
    {
        //On le réinitialise

        monstre.frameTimer = TIME_BETWEEN_2_FRAMES;

        //Et on incrémente notre variable qui compte les frames de 1 pour passer à la suivante

        monstre.frameNumber++;
        monstre.x += (monstre.direction) * 4 ;
		
	
		
		if ((monstre.x < 0)&&(monstre.direction==-1))
		{
			monstre.direction = - monstre.direction ;
                        monstre.sprite = loadImage("graphics/walkright.png");
		}
		
		if (monstre.x + ENNEMY_WIDTH >= SCREEN_WIDTH)
		{
			monstre.direction= -monstre.direction;
                        monstre.sprite = loadImage("graphics/walkleft.png");
		}

        //Mais si on dépasse la frame max, il faut revenir à la première
        //Pour connaître la frame max, il suffit de diviser la longueur du spritesheet
        //par la longueur de notre héros : 480 / 40 = 12 frames
        //Puisque la première frame est la numéro 0, la dernière est donc la numéro 11

        if(monstre.frameNumber >= monstre.sprite->w / ENNEMY_WIDTH)
            monstre.frameNumber = 0;

    }
    //Sinon, on décrémente notre timer
    else
        monstre.frameTimer--;


    //Ensuite, on peut passer la main à notre fonction
    drawEnnemy();


}  
