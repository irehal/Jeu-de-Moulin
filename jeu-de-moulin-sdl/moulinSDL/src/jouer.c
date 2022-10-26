#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<stdbool.h>

#include "../include/struct.h"
///trouver l'indice d'un pion sur la grille
int indice_pion(char c ,etat e)
{
    for (int i=0;i<24;i++)
        if (e.P[i].lettre==c)
            return i;
}

///vérifie s'il n'y a pas de mouvement pour la machine
int pas_de_mouvement1(etat c){
    int i;
    int t1 = 0;
    for (i=0;i<24;i++){
        if (c.P[i].joueur==1){
            //int indice pion(char c);
            //la fonction donne l'indice de la case portant le caractere entree en indice.
            if ((c.P[indice_pion(c.P[i].v1 , c)].joueur!=0) && (c.P[indice_pion(c.P[i].v2,c)].joueur!=0))
            {
                if ((c.P[i].v3=='&') && (c.P[i].v4=='&')) t1++;
                if ((c.P[i].v3!='&') && (c.P[i].v4=='&')){if (c.P[indice_pion(c.P[i].v3,c)].joueur!=0) t1++;}
                if ((c.P[i].v3!='&') && (c.P[i].v4!='&')){if ((c.P[indice_pion(c.P[i].v3,c)].joueur!=0) && (c.P[indice_pion(c.P[i].v4,c)].joueur!=0)) t1++;}
                //la variable v1 signifie le nombre de pions bloqués pour le joueur 1
            }
        }
    }

    if (t1==c.pos1 ) {return 1;}else{return 0;}

}

///vérifie s'il n'y a pas de mouvement pour le joueur
int pas_de_mouvement2(etat c){
    int i;
    int t2 = 0;
    for (i=0;i<24;i++){
     if (c.P[i].joueur==2){
            if ((c.P[indice_pion(c.P[i].v1,c)].joueur!=0) && (c.P[indice_pion(c.P[i].v2,c)].joueur!=0))
            {
                if ((c.P[i].v3=='&') && (c.P[i].v4=='&')) t2++;
                if ((c.P[i].v3!='&') && (c.P[i].v4=='&')){if (c.P[indice_pion(c.P[i].v3,c)].joueur!=0) t2++;}
                if ((c.P[i].v3!='&') && (c.P[i].v4!='&')){if ((c.P[indice_pion(c.P[i].v3,c)].joueur!=0) && (c.P[indice_pion(c.P[i].v4,c)].joueur!=0)) t2++;}
                //la variable v2 signifie le nombre de pions restants pour le joueur 2

            }
        }
    }
    if (t2==c.pos2 ) {return 1;}else{return 0;}

}

///copier un etat dans un autre etat
void copier(etat source, etat *copie)
{
    copie->pC=source.pC;
    copie->presd=source.pC;
    copie->ce=source.ce;
    copie->pos=source.pos;
    copie->pos1=source.pos1;
    copie->pos2=source.pos2;
    for(int i=0; i<24 ;i++){
        copie->P[i].joueur=source.P[i].joueur;
        copie->P[i].couleur= source.P[i].couleur;
        copie->P[i].lettre = source.P[i].lettre;
        copie->P[i].v1=source.P[i].v1;
        copie->P[i].v2=source.P[i].v2;
        copie->P[i].v3=source.P[i].v3;
        copie->P[i].v4=source.P[i].v1;
    }
    /*for(int i=0;i<16;i++)
    {
        copie->M[i].j=source.M[i].j;
        copie->M[i].p1=source.M[i].p1;
        copie->M[i].p2=source.M[i].p2;
        copie->M[i].p3=source.M[i].p3;
    }*/
}

