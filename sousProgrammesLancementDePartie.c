#include "headersMenu.h"

void lancementPartie(BITMAP* lancement, BITMAP* regles, BITMAP* options, BITMAP* conception, BITMAP*  buffer, BITMAP* image, BITMAP* fond, BITMAP* pageJeu)
{
    int a=0;
    int N;
    int choix=0;
    int saisie=0;

    char *nomsJoueurs;

    clear(buffer);
    blit(lancement,buffer,0,0,0,0,800,600);
    rectfill(buffer, 700, 570, 790, 590, blanc);
    textprintf_ex(buffer, font, 700, 575, marron,-1, "%s", "RETOUR MENU");

    while(a!=1)
    {
        textprintf_ex(buffer, font, 415, 95, marron,-1, "%s", "Veuillez-choisir le nombre de joueurs :");


        if(((mouse_x>=450)&&(mouse_x<=470))&&((mouse_y>=120)&&(mouse_y<=125))&&(choix==0))
        {
            rectfill(buffer, 450, 120, 470, 130, marron);
            textprintf_ex(buffer, font, 457, 122, blanc,-1, "%s", "2");
            blit(buffer,screen,0,0,0,0,800,600);
            if(mouse_b &1)
            {
                N=2;
                printf("le nombre de joueurs pour cette partie est de : %d ", N);
                choix=1;
                rest(30);
            }
        }
        else
        {
            if(((mouse_x>=480)&&(mouse_x<=500))&&((mouse_y>=120)&&(mouse_y<=125))&&(choix==0))
            {
                rectfill(buffer, 480, 120, 500, 130, marron);
                textprintf_ex(buffer, font, 487, 122, blanc,-1, "%s", "3");
                blit(buffer,screen,0,0,0,0,800,600);
                if(mouse_b &1)
                {
                    N=3;
                    printf("le nombre de joueurs pour cette partie est de : %d ", N);
                    choix=1;
                    rest(30);
                }
            }
            else
            {
                if(((mouse_x>=510)&&(mouse_x<=530))&&((mouse_y>=120)&&(mouse_y<=125))&&(choix==0))
                {
                    rectfill(buffer, 510, 120, 530, 130, marron);
                    textprintf_ex(buffer, font, 517, 122, blanc,-1, "%s", "4");
                    blit(buffer,screen,0,0,0,0,800,600);
                    if(mouse_b &1)
                    {
                        N=4;
                        printf("le nombre de joueurs pour cette partie est de : %d ", N);
                        choix=1;
                        rest(30);
                    }
                }
                else
                {
                    rectfill(buffer, 450, 120, 470, 130, blanc);
                    textprintf_ex(buffer, font, 457, 122, marron,-1, "%s", "2");
                    rectfill(buffer, 480, 120, 500, 130, blanc);
                    textprintf_ex(buffer, font, 487, 122, marron,-1, "%s", "3");
                    rectfill(buffer, 510, 120, 530, 130, blanc);
                    textprintf_ex(buffer, font, 517, 122, marron,-1, "%s", "4");

                    blit(buffer,screen,0,0,0,0,800,600);
                }
            }
        }
        a=test1(lancement, regles, options, conception, buffer, image, fond,pageJeu);
        if(a==1)
        {
            clear(buffer);
            affichageDeBase(fond, buffer);
        }

        if(choix==1)
        {
            nomsJoueurs=(char*)malloc(N*sizeof(char*));
            textprintf_ex(buffer, font, 415, 140, marron,-1, "%s", "Veuillez suivre les instructions sur ");
            textprintf_ex(buffer, font,415,150,marron,-1,"%s","la fenetre de commande : ");
            blit(buffer,screen,0,0,0,0,800,600);
            printf("\n");
            for(int i=0 ; i<N ; i++)
            {
                printf("saisir le nom du %d e joueur : ", i+1);
                fflush(stdin);
                scanf("%s", &nomsJoueurs[i]);
            }
            printf("\nLES NOMS DES JOUEURS SONT :\n");
            for(int j=0 ; j<N ; j++)
            {
                printf("- %c\n", nomsJoueurs[j]);

            }
            printf("\n----------NOMS DES JOUEURS ENREGISTRES----------\n");
            printf("retour sur la fenetre de jeu\n");
            saisie=1;
        }

        if(saisie==1)
        {
            rectfill(buffer, 415, 200, 700, 230, blanc);
            textprintf_ex(buffer, font, 442, 215, marron,-1, "%s", "APPUYER POUR DEBUTER LA PARTIE");
            blit(buffer,screen,0,0,0,0,800,600);

            a=test1(lancement, regles, options, conception, buffer, image, fond,pageJeu);
            while(a!=1)
            {
                if(((mouse_x>=415)&&(mouse_x<=700))&&((mouse_y>=200)&&(mouse_y<=230)))
                {
                    rectfill(buffer, 415, 200, 700, 230, marron);
                    textprintf_ex(buffer, font, 442, 215, blanc,-1, "%s", "APPUYER POUR DEBUTER LA PARTIE");
                    blit(buffer,screen,0,0,0,0,800,600);
                    if(mouse_b &1)
                    {
                        blit(pageJeu,screen,0,0,0,0,800,600);
                        rest(1000);
                        a=1;
                        menu(image,fond,buffer,lancement,regles,options,conception,pageJeu);   ///retour au menu principal mais il faudra mettre la fonction du jeu
                    }
                }
            }
        }
    }
}






