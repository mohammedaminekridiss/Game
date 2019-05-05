#include "structs.h"

  /* Prototypes des fonctions utilisées */

  extern void init(char *);
  extern void cleanup(void);
  extern void getInput(void);
  extern void draw(void);
  extern void delay(unsigned int);
  extern void loadGame(void);
  void initializeEnnemy(void);


  /* Déclaration des structures globales utilisées par le jeu */

  Input input;
  Gestion jeu;
  Map map ;
  ENNEMY monstre;
