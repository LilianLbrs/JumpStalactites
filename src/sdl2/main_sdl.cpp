#include "sdlJeu.h"
#include <iostream>
#include <time.h>

int main (int argc, char** argv) {
	srand(time(NULL));
	sdlJeu sj;
	sj.sdlBoucle();
	return 0;
}