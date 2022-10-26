#ifndef JOUER1_H
#define JOUER1_H
#include<stdbool.h>

#include "../include/struct.h"
int indice_pion(char c ,etat e);
int pas_de_mouvement1(etat c);
int pas_de_mouvement2(etat c);
void copier(etat source, etat *copie);
etat h(etat c);
etat Minimax(etat e , int p , int pions_a_placer, bool TourMax );
etat AlphaBeta(etat e, int p, int pions_a_placer, bool TourMax ,int a, int b);
int moulin_fnc(place *UnPlateau,int position ,int Pion);
int Voisinages(int source,int PositionTest,etat c, int joueur);
#endif // SDL2_H
