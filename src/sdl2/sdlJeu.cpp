#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>


#include <iostream>
using namespace std;

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
        //cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
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

void Image::drawBG (SDL_Renderer * renderer, int x, int y, int w, int h) {
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




// =========== AFFICHAGE DU JEU ============ //


//Les attributs de l'écran (640 * 480)
const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 640;

//Les dimensions de la map
const int MAP_WIDTH = 1280;
int MAP_HEIGHT;

//La camera
SDL_Rect camera = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };




// ============= CLASS SDLJEU =============== //

sdlJeu::sdlJeu () : jeu() {
    MAP_HEIGHT = jeu.getConstMap().getDimY() * TAILLE_SPRITE;

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


    // Creation de la fenetre
    window = SDL_CreateWindow("JumpStalactites", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    // IMAGES

    //Player
    imPlayerRight.loadFromFile("data/playerRight.png",renderer);
    imPlayerLeft.loadFromFile("data/playerLeft.png",renderer);
    imRunRight.loadFromFile("data/runright.png",renderer);
    imRunLeft.loadFromFile("data/runleft.png",renderer);
    imJumpRight.loadFromFile("data/jumpRight.png",renderer);
    imJumpLeft.loadFromFile("data/jumpLeft.png",renderer);

    //Enemy
    imEnemyRight.loadFromFile("data/EnemyRight.png",renderer);
    imEnemyLeft.loadFromFile("data/EnemyLeft.png",renderer);

    //HUD
    imVie3.loadFromFile("data/vie3.png",renderer);
    imVie2.loadFromFile("data/vie2.png",renderer);
    imVie1.loadFromFile("data/vie1.png",renderer);
    imVie0.loadFromFile("data/vie0.png",renderer);

    //World
    imPlatform.loadFromFile("data/platform.png",renderer);
    imSnowPlatform.loadFromFile("data/snowy_platform.png",renderer);
    imFirePlatform.loadFromFile("data/fire_platform.png",renderer);
    imLavaPlatform.loadFromFile("data/lava_platform.png",renderer);
    imBackground.loadFromFile("data/background.jpg",renderer);
    imStalactite.loadFromFile("data/IceSpike.png",renderer);
    imPlatformSpikeUp.loadFromFile("data/PlatformSpikeUp.png",renderer);
    imPlatformSpikeDown.loadFromFile("data/PlatformSpikeDown.png",renderer);
    imFuntain.loadFromFile("data/funtain.png",renderer);
    
    //Menu
    imTitre.loadFromFile("data/letitre.png",renderer);
    imTitreMort.loadFromFile("data/titremort.png",renderer);
    imMenuFond.loadFromFile("data/fondglace.png",renderer);
    imBoutonJoue.loadFromFile("data/play.png",renderer);
    imBoutonQuitter.loadFromFile("data/exit.png",renderer);
    imBoutonRejouer.loadFromFile("data/rejouer.png",renderer);
    
    
}

sdlJeu::~sdlJeu () {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdlJeu::sdlAff (bool leftPressed,bool jumpPressed,bool rightPressed,bool escapePressed,bool mort) {
	//Remplir l'�cran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

	int x,y;
	const Map& map = jeu.getConstMap();
	const Player& player = jeu.getConstPlayer();
    const vector<Enemy>& vectEnemies = jeu.getVectEnemies();

    //Afficher le background
    imBackground.drawBG(renderer, 0, 0, SCREEN_WIDTH, SCREEN_WIDTH);

    // Afficher les sprites des plateformes et des pics
	for (x=0;x<map.getDimX();++x)
		for (y=0;y<map.getDimY();++y)
        {
			if (map.getXY(x,y)=='#')
                imPlatform.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE - camera.y,TAILLE_SPRITE,TAILLE_SPRITE);
            if (map.getXY(x,y)=='w')
                imSnowPlatform.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE - camera.y,TAILLE_SPRITE,TAILLE_SPRITE);
            if (map.getXY(x,y)=='F')
                imFirePlatform.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE - camera.y,TAILLE_SPRITE,TAILLE_SPRITE);
            if (map.getXY(x,y)=='L')
                imLavaPlatform.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE - camera.y,TAILLE_SPRITE,TAILLE_SPRITE);
            if (map.getXY(x,y)=='^')
				imPlatformSpikeUp.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE - camera.y,TAILLE_SPRITE,TAILLE_SPRITE);
            if (map.getXY(x,y)==';')
				imPlatformSpikeDown.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE - camera.y,TAILLE_SPRITE,TAILLE_SPRITE);
            if (map.getXY(x,y)=='V')
                imFuntain.draw(renderer,x*TAILLE_SPRITE,y*TAILLE_SPRITE - camera.y-TAILLE_SPRITE*1.5,TAILLE_SPRITE*2.5,TAILLE_SPRITE*2.5);
        }

    //Afficher les sprites des stalactites
    for (int i = 0; i < 5; i++ ){
            if(!jeu.getStalactite(i).hidden){
                imStalactite.draw(renderer,jeu.getStalactite(i).coord.getPosx(), jeu.getStalactite(i).coord.getPosy() - camera.y, TAILLE_SPRITE,TAILLE_SPRITE);
            }
    }

	// Afficher le sprite du joueur
    if ( (player.immune && SDL_GetTicks()%500>250) || !player.immune){
        if (jumpPressed){
            if (dir) imJumpRight.draw(renderer,player.getPosX(),player.getPosY() - 1 - camera.y,TAILLE_SPRITE*2,TAILLE_SPRITE*2);
            else imJumpLeft.draw(renderer,player.getPosX(),player.getPosY() - 1 - camera.y,TAILLE_SPRITE*2,TAILLE_SPRITE*2);
        }
        else if (leftPressed) imRunLeft.draw(renderer,player.getPosX(),player.getPosY() - 1 - camera.y,TAILLE_SPRITE*2,TAILLE_SPRITE*2);
        else if (rightPressed) imRunRight.draw(renderer,player.getPosX(),player.getPosY() - 1 - camera.y,TAILLE_SPRITE*2,TAILLE_SPRITE*2);
        else {
            if (dir) imPlayerRight.draw(renderer,player.getPosX(),player.getPosY() - 1 - camera.y,TAILLE_SPRITE,TAILLE_SPRITE*2);
            else imPlayerLeft.draw(renderer,player.getPosX(),player.getPosY() - 1 - camera.y,TAILLE_SPRITE,TAILLE_SPRITE*2);
        }
    }

    // Afficher le sprite de l'ennemi
    for(unsigned int i= 0; i < vectEnemies.size(); i++){
        if(vectEnemies[i].dir)
            imEnemyRight.draw(renderer, vectEnemies[i].coord.getPosx(), (vectEnemies[i].coord.getPosy() - TAILLE_SPRITE) - camera.y,TAILLE_SPRITE*2,TAILLE_SPRITE*2);
        else
            imEnemyLeft.draw(renderer, vectEnemies[i].coord.getPosx(), (vectEnemies[i].coord.getPosy() - TAILLE_SPRITE) - camera.y,TAILLE_SPRITE*2,TAILLE_SPRITE*2);
    }
    //afficher les points de vie
    if(player.getHealth()<=0 && escapePressed==false)
    {
        imVie0.draw(renderer,0,0,TAILLE_SPRITE*3,TAILLE_SPRITE);
    }
    else
    {if(player.getHealth()==1 && escapePressed==false){
        imVie1.draw(renderer,0,0,TAILLE_SPRITE*3,TAILLE_SPRITE);

    }else{
    if(player.getHealth()==2 && escapePressed==false){
        imVie2.draw(renderer,0,0,TAILLE_SPRITE*3,TAILLE_SPRITE);
    }
    else{
    if(player.getHealth()==3 && escapePressed==false){
        imVie3.draw(renderer,0,0,TAILLE_SPRITE*3,TAILLE_SPRITE);
    }
    }
    }
    }

    if(escapePressed)
    {
        //imMenuFond.draw(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        imBoutonJoue.draw(renderer, SCREEN_WIDTH/2-TAILLE_SPRITE*4,SCREEN_HEIGHT/6+TAILLE_SPRITE/2,TAILLE_SPRITE*8,TAILLE_SPRITE*4);
        imBoutonQuitter.draw(renderer,SCREEN_WIDTH/2-TAILLE_SPRITE*2,SCREEN_HEIGHT/2-TAILLE_SPRITE/2,TAILLE_SPRITE*4,TAILLE_SPRITE*4);
        imTitre.draw(renderer,SCREEN_WIDTH/2-TAILLE_SPRITE*8,TAILLE_SPRITE,TAILLE_SPRITE*16,TAILLE_SPRITE*2);
    }

    if(mort)
    {
        //imMenuFond.draw(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
        imBoutonRejouer.draw(renderer, SCREEN_WIDTH/2-TAILLE_SPRITE*4,SCREEN_HEIGHT/6+TAILLE_SPRITE/2,TAILLE_SPRITE*8,TAILLE_SPRITE*4);
        imBoutonQuitter.draw(renderer,SCREEN_WIDTH/2-TAILLE_SPRITE*2,SCREEN_HEIGHT/2-TAILLE_SPRITE/2,TAILLE_SPRITE*4,TAILLE_SPRITE*4);
        imTitreMort.draw(renderer,SCREEN_WIDTH/2-TAILLE_SPRITE*8,TAILLE_SPRITE,TAILLE_SPRITE*16,TAILLE_SPRITE*2);
    }
}

