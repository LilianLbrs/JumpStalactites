#ifndef _MAP_H
#define _MAP_H

#include "Coord.h"
#include <vector>

/**
 * \file Map.h
 * \brief Module gérant la carte du jeu
 * \version 0.1
 * \date 20/03/2021
 */

class Map {
    private:

        const int dimx = 30;
        const int dimy = 38;
        char mapTable [30][38];

    public:

        /**
         * \brief : Constructeur par défaut de la classe Map,
         * coordonées dimx et dimy a modifier en meme temps que le fichier map.txt
         */
        Map();
        /**
         * \brief Charge les caractères du fichier map.txt dans la mapTable
         */
        void loadMapFromFile ();
        /**
         * \brief : Vérifie si la position passée en paramètre (caleurs entières) ne contient pas un caractère de mur ou de plateforme
         *
         * \param x : composante des abscisses
         * \param y : composante des ordonnées
         * \param taille: taille du "pixel" (optionnel)
         */
        bool isPosValid (int x, int y, int taille = 1) const;
        /**
         * \brief : Vérifie si la position passée en paramètre (classe coord) ne contient pas un caractère de mur ou de plateforme
         *
         * \param pos : coordonées de la position a vérifier
         * \param taille: taille du "pixel" (optionnel)
         */
        bool isPosValid (Coord& pos, int taille = 1) const;
        /**
         * \brief : Accesseur qui retourne la valeur stockée dans la mapTable aux coordonées passées en paramètres
         *
         * \param x : composante des abscisses
         * \param y : composante des ordonnées
         */
        char getXY (const int x, const int y) const;
        /**
         * \brief : Retourne la largeur de la map
         */
        int getDimX () const;
        /**
         * \brief : Retourne la hauteur de la map
         */
        int getDimY () const;

};

#endif
