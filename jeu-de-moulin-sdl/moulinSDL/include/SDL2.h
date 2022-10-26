#ifndef SDL2_H
#define SDL2_H

#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/SDL2/SDL_mixer.h"
#include "../include/SDL2/SDL_ttf.h"

#include "../include/struct.h"

void SDL_Inialiser();
void SDLmain(etat e);
int entrer_utilisateur(int Joueur,etat e);
void afficher();
int Nbr_des_pions_poser;

#endif // SDL2_H
