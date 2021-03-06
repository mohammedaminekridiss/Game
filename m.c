#include<stdio.h>
#include"SDL/SDL.h"
#include"SDL/SDL_image.h"
#include"SDL/SDL_mixer.h"

int main(void)
{
char pause;
SDL_Surface *screen;
SDL_Surface *sprite;
SDL_Surface *image;
SDL_Rect positionecran;
SDL_Rect positionSprite;
SDL_Event test_event;
Mix_Music *musique;
int done =1;
int boucle_jeux=1;



if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("Unable to initialize SDL: %s\n",SDL_GetError());
return 1;
}

screen= SDL_SetVideoMode(600,400,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
if(screen==NULL)
{
printf("Unable to set video mode: %s\n",SDL_GetError());
return 1;
}

positionecran.x=0;
positionecran.y=0;
image =SDL_LoadBMP("background.bmp");
SDL_BlitSurface(image, NULL, screen , &positionecran);
SDL_Flip(screen);
if(image==NULL)
{
printf("Unable to load bitmap: %s\n",SDL_GetError());
return 1;
}

positionSprite.x=100;
positionSprite.y=220;
sprite = IMG_Load("detective.png");
SDL_SetColorKey(sprite, SDL_SRCCOLORKEY, SDL_MapRGB(sprite->format, 255, 255, 255));
SDL_BlitSurface(sprite, NULL, screen, &positionSprite);
SDL_Flip(sprite);
if(image==NULL)
{
printf("Unable to load PNG: %s\n",SDL_GetError());
return 1;
}


while(boucle_jeux)
{

SDL_FreeSurface(image);
if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
{
printf("%s",Mix_GetError());
}
musique=Mix_LoadMUS("music.mp3");
Mix_PlayMusic(musique, -1);

while(done) //TANT QUE la variable done ne reçoit pas 0
{
SDL_WaitEvent(&test_event); //on attend qu'on récupére un événement
switch(test_event.type) //on teste le type l'événement
{
case SDL_QUIT: //si c'est un événement  QUITTER
done = 0;
boucle_jeux=0; //on arrête
break;
case SDL_KEYDOWN: //touche enfoncée
switch(test_event.key.keysym.sym)
{
case SDLK_ESCAPE: //appuyer sur la touche Echap
done=0;
break;

case SDLK_LEFT:
positionSprite.x-=80;
break;
case SDLK_RIGHT:
if(positionSprite.x>=200&&positionecran.x<=1200)

{
  positionSprite.x=199;
  positionecran.x+=50;
}

else {positionSprite.x+=80;
}

printf("pos sprite.x = %d\n",positionSprite.x);
printf("pos ecran.x = %d",positionecran.x);
break;

case SDLK_UP:
positionSprite.y-=50;
break;

case SDLK_DOWN:
positionSprite.y+=50;
break;
default: //on ne traite pas les autres événements
break;
}
break;
default: break;
}
image =SDL_LoadBMP("background.bmp");
SDL_BlitSurface(image, NULL, screen , &positionecran);
SDL_Flip(screen);

SDL_BlitSurface(sprite, NULL, screen, &positionSprite);
SDL_Flip(screen);

}
SDL_FreeSurface(image);
SDL_FreeSurface(sprite);
Mix_FreeMusic(musique);
Mix_CloseAudio();
SDL_Quit;
pause=getchar();
}
return 0;
}
