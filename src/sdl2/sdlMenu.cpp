#include <cassert>
#include <time.h>
#include "sdlMenu.h"
#include "../core/Jeu.h"
#include "sdlJeu.h"
#include <stdlib.h>

#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 32;

float temps () {
    return float(SDL_GetTicks())*10000 / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Image::Image () {
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return texture;}

void Image::setSurface(SDL_Surface * surf) {surface = surf;}

// ============= CLASS SDLMENU =============== //

sdlMenu::sdlMenu () : jeu() {
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }


	dimWindowX = jeu.getConstMap().getDimX() * TAILLE_SPRITE;
	dimWindowY = jeu.getConstMap().getDimY() * TAILLE_SPRITE;

    // Creation de la fenetre
    window = SDL_CreateWindow("Menu", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimWindowX, dimWindowY, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES
    imMenu.loadFromFile("data/menu.png",renderer);
}

sdlMenu::~sdlMenu () {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlMenu::sdlAff () {
	//Remplir l'�cran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

	int x,y;
	const Map& map = jeu.getConstMap();
	const Player& player = jeu.getConstPlayer();

    //Afficher le background
    imMenu.draw(renderer, 0, 0, dimWindowX, dimWindowY);
}

void sdlMenu::resizeWindow(int windowWidth, int windowHeight) {
    dimWindowX = windowWidth;
    dimWindowY = windowHeight;
}

void sdlMenu::sdlBoucle () {
    SDL_Event events;
    SDL_Rect positionMenu, positionClic,positionTxt;
	bool quit = false;
    positionMenu.x=0;
    positionMenu.y=0;

	// tant que ce n'est pas la fin ...
	while (!quit) {


		// tant qu'il y a des evenements � traiter (cette boucle n'est pas bloquante)
		while (SDL_PollEvent(&events))
        {
            switch (events.type)
            {
                case SDL_QUIT:
                quit = true;
                break;
                case SDL_WINDOWEVENT:
                if (events.window.event == SDL_WINDOWEVENT_RESIZED) {
                resizeWindow(events.window.data1, events.window.data2);
                }
                break;
                case SDL_MOUSEBUTTONUP:
                if(events.button.button == SDL_BUTTON_LEFT)
                    {
                        positionClic.x = events.button.x;
                        positionClic.y = events.button.y;

                        if(events.button.x >240 && events.button.x<410 && events.button && events.button.y > 105 && events.button.y<170)//jouer
                        {
                            sdlJeu sj;
	                        sj.sdlBoucle();

                        }
                        else if(events.button.x >280 && events.button.x<370 && events.button && events.button.y > 270 && events.button.y<350)
                        {
                            exit(0);
                        }

                    }
                    break;
                
            }
        }


        // on affiche le jeu sur le buffer cach�
	    sdlAff();

		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
        SDL_Delay(30);
	}

}
