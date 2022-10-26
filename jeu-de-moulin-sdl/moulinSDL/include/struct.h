#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED


typedef struct place {
    char lettre;
    int joueur;
    int couleur;
    char v1,v2,v3,v4;///voisins de chaque position sur la grille
}place;
typedef struct etat {
    place P[24];
    int pos1; ///nombre de pions sur table
    int pos2;
    int ce; ///cout de chaque etat
    int pos;///position de chaque pion
    int presd;
    int pC;///pion capture de l'adversaire

}etat;
typedef struct Noeud
{
    struct Noeud *suivant;
    etat Etat;
}Noeud;

static int n = 0;

#endif // STRUCT_H_INCLUDED



