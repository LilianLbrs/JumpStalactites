#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"
#include <time.h> 
#include <string.h>

#include "../core/Jeu.h"

void txtAff(WinTXT & win, const Jeu & jeu) {
	const Map& map = jeu.getConstMap();
	const Player& player = jeu.getConstPlayer();
	Stalactites stalactite[5];
	for (int i = 0; i < 5; i++){
		stalactite[i] = jeu.getStalactite(i);
	}

	win.clear();

    // Affichage des murs et des plateformes
	for(int x=0;x<map.getDimX();++x)
		for(int y=0;y<map.getDimY();++y)
			win.print(x,y,map.getXY(x,y));

	// Affichage de Pacman
	win.print(player.getPosX(),player.getPosY(),'P');

	//Affichage des stalactites
	for(int i = 0; i<5; i++){
		if (!stalactite[i].hidden) win.print(stalactite[i].posX,stalactite[i].posY,'|');
	}

	win.draw();
}

void endGame (WinTXT & win, const Jeu & jeu) {
	win.clear();
	printf ("Fin de partie \n");
	win.pause();
}

void txtBoucle (Jeu & jeu) {
	srand (time(NULL));

	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getConstMap().getDimX(),jeu.getConstMap().getDimY());

	bool ok = true;
	int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32
		
		c = win.getCh();
		switch (c) {
			case 'q':
				jeu.actionClavier('q');
				break;
			case 'd':
				jeu.actionClavier('d');
				break;
			case ' ':
				jeu.actionClavier(' ');
				break;
			/*case 'escape':
				jeu.actionClavier('escape');
				break;*/
		}

		jeu.gravity();

		int i =0;
		while (i<5) {
			ok = !jeu.actionsAuto(rand() % 5 + 1, (rand()% jeu.getDimMapX() +1), i);
			if (!ok) i = 6;
			i++;
		}

	} while (ok);

	endGame(win, jeu);

}
