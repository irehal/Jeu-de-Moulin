#include <stdio.h>
#include <stdlib.h>
#include "../include/SDL2/SDL.h"
#include "../include/SDL2/SDL_image.h"
#include "../include/SDL2/SDL_mixer.h"
#include "../include/SDL2/SDL_ttf.h"
#include "../include/SDL2.h"
#include "../include/jouer.h"
#include "../include/struct.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


int main(int argc, char **argv)
{
    etat e;
    for (int i=0;i<24;i++){
        e.P[i].lettre='a'+i;
    }
    e.P[0].joueur=0;e.P[1].joueur=0;e.P[2].joueur=0;
    e.P[3].joueur=0;e.P[4].joueur=0;e.P[5].joueur=0;
    e.P[6].joueur=0;e.P[7].joueur=0;e.P[8].joueur=0;
    e.P[9].joueur=0;e.P[10].joueur=0;e.P[11].joueur=0;
    e.P[12].joueur=0;e.P[13].joueur=0;e.P[14].joueur=0;
    e.P[15].joueur=0;e.P[16].joueur=0;e.P[17].joueur=0;
    e.P[18].joueur=0;e.P[19].joueur=0;e.P[20].joueur=0;
    e.P[21].joueur=0;e.P[22].joueur=0;e.P[23].joueur=0;
    //couleur des joueurs
    for (int i=0 ; i<24 ; i++ ){
        if(e.P[i].joueur == 1){
            e.P[i].couleur = 9;
        }else if( e.P[i].joueur == 2){
            e.P[i].couleur = 12;
        }else{
            e.P[i].couleur=0;
        }
    }
    //voisins
    e.P[0].v1='b';e.P[0].v2='j';e.P[0].v3='&';e.P[0].v4='&';
    e.P[1].v1='a';e.P[1].v2='c';e.P[1].v3='e';e.P[1].v4='&';
    e.P[2].v1='b';e.P[2].v2='o';e.P[2].v3='&';e.P[2].v4='&';
    e.P[3].v1='e';e.P[3].v2='k';e.P[3].v3='&';e.P[3].v4='&';
    e.P[4].v1='b';e.P[4].v2='d';e.P[4].v3='f';e.P[4].v4='h';
    e.P[5].v1='e';e.P[5].v2='n';e.P[5].v3='&';e.P[5].v4='&';
    e.P[6].v1='h';e.P[6].v2='l';e.P[6].v3='&';e.P[6].v4='&';
    e.P[7].v1='g';e.P[7].v2='e';e.P[7].v3='i';e.P[7].v4='&';
    e.P[8].v1='h';e.P[8].v2='m';e.P[8].v3='&';e.P[9].v4='&';
    e.P[9].v1='a';e.P[9].v2='k';e.P[9].v3='v';e.P[9].v4='&';
    e.P[10].v1='j';e.P[10].v2='d';e.P[10].v3='l';e.P[10].v4='s';
    e.P[11].v1='k';e.P[11].v2='g';e.P[11].v3='p';e.P[11].v4='&';
    e.P[12].v1='i';e.P[12].v2='n';e.P[12].v3='r';e.P[12].v4='&';
    e.P[13].v1='m';e.P[13].v2='f';e.P[13].v3='o';e.P[13].v4='u';
    e.P[14].v1='n';e.P[14].v2='c';e.P[14].v3='x';e.P[14].v4='&';
    e.P[15].v1='l';e.P[15].v2='q';e.P[15].v3='&';e.P[15].v4='&';
    e.P[16].v1='p';e.P[16].v2='r';e.P[16].v3='t';e.P[16].v4='&';
    e.P[17].v1='q';e.P[17].v2='m';e.P[17].v3='&';e.P[17].v4='&';
    e.P[18].v1='k';e.P[18].v2='t';e.P[18].v3='&';e.P[18].v4='&';
    e.P[19].v1='s';e.P[19].v2='q';e.P[19].v3='u';e.P[19].v4='w';
    e.P[20].v1='t';e.P[20].v2='n';e.P[20].v3='&';e.P[20].v4='&';
    e.P[21].v1='j';e.P[21].v2='w';e.P[21].v3='&';e.P[21].v4='&';
    e.P[22].v1='v';e.P[22].v2='t';e.P[22].v3='x';e.P[22].v4='&';
    e.P[23].v1='w';e.P[23].v2='o';e.P[23].v3='&';e.P[23].v4='&';

    e.pos1=9;
    e.pos2=9;

    SDLmain(e);
    return 0;
}
