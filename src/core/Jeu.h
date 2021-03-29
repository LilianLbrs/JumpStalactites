#ifndef _JEU_H
#define _JEU_H

#include "Map.h"
#include "Player.h"
#include "Stalactites.h"
#include "Coord.h"

/**
 * \file Jeu.h
 * \brief Module gérant la partie en cours
 * \version 0.1
 * \date 20/03/2021
 */

class Jeu {

private :

    Map map;
    Player player;
    Stalactites stalactite [5];

public :
    /**
     * \brief Constructeur par défaut de la classe Jeu
     */
    Jeu ();
    /**
     * \brief Accesseur qui retourne la map utilisée pour la partie
     */
    Map& getMap ();
    /**
     * \brief Accesseur qui retourne la map (const) utilisée pour la partie
     */
    const Map& getConstMap () const;
    /**
     * \brief Accesseur qui retourne le joueur (const) de la partie
     */
    const Player& getConstPlayer () const;
    /**
     * \brief Accesseur qui retourne le joueur de la partie
     */
    Player& getPlayer ();
    /**
     * \brief Accesseur qui retourne la stalactite d'indice i
     *
     * \param i : indice de la stalactite à retourner
     */
    const Stalactites& getStalactite (int i) const;
    /**
     * \brief Procédure qui gère les actions automatiques du jeu (stalactites)
     *
     * \param h :
     * \param posX :
     * \param i :
     */
    bool actionsAuto (int h, int posX, int i);
    /**
     * \brief Gère les actions saisies au clavier (mode texte uniquement)
     */
    void actionClavier (const char touche);

    void gravity ();

    int getDimMapX ();


};

#endif
