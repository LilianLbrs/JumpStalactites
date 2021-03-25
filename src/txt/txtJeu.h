#ifndef _TXTJEU_H
#define _TXTJEU_H

#include "../core/Jeu.h"

/**
 * \file txtJeu.h
 * \brief Module gérant l'affichage en mode texte du jeu
 * \version 0.1
 * \date 20/03/2021
 */

void txtAff(WinTXT & win, const Jeu & jeu);
void txtBoucle (Jeu & j);
void endGame (WinTXT & win, const Jeu & jeu);

#endif