///la fonction heuristique
etat h(etat c)
{
    int nb1=0,nb2=0;
    for(int i=0; i<24 ; i++)
    {
        if(c.P[i].joueur==1)nb1++;
        if(c.P[i].joueur==2)nb2++;
        if(c.P[i].joueur==0&&moulin_fnc(c.P,i,1)==0)nb1+=3;
        if(c.P[i].joueur==0&&moulin_fnc(c.P,i,2)==0)nb2+=3;
        if(moulin_fnc(c.P,i,1)==0)nb1+=10;
        if(moulin_fnc(c.P,i,2)==0)nb2+=10;
    }
    c.ce=nb1-nb2;
    return c;
}

///La stratégie Minimax
etat Minimax(etat e, int p, int pions_a_placer, bool TourMax )
{
    if( p<=0)
    {
        return h(e);
    }
    if(pions_a_placer >18)
    {
        if( pas_de_mouvement1(e) ||e.pos1 ==2)
        {
            e.ce = -1000;
            return e;
        }
        if( pas_de_mouvement2(e) || e.pos2 ==2)
        {
            e.ce = 1000;
            return e;
        }
    }
    if(TourMax)
    {
        p--;
        pions_a_placer++;
        etat eMax;
        copier(e,&eMax) ;
        eMax.ce = -100000;
        eMax.pC=-1;
        if(pions_a_placer <= 18 )
        {
            for ( int i=0 ; i<24 ; i++)
            {
                if(e.P[i].joueur==0)
                {
                    n++;
                    etat eCourant;
                    etat eAide;
                    copier(e, &eCourant);
                    eCourant.P[i].joueur=1;
                    eCourant.P[i].couleur = 9;
                    eCourant.pos = i ;
                    eCourant.pC=-1;
                    if( moulin_fnc(eCourant.P,eCourant.pos ,1)==0)
                    {
                        for(int j=0; j<24 ; j++)
                        {
                            if(e.P[j].joueur == 2 && !( moulin_fnc(eCourant.P,j ,2)==0) )
                            {
                                n++;
                                eCourant.P[j].joueur = 0;
                                eCourant.P[j].couleur = 0;
                                e.pos2--;
                                eAide = Minimax(eCourant,p-1, pions_a_placer -1, !TourMax);
                                eAide.pC = j;
                                eAide.pos = i ;
                            }
                        }
                    }
                    else
                    {
                        eAide = Minimax(eCourant, p, pions_a_placer, !TourMax );
                        eAide.pos = i ;
                        eAide.pC = -1;
                    }
                    if(eMax.ce < eAide.ce)
                    {
                        eMax.ce  = eAide.ce;
                        eMax.pos = i;
                        eMax.pC= eAide.pC;
                    }
                }
            }
            return eMax;
        }
        else
        {
            for(int k=0 ; k<24 ; k++)
            {
                if(e.P[k].joueur==1){
                    for(int i = 0 ; i<24; i++)
                    {
                        if(Voisinages(k,i,e,1)==0&&e.P[i].joueur==0)
                        {
                            n++;
                            etat eCourant;
                            etat eAide;
                            copier(e, &eCourant);
                            eCourant.P[k].joueur = 0;
                            eCourant.P[k].couleur = 0;
                            eCourant.P[i].joueur = 1;
                            eCourant.P[i].couleur = 9;
                            eCourant.pos = i ;
                            eCourant.presd = k;
                            eCourant.pC=-1;
                            if(moulin_fnc(eCourant.P,eCourant.pos ,1)==0)
                            {
                                for( int j = 0 ; j<24 ; j++)
                                {
                                    if(e.P[j].joueur == 2 && !( moulin_fnc(eCourant.P,j ,2)==0) )
                                    {
                                        n++;
                                        eCourant.P[j].joueur = 0;
                                        eCourant.P[j].couleur = 0;
                                        eCourant.pos2--;
                                        eAide = Minimax(eCourant,p-1, pions_a_placer -1, !TourMax);
                                        eAide.pC = j;
                                        eAide.pos = i ;
                                    }
                                }
                            }
                            else
                            {
                                eAide = Minimax(eCourant, p, pions_a_placer, !TourMax );
                                eAide.pos = i ;
                                eAide.pC = -1;
                            }
                            if(eMax.ce < eAide.ce)
                            {
                                eMax.ce  = eAide.ce;
                                eMax.pos = i;
                                eMax.presd = k ;
                                eMax.pC= eAide.pC;
                            }
                        }
                    }
                }

            }
            return eMax;
        }
    }
    else
    {
        p--;
        pions_a_placer++;
        etat eMin;
        copier(e,&eMin) ;
        eMin.ce = 100000;
        eMin.pC=-1;
        if(pions_a_placer <= 18 )
        {
            for ( int i=0 ; i<24 ; i++)
            {
                if(e.P[i].joueur==0)
                {
                    n++;
                    etat eCourant;
                    etat eAide;
                    copier(e, &eCourant);
                    eCourant.P[i].joueur=2;
                    eCourant.P[i].couleur = 12;
                    eCourant.pos = i ;
                    eCourant.pC=-1;
                    if( moulin_fnc(eCourant.P,eCourant.pos ,2)==0)
                    {
                        for(int j=0; j<24 ; j++)
                        {
                            if(e.P[j].joueur == 1 && !( moulin_fnc(eCourant.P,j ,1)==0) )
                            {
                                n++;
                                eCourant.P[j].joueur = 0;
                                eCourant.P[j].couleur = 0;
                                eCourant.pos1--;
                                eAide = Minimax(eCourant,p-1, pions_a_placer -1, !TourMax);
                                eAide.pC = j;
                                eAide.pos = i ;
                            }
                        }
                    }
                    else
                    {
                        eAide = Minimax(eCourant, p, pions_a_placer, !TourMax );
                        eAide.pos = i ;
                        eAide.pC = -1;
                    }
                    if(eMin.ce > eAide.ce)
                    {
                        eMin.ce  = eAide.ce;
                        eMin.pos = i;
                        eMin.pC= eAide.pC;
                    }
                }
            }
            return eMin;
        }
        else
        {
            for(int k=0 ; k<24 ; k++)
            {
                if(e.P[k].joueur==2){
                    for(int i = 0 ; i<24; i++)
                    {
                        if(Voisinages(k,i,e,2)==0&&e.P[i].joueur==0)
                        {
                            n++;
                            etat eCourant;
                            etat eAide;
                            copier(e, &eCourant);
                            eCourant.P[k].joueur = 0;
                            eCourant.P[k].couleur = 0;
                            eCourant.P[i].joueur = 2;
                            eCourant.P[i].couleur = 12;
                            eCourant.pos = i ;
                            eCourant.presd = k;
                            eCourant.pC=-1;
                            if(moulin_fnc(eCourant.P,eCourant.pos ,2)==0)
                            {
                                for( int j = 0 ; j<24 ; j++)
                                {
                                    if(e.P[j].joueur == 1 && !( moulin_fnc(eCourant.P,j ,1)==0) )
                                    {
                                        n++;
                                        eCourant.P[j].joueur = 0;
                                        eCourant.P[j].couleur = 0;
                                        eCourant.pos1--;
                                        eAide = Minimax(eCourant,p-1, pions_a_placer -1, !TourMax);
                                        eAide.pC = j;
                                        eAide.pos = i ;
                                    }
                                }
                            }
                            else
                            {
                                eAide = Minimax(eCourant, p, pions_a_placer, !TourMax );
                                eAide.pos = i ;
                                eAide.pC = -1;
                            }
                            if(eMin.ce > eAide.ce)
                            {
                                eMin.ce  = eAide.ce;
                                eMin.pos = i;
                                eMin.presd = k ;
                                eMin.pC= eAide.pC;
                            }
                        }
                    }
                }

            }
            return eMin;
        }
    }
}

