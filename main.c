#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL_mixer.h"
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "header.h"
#include <SDL/SDL_ttf.h>
#include "libserialport.h"
char serialPortBuffer[SERIAL_PORT_BUFFER_LENGTH] = {0};
int serialPortReadDataLength = 0;

int main(int argc, char *argv[])
{ int start_game=0,dead=0;
SDL_Event event;
    int continuer = 1;
     unsigned int frameLimit = SDL_GetTicks() + 16;
SDL_Rect position_enemy;
SDL_Surface *fenetre=NULL;
objet c1,c2;
int i=1,coll=0;
Mix_Music *musique;
char lien[20];
int k=0;
start_game=menu1();
if(!Arduino_connect(SERIAL_PORT,9600))
exit(EXIT_FAILURE);
if(start_game==1)
{
        SDL_Init(SDL_INIT_VIDEO);

atexit(SDL_QUIT);
        s.ecran = SDL_SetVideoMode(558,417, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
        SDL_WM_SetCaption("Torn Asunder", NULL); 

if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
           {
           printf("%s",Mix_GetError());
           }

           musique=Mix_LoadMUS("music.ogg");
           Mix_PlayMusic(musique, -1);


        sprintf(lien,"r%d.png",i);
        p.sprite = IMG_Load(lien);
        //s.mask=IMG_Load("Coll.png");


        s.background=IMG_Load("final_map.png");
        SDL_SetColorKey(p.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(p.sprite->format, 255, 255, 255));    
        initialiser_personnage(&p);
        s.background=initialiser_stage(&s,"final_map.png");
        afficher_background(s.background,&s.pos,s.ecran);
        s.pos.x=0;
        s.pos.y=0;
        c1=init(c1,740,70,40,32);
        c2=init(c2,740,70,40,32);
 afficher_objet(c1,"c1.png",s.background);
  initializeEnnemy();

position_enemy.x=monstre.x;
position_enemy.y=monstre.y;
position_enemy.h=10;
position_enemy.w=5;
int x;
        while (continuer)
               {Deplacement_personnage(&event,&p,&continuer,&s);
//FUCKOFF RETAIN Y AXIS LIMITS -> Deplacement_personnage
if(p.position.y>250) p.position.y=250;
if(p.position.y<20) p.position.y=20;

x=arduinoReadData(&k);
switch(k)
{
  case 4 : printf("jump");
break;
case 2 : printf("right");
break;
case 3 : printf("left");
break;
}


//END_FUCKOFF
              coll=Collision(p.position,position_enemy);  //BBOX_COLLISON FULLY FUNCTIONNAL. WELL DONE MONKEY.
               //coll=collision_parfaite(s.mask,p.position); //WORKING NOW MONKEY,NOT TOO BAD FOR A SUPINE GELLATINOUS INVERTEBRATE GOON.
if(coll==1) 
{
p.position.x-=30;
p.v.val-=12.5;
monstre.x+=50; 
coll=0;
}
               if(i>5){i=1;}                
               anim_perso(&i,&event,&p);
                scrolling(&p,&s);
                afficher_background(s.background,&s.pos,s.ecran);
                afficher_vie(p.v,s.ecran);
                SDL_BlitSurface(p.sprite, NULL,s.ecran,&p.position);
                  drawanimatedEnnemy();
                   SDL_Flip(s.ecran);
                  delay(frameLimit);
                  frameLimit = SDL_GetTicks() + 16;
 /*              
if(Collision(c1.positionObjet,p.position)==1){
char pause;
getchar();
afficher_objet(c2,"c2.png",s.background);
printf("YOU SHALL NOT PASS !");
}*/

position_enemy.x=monstre.x;
position_enemy.y=monstre.y;
position_enemy.h=10;
position_enemy.w=5;

                SDL_Flip(s.ecran);

               }    

        }
 SDL_FreeSurface(s.background);
 SDL_FreeSurface(p.sprite);
    SDL_Quit();

    return EXIT_SUCCESS;

}