/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
int test1(BITMAP* lancement, BITMAP* regles, BITMAP* options, BITMAP* conception, BITMAP*  buffer, BITMAP* image, BITMAP* fond, BITMAP* pageJeu)
{
    int k=0;
    if(((mouse_y>=570)&&(mouse_y<=590))&&((mouse_x>=700)&&(mouse_x<=790)))
    {
        if(mouse_b & 1)
        {
            clear_bitmap(buffer);
            clear_bitmap(screen);
            menu(image, fond, buffer, lancement, regles, options, conception,pageJeu);
            k=1;
        }
    }
    blit(buffer,screen,0,0,0,0,800,600);
    return k;
}
/*******************************************************************************************************************************/
int reglesMenu(BITMAP* lancement, BITMAP* regles, BITMAP* options, BITMAP* conception, BITMAP*  buffer, BITMAP* image, BITMAP* fond, BITMAP* pageJeu)
{
    int k=0;
    while(k==0)
    {
        clear(buffer);
        blit(regles,buffer,0,0,0,0,800,600);
        rectfill(buffer, 700, 570, 790, 590, blanc);
        textprintf_ex(buffer, font, 700, 575, marron,-1, "%s", "RETOUR MENU");
        textprintf_centre_ex(buffer,font,550,150,marron,-1,"%s","METTRE LES REGLES DU JEU ICI");
        if(((mouse_y>=570)&&(mouse_y<=590))&&((mouse_x>=700)&&(mouse_x<=790)))
        {
            if(mouse_b & 1)
            {
                menu(image, fond, buffer, lancement, regles, options, conception,pageJeu);
                k=1;
            }
        }
        blit(buffer,screen,0,0,0,0,800,600);
    }
    return k;
}
/*******************************************************************************************************************************/
int test3(BITMAP* lancement, BITMAP* regles, BITMAP* options, BITMAP* conception, BITMAP*  buffer, BITMAP* image, BITMAP* fond, BITMAP* pageJeu)
{
    int k=0;
    while(k==0)
    {
        clear(buffer);
        blit(options,buffer,0,0,0,0,800,600);
        rectfill(buffer, 700, 570, 790, 590, blanc);
        textprintf_ex(buffer, font, 700, 575, marron,-1, "%s", "RETOUR MENU");
        if(((mouse_y>=570)&&(mouse_y<=590))&&((mouse_x>=700)&&(mouse_x<=790)))
        {
            if(mouse_b & 1)
            {
                menu(image, fond, buffer, lancement, regles, options, conception,pageJeu);

                k=1;
            }
        }
        blit(buffer,screen,0,0,0,0,800,600);
    }
    return k;
}
/*******************************************************************************************************************************/
int conceptionMenu(BITMAP* lancement, BITMAP* regles, BITMAP* options, BITMAP* conception, BITMAP*  buffer, BITMAP* image, BITMAP* fond, BITMAP* pageJeu)
{
    int k=0;
    while(k==0)
    {
        clear(buffer);
        blit(conception,buffer,0,0,0,0,800,600);
        rectfill(buffer, 700, 570, 790, 590, blanc);
        textprintf_ex(buffer, font, 700, 575, marron,-1, "%s", "RETOUR MENU");
        textprintf_centre_ex(buffer,font,550,150,marron,-1,"%s","METTRE LES INFORMATIONS SUR");
        textprintf_centre_ex(buffer,font,550,160,marron,-1,"%s","LA CONCEPTION DU JEU ICI");
        if(((mouse_y>=570)&&(mouse_y<=590))&&((mouse_x>=700)&&(mouse_x<=790)))
        {
            if(mouse_b & 1)
            {
                menu(image, fond, buffer, lancement, regles, options, conception,pageJeu);
                k=1;
            }
        }
        blit(buffer,screen,0,0,0,0,800,600);
    }
    return k;
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/



