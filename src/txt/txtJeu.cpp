#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "../core/Jeu.h"

void txtAff(WinTXT & win, const Jeu & jeu) {
	const Map& map = jeu.getConstMap();

	win.clear();

    // Affichage des murs et des plateformes
	for(int x=0;x<map.getDimX();++x)
		for(int y=0;y<map.getDimY();++y)
			win.print(x,y,map.getXY(x,y));

	win.draw();
}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getConstMap().getDimX(),jeu.getConstMap().getDimY());

	bool ok = true;
	//int c;

	do {
	    txtAff(win,jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

		/*c = win.getCh();
		switch (c) {
			case 'q':
				jeu.actionClavier('q');
				break;
			case 'd':
				jeu.actionClavier('d');
				break;
			case 'space':
				jeu.actionClavier('space');
				break;
			case 'escape':
				jeu.actionClavier('escape');
				break;
		}*/

	} while (ok);

}
