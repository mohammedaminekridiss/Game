#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct
{
 SDL_Rect position;
 SDL_Surface *sprite;
 int vitesse;
 int acceleration;
 int vie;
 int score;
}personnage;

typedef struct 
{
SDL_Surface *background;
SDL_Surface *ecran;
SDL_Rect pos;
}stage;



SDL_Surface *initialiser_stage(stage *s,char chaine[])
{
  s->pos.x=0;
  s->pos.y=0;
  s->pos.w=s->background->w;
  s->pos.h=s->background->h;
  
SDL_Surface *tmp=NULL,*image=NULL;
    tmp=IMG_Load(chaine);
    SDL_SetColorKey(tmp,SDL_SRCCOLORKEY,SDL_MapRGB(tmp->format,255,255,255));
    image=SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    tmp=NULL;
    return image;
 
}


void initialiser_personange(personnage *p)
{
  p->position.x=0;
  p->position.y=0;
  p->vie=5;
  p->acceleration=0;
  p->vitesse=10;
  p->score=0;
}

void afficher_background(SDL_Surface *bg,SDL_Rect *pos,SDL_Surface *screen)
{
SDL_BlitSurface(bg,pos,screen,NULL);
}


void Deplacement_personnage(SDL_Event *event,personnage *p,int *continuer,stage *s)
{

SDL_PollEvent(event);
     switch(event->type)
        {
            case SDL_QUIT:
                (*continuer)=0;
                break;
            case SDL_MOUSEBUTTONDOWN :
if(event->button.button==SDL_BUTTON_LEFT)
   {
if(event->button.x-s->pos.x>p->position.x-s->pos.x)
{
p->position.x+=p->vitesse+p->acceleration*0.2;}

if(event->button.x-s->pos.x<p->position.x-s->pos.x)
{
p->position.x-=p->vitesse+p->acceleration*0.2;}


    }
break;           
 case SDL_KEYDOWN:
                switch(event->key.keysym.sym)
                {
                    case SDLK_UP: 
p->position.y-=p->vitesse+p->acceleration*0.2;
                        break;
                    case SDLK_DOWN: 
p->position.y+=p->vitesse+p->acceleration*0.2;

                        break;
                    case SDLK_RIGHT: 
p->position.x+=p->vitesse+p->acceleration*0.2;
                        break;
                    case SDLK_LEFT: 
p->position.x-=p->vitesse+p->acceleration*0.2;
                        break;
                }
                break;
             }
       
}


void scrolling(personnage *p,stage *stage1 )
{      

if((p->position.x>=750)&&(stage1->pos.x<=3733))
       {
         stage1->pos.x+=20;
         p->position.x=740;
       }
           if((p->position.x<=50)&&(stage1->pos.x>=0))
             {
                   stage1->pos.x-=20;
                   p->position.x=60;
             }

}
int main(int argc, char *argv[])
{
    SDL_Event event;
    int continuer = 1;
personnage p;
stage s;
    SDL_Init(SDL_INIT_VIDEO);
   // s.ecran = SDL_SetVideoMode(1000, 480, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
s.ecran = SDL_SetVideoMode(558,417, 32, SDL_HWSURFACE);    
SDL_WM_SetCaption("Test", NULL);
    p.sprite = IMG_Load("detective.png");
    s.background=IMG_Load("small.png");
    SDL_SetColorKey(p.sprite, SDL_SRCCOLORKEY, SDL_MapRGB(p.sprite->format, 0, 0, 255));    
    initialiser_personange(&p);
    s.background=initialiser_stage(&s,"small.png");   
    while (continuer)
    {
   Deplacement_personnage(&event,&p,&continuer,&s);
   scrolling(&p,&s);
   afficher_background(s.background,&s.pos,s.ecran);
   SDL_BlitSurface(p.sprite, NULL,s.ecran,&p.position);
   SDL_Flip(s.ecran);
    }

    SDL_FreeSurface(p.sprite);
    SDL_Quit();

    return EXIT_SUCCESS;
}