void sdlJeu::sdlBoucle () {
    SDL_Event events;
	bool quit = false;
    bool leftPressed = false, rightPressed = false,
    jumpPressed = false, escapePressed = true;
    Player player;
    bool enPause=true;
    bool mort = false;

	// tant que ce n'est pas la fin ...
	while (!quit) {

        //boucle menu
        while (SDL_PollEvent(&events))
        {
        if(mort)
        {
            switch (events.type)
            {
                case SDL_QUIT:
                quit = true;
                break;
                escapePressed=true;
                case SDL_MOUSEBUTTONUP:
                    if(events.button.button == SDL_BUTTON_LEFT)
                    {
                        if(events.button.x > SCREEN_WIDTH/2-TAILLE_SPRITE*4 && events.button.x< SCREEN_WIDTH/2+TAILLE_SPRITE*4 && events.button.y > SCREEN_HEIGHT/6 && events.button.y<SCREEN_HEIGHT/6+TAILLE_SPRITE*4)
                        {
                           leftPressed = false,rightPressed = false, jumpPressed = false;
                           jeu.initJeu();
                           mort=false;
                        }
                        else if(events.button.x >SCREEN_WIDTH/2-TAILLE_SPRITE*2 && events.button.x<SCREEN_WIDTH/2+TAILLE_SPRITE*2 && events.button.y > SCREEN_HEIGHT/2 && events.button.y<SCREEN_HEIGHT/2+TAILLE_SPRITE*4)
                        {
                            exit(0);
                        }

                    }
                    break;

            }
        }
        else{
        if(enPause)
        {
            switch (events.type)
            {
                case SDL_QUIT:
                quit = true;
                break;
                escapePressed=true;
                case SDL_MOUSEBUTTONUP:
                    if(events.button.button == SDL_BUTTON_LEFT)
                    {
                        if(events.button.x > SCREEN_WIDTH/2-TAILLE_SPRITE*4 && events.button.x< SCREEN_WIDTH/2+TAILLE_SPRITE*4 && events.button.y > SCREEN_HEIGHT/6 && events.button.y<SCREEN_HEIGHT/6+TAILLE_SPRITE*4)
                        {
                            leftPressed = false, rightPressed = false, jumpPressed = false;
                            enPause = false;
                            escapePressed=false;

                        }
                        else if(events.button.x >SCREEN_WIDTH/2-TAILLE_SPRITE*2 && events.button.x<SCREEN_WIDTH/2+TAILLE_SPRITE*2 && events.button.y > SCREEN_HEIGHT/2 && events.button.y<SCREEN_HEIGHT/2+TAILLE_SPRITE*4)
                        {
                            exit(0);
                        }

                    }
                    break;

            }
            }

		// tant qu'il y a des evenements � traiter (cette boucle n'est pas bloquante)
            else{
            switch (events.type)
            {
                case SDL_QUIT:
                quit = true;
                break;

                case SDL_KEYDOWN:
                switch (events.key.keysym.scancode)
                {
                    case SDL_SCANCODE_SPACE:
                    jumpPressed = true;
                    break;
                    case SDL_SCANCODE_A:
                    case SDL_SCANCODE_LEFT:
                    leftPressed = true;
                    dir = 0;
                    break;
                    case SDL_SCANCODE_D:
                    case SDL_SCANCODE_RIGHT:
                    rightPressed = true;
                    dir = 1;
                    break;
                    case SDL_SCANCODE_ESCAPE:
                    escapePressed = true;
                    enPause = true;
                    break;
                    default:
                    break;
                    }
                break;
                case SDL_KEYUP:
                switch (events.key.keysym.scancode)
                {
                    case SDL_SCANCODE_SPACE:
                    jumpPressed = false;
                    break;
                    case SDL_SCANCODE_A:
                    case SDL_SCANCODE_LEFT:
                    leftPressed = false;
                    break;
                    case SDL_SCANCODE_D:
                    case SDL_SCANCODE_RIGHT:
                    rightPressed = false;
                    break;
                    default:
                    break;
                    }
                break;
                default:
                break;
            }
            }
        }
    }
        //on traite le cas du jeu en pause
        if(enPause){
       	sdlAff(rightPressed,jumpPressed,leftPressed,escapePressed,mort);
        }

        //on traite le cas du jeu quand le personnage joueur est mort
        else{
        if(mort){
        sdlAff(rightPressed,jumpPressed,leftPressed,escapePressed,mort);
        for(int i=0; i<5; i++){
            jeu.setStalactite(i).cacherStalactites(jeu.getConstMap(), jeu.getPlayer(), TAILLE_SPRITE);}
        }

        //on traite le cas du jeu du jeu en cours
        else{
        //on vérifie si il est mort ou vivant
        if(jeu.getPlayer().getHealth()<=0){mort=true;}

        // on actualise la position du joueur
        jeu.getPlayer().updatePlayerSdl(jeu.getConstMap(), rightPressed, leftPressed, jumpPressed, SDL_GetTicks(), TAILLE_SPRITE);
        
        // on actualise la position des stalactites
        for(int i=0; i<5; i++){
            jeu.setStalactite(i).updateStalactite(jeu.getConstMap(), jeu.getPlayer(), SDL_GetTicks(), TAILLE_SPRITE);
        }

        // on actualise la position de l'ennemi
        vector<Enemy> & vectEnemies = jeu.getVectEnemies();
        for(unsigned int i = 0; i < vectEnemies.size(); i++){
            vectEnemies[i].move(jeu.getConstMap(),jeu.getPlayer(), TAILLE_SPRITE, SDL_GetTicks());
        }

        //on ajuste la position de la camera
        camera.y = jeu.getPlayer().getPosY() - SCREEN_HEIGHT / 2;
        if( camera.y <= 0 ) camera.y = 0;
        if (camera.y >= MAP_HEIGHT - SCREEN_HEIGHT) camera.y = MAP_HEIGHT - SCREEN_HEIGHT;
        

        // on affiche le jeu sur le buffer cach�
	    sdlAff(rightPressed,jumpPressed,leftPressed,escapePressed,mort);
        }
        }
		// on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
        SDL_Delay(30);

	}
}


