#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include<stdbool.h>

typedef struct place {
    char lettre;
    int joueur;
    int couleur;
    char v1,v2,v3,v4;///voisins de chaque position sur la grille
}place;
typedef struct etat {
    place P[24];///le plateau du jeu
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

static int n = 0; ///pour calculer le nombre de noeuds

//////////////////////////fonction de couleur////////////////////////////////
void Color(int flags)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,(WORD)flags);
}
void color(int BackC, int ForgC)
{
    WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
/////////////////////////////////afiichage de la grille//////////////////////////////////
void afficher(etat e){
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("\n");
    printf("\t\t\t\t\t\t\t");
    color(e.P[0].couleur,15);
    printf(" %c ",e.P[0].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);

    printf("---------------------");
    color(e.P[1].couleur,15);
    printf(" %c ",e.P[1].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("----------------------");
    color(e.P[2].couleur,15);
    printf(" %c \n",e.P[2].lettre);
    color(0,15);


 Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
   printf("\t\t\t\t\t\t\t|                        |                         |\n");
    printf("\t\t\t\t\t\t\t|                        |                         |\n");
    printf("\t\t\t\t\t\t\t|                        |                         |\n");

    printf("\t\t\t\t\t\t\t|       ");
    color(e.P[3].couleur,15);
    printf(" %c ",e.P[3].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);

    printf("-------------");
    color(e.P[4].couleur,15);
    printf(" %c ",e.P[4].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("--------------");
    color(e.P[5].couleur,15);
    printf(" %c ",e.P[5].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("       |\n");


    printf("\t\t\t\t\t\t\t|       |                |                 |       |\n");
    printf("\t\t\t\t\t\t\t|       |                |                 |       |\n");

    printf("\t\t\t\t\t\t\t|       |     ");
    color(e.P[6].couleur,15);
    printf(" %c ",e.P[6].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("-------");
    color(e.P[7].couleur,15);
    printf(" %c ",e.P[7].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("-------");
    color(e.P[8].couleur,15);
    printf(" %c ",e.P[8].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("      |       |\n");


    printf("\t\t\t\t\t\t\t|       |      |    ___________    |       |       |\n");
    printf("\t\t\t\t\t\t\t|       |      |   |  ___      |   |       |       |\n");
    printf("\t\t\t\t\t\t\t|       |      |   | |   |  *  |   |       |       |\n");

    printf("\t\t\t\t\t\t       ");
    color(e.P[9].couleur,15);
    printf(" %c ",e.P[9].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("-----");
    color(e.P[10].couleur,15);
    printf(" %c ",e.P[10].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("----");
    color(e.P[11].couleur,15);
    printf(" %c ",e.P[11].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("  | |  ___ |  |  ");


    color(e.P[12].couleur,15);
    printf(" %c ",e.P[12].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("-----");
    color(e.P[13].couleur,15);
    printf(" %c ",e.P[13].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("-----");
    color(e.P[14].couleur,15);
    printf(" %c ",e.P[14].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("\n");

    printf("\t\t\t\t\t\t\t|       |      |   | |___|  |  |   |       |       |\n");
    printf("\t\t\t\t\t\t\t|       |      |   |___________|   |       |       |\n");
    printf("\t\t\t\t\t\t\t|       |      |                   |       |       |\n");

    printf("\t\t\t\t\t\t\t|       |     ");
    color(e.P[15].couleur,15);
    printf(" %c ",e.P[15].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("-------");
    color(e.P[16].couleur,15);
    printf(" %c ",e.P[16].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("-------");
    color(e.P[17].couleur,15);
    printf(" %c ",e.P[17].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("      |       |\n");

    printf("\t\t\t\t\t\t\t|       |                |                 |       |\n");
    printf("\t\t\t\t\t\t\t|       |                |                 |       |\n");

    printf("\t\t\t\t\t\t\t|       ");
    color(e.P[18].couleur,15);
    printf(" %c ",e.P[18].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("-------------");
    color(e.P[19].couleur,15);
    printf(" %c ",e.P[19].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("--------------");
    color(e.P[20].couleur,15);
    printf(" %c ",e.P[20].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("       |\n");

    printf("\t\t\t\t\t\t\t|                        |                         |\n");

    printf("\t\t\t\t\t\t\t|                        |                         |\n");
    printf("\t\t\t\t\t\t\t|                        |                         |\n");

    printf("\t\t\t\t\t\t\t");
    color(e.P[21].couleur,15);
    printf(" %c ",e.P[21].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("---------------------");
    color(e.P[22].couleur,15);
    printf(" %c ",e.P[22].lettre);
    color(0,15);
Color(FOREGROUND_GREEN|FOREGROUND_BLUE|FOREGROUND_INTENSITY);
    printf("----------------------");
    color(e.P[23].couleur,15);
    printf(" %c ",e.P[23].lettre);
    color(0,15);
    printf("\n\n");
}

///verifie s'il y a un moulin dans une position
int moulin_fnc(place *UnPlateau,int position ,int joueur)
{
    int moulin=-1;
    switch(position){
        case 0 : if((UnPlateau[9].joueur==joueur&&UnPlateau[21].joueur==joueur)||(UnPlateau[1].joueur==joueur&&UnPlateau[2].joueur==joueur)) moulin=0;break;
        case 1 : if((UnPlateau[7].joueur==joueur&&UnPlateau[4].joueur==joueur)||(UnPlateau[0].joueur==joueur&&UnPlateau[2].joueur==joueur)) moulin=0;break;
        case 2 : if((UnPlateau[14].joueur==joueur&&UnPlateau[23].joueur==joueur)||(UnPlateau[0].joueur==joueur&&UnPlateau[1].joueur==joueur)) moulin=0;break;
        case 3 : if((UnPlateau[10].joueur==joueur&&UnPlateau[18].joueur==joueur)||(UnPlateau[4].joueur==joueur&&UnPlateau[5].joueur==joueur)) moulin=0;break;
        case 4 : if((UnPlateau[1].joueur==joueur&&UnPlateau[7].joueur==joueur)||(UnPlateau[3].joueur==joueur&&UnPlateau[5].joueur==joueur)) moulin=0;break;
        case 5 : if((UnPlateau[13].joueur==joueur&&UnPlateau[20].joueur==joueur)||(UnPlateau[3].joueur==joueur&&UnPlateau[4].joueur==joueur)) moulin=0;break;
        case 6 : if((UnPlateau[11].joueur==joueur&&UnPlateau[15].joueur==joueur)||(UnPlateau[7].joueur==joueur&&UnPlateau[8].joueur==joueur)) moulin=0;break;
        case 7 : if((UnPlateau[1].joueur==joueur&&UnPlateau[4].joueur==joueur)||(UnPlateau[6].joueur==joueur&&UnPlateau[8].joueur==joueur)) moulin=0;break;
        case 8 : if((UnPlateau[12].joueur==joueur&&UnPlateau[17].joueur==joueur)||(UnPlateau[6].joueur==joueur&&UnPlateau[7].joueur==joueur)) moulin=0;break;
        case 9 : if((UnPlateau[0].joueur==joueur&&UnPlateau[21].joueur==joueur)||(UnPlateau[10].joueur==joueur&&UnPlateau[11].joueur==joueur)) moulin=0;break;
        case 10 : if((UnPlateau[3].joueur==joueur&&UnPlateau[18].joueur==joueur)||(UnPlateau[9].joueur==joueur&&UnPlateau[11].joueur==joueur)) moulin=0;break;
        case 11 : if((UnPlateau[6].joueur==joueur&&UnPlateau[15].joueur==joueur)||(UnPlateau[9].joueur==joueur&&UnPlateau[10].joueur==joueur)) moulin=0;break;
        case 12 : if((UnPlateau[8].joueur==joueur&&UnPlateau[17].joueur==joueur)||(UnPlateau[13].joueur==joueur&&UnPlateau[14].joueur==joueur)) moulin=0;break;
        case 13 : if((UnPlateau[5].joueur==joueur&&UnPlateau[20].joueur==joueur)||(UnPlateau[12].joueur==joueur&&UnPlateau[14].joueur==joueur)) moulin=0;break;
        case 14 : if((UnPlateau[2].joueur==joueur&&UnPlateau[23].joueur==joueur)||(UnPlateau[12].joueur==joueur&&UnPlateau[13].joueur==joueur)) moulin=0;break;
        case 15 : if((UnPlateau[6].joueur==joueur&&UnPlateau[11].joueur==joueur)||(UnPlateau[16].joueur==joueur&&UnPlateau[17].joueur==joueur)) moulin=0;break;
        case 16 : if((UnPlateau[19].joueur==joueur&&UnPlateau[22].joueur==joueur)||(UnPlateau[15].joueur==joueur&&UnPlateau[17].joueur==joueur)) moulin=0;break;
        case 17 : if((UnPlateau[8].joueur==joueur&&UnPlateau[12].joueur==joueur)||(UnPlateau[15].joueur==joueur&&UnPlateau[16].joueur==joueur)) moulin=0;break;
        case 18 : if((UnPlateau[3].joueur==joueur&&UnPlateau[10].joueur==joueur)||(UnPlateau[19].joueur==joueur&&UnPlateau[20].joueur==joueur)) moulin=0;break;
        case 19 : if((UnPlateau[16].joueur==joueur&&UnPlateau[22].joueur==joueur)||(UnPlateau[18].joueur==joueur&&UnPlateau[20].joueur==joueur)) moulin=0;break;
        case 20 : if((UnPlateau[5].joueur==joueur&&UnPlateau[13].joueur==joueur)||(UnPlateau[18].joueur==joueur&&UnPlateau[19].joueur==joueur)) moulin=0;break;
        case 21 : if((UnPlateau[0].joueur==joueur&&UnPlateau[9].joueur==joueur)||(UnPlateau[22].joueur==joueur&&UnPlateau[23].joueur==joueur)) moulin=0;break;
        case 22 : if((UnPlateau[16].joueur==joueur&&UnPlateau[19].joueur==joueur)||(UnPlateau[21].joueur==joueur&&UnPlateau[23].joueur==joueur)) moulin=0;break;
        case 23 : if((UnPlateau[2].joueur==joueur&&UnPlateau[14].joueur==joueur)||(UnPlateau[21].joueur==joueur&&UnPlateau[22].joueur==joueur)) moulin=0;break;
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

///trouver l'indice d'un pion sur la grille
int indice_pion(char c ,etat e)
{
    for (int i=0;i<24;i++)
        if (e.P[i].lettre==c)
            return i;
}

///vérifie s'il n'y a pas de mouvement pour Max
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

///vérifie s'il n'y a pas de mouvement pour Min
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

///main
int main()
{
    ///initialiser l'état initial
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

    ///9 pions our chaque joueur au début
    e.pos1=9;
    e.pos2=9;
    ///////////////////
    etat maxine;
    maxine = Minimax(e,4,0,1);
    afficher(maxine);
    printf("\nLe nombre de noeuds explores est : %d",n);
    return 0;
}
