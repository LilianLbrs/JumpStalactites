#ifndef _JEU_H
#define _JEU_H

#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include "Stalactites.h"
#include "Coord.h"
#include "Const.h"

/**
 * \file Jeu.h
 * \brief Module gérant la partie en cours
 * \version 1.0
 * \date 09/05/2021
 */

/**
 * \class Jeu
 * \brief Classe gérant la partie en cours
 */

class Jeu {

private :

    Map map;
    Player player;
    Stalactites stalactite [5];
    vector<Enemy> vectEnemies;
    Enemy enemy;

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
     * \brief Accesseur qui retourne la stalactite (const) d'indice i
     *
     * \param i : indice de la stalactite à retourner
     */
    const Stalactites& getStalactite (int i) const;
    /**
     * \brief Accesseur qui  retourne la stalactite d'incdice i
     *
     *\param i : indice de la stalactite à retourner
     */
     Stalactites& setStalactite(int i);
     /**
     * \brief Accesseur qui retourne l'ennemy
     */
     vector<Enemy>& getVectEnemies ();
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
    /**
     * \brief Initialise le personnage et les stalactites
     */
    void initJeu ();
    /**
     * \brief gère la gravité
     */
    void gravity ();
    /**
     * \brief retourne la taille (abscisses) de la map
     */
    int getDimMapX ();


};

#endif