///La stratégie AlphaBeta
etat AlphaBeta(etat e, int p, int pions_a_placer, bool TourMax ,int a, int b)
{
    if( p<=0)
    {
        return h(e);
    }
    if(pions_a_placer >18)
    {
        if( pas_de_mouvement1(e) ||e.pos1 ==2)
        {
            e.ce = -1000;
            return e;
        }
        if( pas_de_mouvement2(e) || e.pos2 ==2)
        {
            e.ce = 1000;
            return e;
        }
    }
    if(TourMax)
    {
        p--;
        pions_a_placer++;
        etat eMax;
        copier(e,&eMax) ;
        eMax.ce = -100000;
        eMax.pC=-1;
        if(pions_a_placer <= 18 )
        {
            for ( int i=0 ; i<24 ; i++)
            {
                if(e.P[i].joueur==0)
                {
                    n++;
                    etat eCourant;
                    etat eAide;
                    copier(e, &eCourant);
                    eCourant.P[i].joueur=1;
                    eCourant.P[i].couleur = 9;
                    eCourant.pos = i ;
                    if( moulin_fnc(eCourant.P,eCourant.pos ,1)==0)
                    {
                        for(int j=0; j<24 ; j++)
                        {
                            if(e.P[j].joueur == 2 && !( moulin_fnc(eCourant.P,j ,2)==0) )
                            {
                                n++;
                                eCourant.P[j].joueur = 0;
                                eCourant.P[j].couleur = 0;
                                e.pos2--;
                                eAide = AlphaBeta(eCourant,p-1, pions_a_placer -1, !TourMax, a, b);
                                eAide.pC = j;
                                eAide.pos = i ;
                            }
                        }
                    }
                    else
                    {
                        eAide = AlphaBeta(eCourant, p, pions_a_placer, !TourMax, a, b);
                        eAide.pos = i ;
                        eAide.pC = -1;
                    }
                    if(eMax.ce < eAide.ce)
                    {
                        eMax.ce  = eAide.ce;
                        eMax.pos = i;
                        eMax.pC= eAide.pC;
                    }
                    if( a < eAide.ce)
                        a = eAide.ce;
                    if( a >= b)
                        i=25;
                }
            }
            return eMax;
        }
        else
        {
            for(int k=0 ; k<24 ; k++)
            {
                if(e.P[k].joueur==1){
                    for(int i = 0 ; i<24; i++)
                    {
                        if(Voisinages(k,i,e,1)==0&&e.P[i].joueur==0)
                        {
                            n++;
                            etat eCourant;
                            etat eAide;
                            copier(e, &eCourant);
                            eCourant.P[k].joueur = 0;
                            eCourant.P[k].couleur = 0;
                            eCourant.P[i].joueur = 1;
                            eCourant.P[i].couleur = 9;
                            eCourant.pos = i ;
                            eCourant.presd = k;
                            if(moulin_fnc(eCourant.P,eCourant.pos ,1)==0)
                            {
                                for( int j = 0 ; j<24 ; j++)
                                {
                                    if(e.P[j].joueur == 2 && !( moulin_fnc(eCourant.P,j ,2)==0) )
                                    {
                                        n++;
                                        eCourant.P[j].joueur = 0;
                                        eCourant.P[j].couleur = 0;
                                        eCourant.pos2--;
                                        eAide = AlphaBeta(eCourant,p-1, pions_a_placer -1, !TourMax, a, b);
                                        eAide.pC = j;
                                        eAide.pos = i ;
                                    }
                                }
                            }
                            else
                            {
                                eAide = AlphaBeta(eCourant, p, pions_a_placer, !TourMax, a, b);
                                eAide.pos = i ;
                                eAide.pC = -1;
                            }
                            if(eMax.ce < eAide.ce)
                            {
                                eMax.ce  = eAide.ce;
                                eMax.pos = i;
                                eMax.presd = k ;
                                eMax.pC= eAide.pC;
                            }
                            if( a < eAide.ce)
                                a = eAide.ce;
                            if( a >= b)
                                i=25;
                        }
                    }
                }

            }
            return eMax;
        }
    }
    else
    {
        p--;
        pions_a_placer++;
        etat eMin;
        copier(e,&eMin) ;
        eMin.ce = 100000;
        eMin.pC=-1;
        if(pions_a_placer <= 18 )
        {
            for ( int i=0 ; i<24 ; i++)
            {
                if(e.P[i].joueur==0)
                {
                    n++;
                    etat eCourant;
                    etat eAide;
                    copier(e, &eCourant);
                    eCourant.P[i].joueur=2;
                    eCourant.P[i].couleur = 12;
                    eCourant.pos = i ;
                    if(moulin_fnc(eCourant.P,eCourant.pos ,2)==0)
                    {
                        for(int j=0; j<24 ; j++)
                        {
                            if(e.P[j].joueur == 1 && !( moulin_fnc(eCourant.P,j ,1)==0) )
                            {
                                n++;
                                eCourant.P[j].joueur = 0;
                                eCourant.P[j].couleur = 0;
                                eCourant.pos1--;
                                eAide = AlphaBeta(eCourant,p-1, pions_a_placer -1, !TourMax, a, b);
                                eAide.pC = j;
                                eAide.pos = i ;
                            }
                        }
                    }
                    else
                    {
                        eAide = AlphaBeta(eCourant, p, pions_a_placer, !TourMax, a, b);
                        eAide.pos = i ;
                        eAide.pC = -1;
                    }
                    if(eMin.ce > eAide.ce)
                    {
                        eMin.ce  = eAide.ce;
                        eMin.pos = i;
                        eMin.pC= eAide.pC;
                    }
                    if( b > eAide.ce)
                        b = eAide.ce;
                    if( a >= b)
                        i=25;
                }
            }
            return eMin;
        }
        else
        {
            for(int k=0 ; k<24 ; k++)
            {
                if(e.P[k].joueur==2){
                    for(int i = 0 ; i<24; i++)
                    {
                        if(Voisinages(k,i,e,2)==0&&e.P[i].joueur==0)
                        {
                            n++;
                            etat eCourant;
                            etat eAide;
                            copier(e, &eCourant);
                            eCourant.P[k].joueur = 0;
                            eCourant.P[k].couleur = 0;
                            eCourant.P[i].joueur = 2;
                            eCourant.P[i].couleur = 12;
                            eCourant.pos = i ;
                            eCourant.presd = k;
                            if(moulin_fnc(eCourant.P,eCourant.pos ,2)==0)
                            {
                                for( int j = 0 ; j<24 ; j++)
                                {
                                    if(e.P[j].joueur == 1 && !( moulin_fnc(eCourant.P,j ,1)==0) )
                                    {
                                        n++;
                                        eCourant.P[j].joueur = 0;
                                        eCourant.P[j].couleur = 0;
                                        eCourant.pos1--;
                                        eAide = AlphaBeta(eCourant,p-1, pions_a_placer -1, !TourMax, a, b);
                                        eAide.pC = j;
                                        eAide.pos = i ;
                                    }
                                }
                            }
                            else
                            {
                                eAide = AlphaBeta(eCourant, p, pions_a_placer, !TourMax, a, b);
                                eAide.pos = i ;
                                eAide.pC = -1;
                            }
                            if(eMin.ce > eAide.ce)
                            {
                                eMin.ce  = eAide.ce;
                                eMin.pos = i;
                                eMin.presd = k ;
                                eMin.pC= eAide.pC;
                            }
                            if( b > eAide.ce)
                                b = eAide.ce;
                            if( a >= b)
                                i=25;
                        }
                    }
                }

            }
            return eMin;
        }
    }
}


