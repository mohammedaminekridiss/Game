jeu:fonction.o main.o arduino.o
	gcc fonction.o main.o arduino.o -o jeu -lSDL_image -lSDL -lSDL_mixer -lSDL_ttf -lserialport -g
arduino.o:arduino.c
	gcc -c arduino.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lserialport -g
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lserialport -g
fonction.o:fonction.c
	gcc -c fonction.c -lSDL -lSDl_image -lSDL_mixer -lSDL_ttf -lserialport -g

