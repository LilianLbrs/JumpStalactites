#ifndef _COORD_H
#define _COORD_H

/**
 * \file Coord.h
 * \brief Module gérant les coordonnées des éléments du jeu
 * \version 1.0
 * \date 09/05/2021
 */

/**
 * \class Coord
 * \brief Classe gérant les coordonnées des éléments du jeu
 */
class Coord{
private:
    int position_X;
    int position_Y;

public:
    /**
     * \brief Constructeur par défaut de la classe coordonées
     */
    Coord();

    /**
     * \brief Constructeur qui initialise les valeurs coordonées
     *
     *\param posx : valeur des abscisses
     *\param posy : valeur en ordonnées (attention, axe des ordonnées inversé)
     */
    Coord(const int posx, const int posy);

    /**
     * \brief Constructeur par copie valeurs de la classe coordonnées
     *
     *\param pos : coordonées à copier
     */
    Coord(const Coord & pos);

    /**
     * \brief Accesseur qui retourne la valeur des abscisses
     */
    int getPosx() const;
    /**
     * \brief Accesseur qui retourne la valeur des ordonnées
     */
    int getPosy() const;
    /**
     * \brief Mutateur qui modifie les coordonnées avec les valeurs entières passées en paramètres
     *
     *\param posx : nouvelle valeur sur l'axe des abscisses
     * \param posy : nouvelle valeur sur l'axe des ordonnées
     */
    void setPos(const int posx, const int posy);
    /**
     * \brief Mutateur qui modifie les coordonées avec la valeur (classe Coord) passée en paramètre
     *
     * \param pos :  nouvelles coordonées
     */
    void setPos(const Coord& pos);
    /**
     * \brief Mutateur qui modifie la valeur des abscisses
     */
    void setPosx(const int posx);
    /**
     * \brief Mutateur qui modifie la valeur des ordonnées
     */
    void setPosy(const int posy);

};

#endif