///verifie s'il y a un moulin dans une position
int moulin_fnc(place *UnPlateau,int position ,int Pion)
{
    int moulin=-1;
    switch(position){
        case 0 : if((UnPlateau[9].joueur==Pion&&UnPlateau[21].joueur==Pion)||(UnPlateau[1].joueur==Pion&&UnPlateau[2].joueur==Pion)) moulin=0;break;
        case 1 : if((UnPlateau[7].joueur==Pion&&UnPlateau[4].joueur==Pion)||(UnPlateau[0].joueur==Pion&&UnPlateau[2].joueur==Pion)) moulin=0;break;
        case 2 : if((UnPlateau[14].joueur==Pion&&UnPlateau[23].joueur==Pion)||(UnPlateau[0].joueur==Pion&&UnPlateau[1].joueur==Pion)) moulin=0;break;
        case 3 : if((UnPlateau[10].joueur==Pion&&UnPlateau[18].joueur==Pion)||(UnPlateau[4].joueur==Pion&&UnPlateau[5].joueur==Pion)) moulin=0;break;
        case 4 : if((UnPlateau[1].joueur==Pion&&UnPlateau[7].joueur==Pion)||(UnPlateau[3].joueur==Pion&&UnPlateau[5].joueur==Pion)) moulin=0;break;
        case 5 : if((UnPlateau[13].joueur==Pion&&UnPlateau[20].joueur==Pion)||(UnPlateau[3].joueur==Pion&&UnPlateau[4].joueur==Pion)) moulin=0;break;
        case 6 : if((UnPlateau[11].joueur==Pion&&UnPlateau[15].joueur==Pion)||(UnPlateau[7].joueur==Pion&&UnPlateau[8].joueur==Pion)) moulin=0;break;
        case 7 : if((UnPlateau[1].joueur==Pion&&UnPlateau[4].joueur==Pion)||(UnPlateau[6].joueur==Pion&&UnPlateau[8].joueur==Pion)) moulin=0;break;
        case 8 : if((UnPlateau[12].joueur==Pion&&UnPlateau[17].joueur==Pion)||(UnPlateau[6].joueur==Pion&&UnPlateau[7].joueur==Pion)) moulin=0;break;
        case 9 : if((UnPlateau[0].joueur==Pion&&UnPlateau[21].joueur==Pion)||(UnPlateau[10].joueur==Pion&&UnPlateau[11].joueur==Pion)) moulin=0;break;
        case 10 : if((UnPlateau[3].joueur==Pion&&UnPlateau[18].joueur==Pion)||(UnPlateau[9].joueur==Pion&&UnPlateau[11].joueur==Pion)) moulin=0;break;
        case 11 : if((UnPlateau[6].joueur==Pion&&UnPlateau[15].joueur==Pion)||(UnPlateau[9].joueur==Pion&&UnPlateau[10].joueur==Pion)) moulin=0;break;
        case 12 : if((UnPlateau[8].joueur==Pion&&UnPlateau[17].joueur==Pion)||(UnPlateau[13].joueur==Pion&&UnPlateau[14].joueur==Pion)) moulin=0;break;
        case 13 : if((UnPlateau[5].joueur==Pion&&UnPlateau[20].joueur==Pion)||(UnPlateau[12].joueur==Pion&&UnPlateau[14].joueur==Pion)) moulin=0;break;
        case 14 : if((UnPlateau[2].joueur==Pion&&UnPlateau[23].joueur==Pion)||(UnPlateau[12].joueur==Pion&&UnPlateau[13].joueur==Pion)) moulin=0;break;
        case 15 : if((UnPlateau[6].joueur==Pion&&UnPlateau[11].joueur==Pion)||(UnPlateau[16].joueur==Pion&&UnPlateau[17].joueur==Pion)) moulin=0;break;
        case 16 : if((UnPlateau[19].joueur==Pion&&UnPlateau[22].joueur==Pion)||(UnPlateau[15].joueur==Pion&&UnPlateau[17].joueur==Pion)) moulin=0;break;
        case 17 : if((UnPlateau[8].joueur==Pion&&UnPlateau[12].joueur==Pion)||(UnPlateau[15].joueur==Pion&&UnPlateau[16].joueur==Pion)) moulin=0;break;
        case 18 : if((UnPlateau[3].joueur==Pion&&UnPlateau[10].joueur==Pion)||(UnPlateau[19].joueur==Pion&&UnPlateau[20].joueur==Pion)) moulin=0;break;
        case 19 : if((UnPlateau[16].joueur==Pion&&UnPlateau[22].joueur==Pion)||(UnPlateau[18].joueur==Pion&&UnPlateau[20].joueur==Pion)) moulin=0;break;
        case 20 : if((UnPlateau[5].joueur==Pion&&UnPlateau[13].joueur==Pion)||(UnPlateau[18].joueur==Pion&&UnPlateau[19].joueur==Pion)) moulin=0;break;
        case 21 : if((UnPlateau[0].joueur==Pion&&UnPlateau[9].joueur==Pion)||(UnPlateau[22].joueur==Pion&&UnPlateau[23].joueur==Pion)) moulin=0;break;
        case 22 : if((UnPlateau[16].joueur==Pion&&UnPlateau[19].joueur==Pion)||(UnPlateau[21].joueur==Pion&&UnPlateau[23].joueur==Pion)) moulin=0;break;
        case 23 : if((UnPlateau[2].joueur==Pion&&UnPlateau[14].joueur==Pion)||(UnPlateau[21].joueur==Pion&&UnPlateau[22].joueur==Pion)) moulin=0;break;
    }
    return moulin;
}

