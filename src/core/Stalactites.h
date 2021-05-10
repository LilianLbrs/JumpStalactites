#ifndef _STALACTITES_H
#define _STALACTITES_H

#include "Map.h"
#include "Player.h"
#include "Coord.h"

/**
 * \file Stalactites.h
 * \version 1.0
 * \date 09/05/2021
 * \brief Module gérant les stalactites et leur mouvement
 */

/**
 * \class Stalactites
 * \brief Classe gérant les stalactites et leur mouvement
 */
class Stalactites {
    private:


    public:
    bool hidden;
    Coord coord;

    /**
     * \brief Constructeur par défaut de la classe stalactites
     */
    Stalactites ();
    /**
     * \brief Constructeur qui initialise la position de la stalactite avec le parametre posX
     * \param posX position sur l'axe des abscisses
     */
    Stalactites (int posX);
    /**
     * \brief Surcharge de l'opérateur =
     */
    void operator=(const Stalactites& s);
    /**
     * \brief Actualise la position de la stalactite
     * \param m Map
     * \param p Joueur
     * \param ticks Nombre de ticks depuis le lancement de l'application (pour l'invincibilité temporaire)
     * \param taille Taille d'une stalactite
     */
    void updateStalactite(const Map& m, Player& p, int ticks, int taille = 1);
    /**
     * \brief Fonction qui gère la hitbox des stalactites
     * \param m Map du jeu
     * \param p Joueur
     * \param taille Taille d'une stalactite
	*/
    bool box(const Map& m, Player& p, int taille = 1);
    /**
     * \brief Fonction qui cache une stalactite quand elle touche le joueur
     * \param m Map du jeu
     * \param p Joueur
     * \param taille Taille d'une stalactite
	*/
    void cacherStalactites(const Map& m,Player& p,int taille = 1);

};

#endif