///retourne 1 si un joueur a une possibilité de déplacer dans la grille et 0 sinon
int Voisinages(int source,int PositionTest,etat c,int joueur)
{
    switch(source){
        case 0 : if(PositionTest==1||PositionTest==9)return 0;break;
        case 1 : if(PositionTest==0||PositionTest==2||PositionTest==4)return 0;break;
        case 2 : if(PositionTest==1||PositionTest==14)return 0;break;
        case 3 : if(PositionTest==4||PositionTest==10)return 0;break;
        case 4 : if(PositionTest==1||PositionTest==3||PositionTest==5||PositionTest==7)return 0;break;
        case 5 : if(PositionTest==4||PositionTest==13)return 0;break;
        case 6 : if(PositionTest==7||PositionTest==11)return 0;break;
        case 7 : if(PositionTest==4||PositionTest==6||PositionTest==8)return 0;break;
        case 8 : if(PositionTest==7||PositionTest==12)return 0;break;
        case 9 : if(PositionTest==0||PositionTest==10||PositionTest==21)return 0;break;
        case 10 : if(PositionTest==3||PositionTest==9||PositionTest==11||PositionTest==18)return 0;break;
        case 11 : if(PositionTest==6||PositionTest==10||PositionTest==15)return 0;break;
        case 12 : if(PositionTest==8||PositionTest==13||PositionTest==17)return 0;break;
        case 13 : if(PositionTest==5||PositionTest==12||PositionTest==14||PositionTest==20)return 0;break;
        case 14 : if(PositionTest==2||PositionTest==13||PositionTest==23)return 0;break;
        case 15 : if(PositionTest==11||PositionTest==16)return 0;break;
        case 16 : if(PositionTest==15||PositionTest==17||PositionTest==19)return 0;break;
        case 17 : if(PositionTest==12||PositionTest==16)return 0;break;
        case 18 : if(PositionTest==10||PositionTest==19)return 0;break;
        case 19 : if(PositionTest==16||PositionTest==18||PositionTest==20||PositionTest==22)return 0;break;
        case 20 : if(PositionTest==13||PositionTest==19)return 0;break;
        case 21 : if(PositionTest==9||PositionTest==22)return 0;break;
        case 22 : if(PositionTest==19||PositionTest==21||PositionTest==23)return 0;break;
        case 23 : if(PositionTest==14||PositionTest==22)return 0;break;

    }
    if(joueur==1){
        if(c.pos1<=3)return 0;
    }
    if(joueur==2){
        if(c.pos2<=3)return 0;
    }
    return -1;
}

int pion_libre(place *UnPlateau)
{
    int Choix=-1;
        for(int i=0 ;i<24 ;i++){
            if(UnPlateau[i].joueur==1)
            if(moulin_fnc(UnPlateau,i,1)==-1){
                Choix=0;
                i=24;
            }
        }
        if(Choix==-1) {
            printf("l'adversaire n'a que des moulin, vous pouver pas capturer un pion");
        }
        return Choix;
}
