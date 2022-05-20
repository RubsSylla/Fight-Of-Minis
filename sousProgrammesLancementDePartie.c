#include "headersMenu.h"

void lancementPartie(BITMAP* lancement, BITMAP* regles, BITMAP* options, BITMAP* conception, BITMAP*  buffer, BITMAP* image, BITMAP* fond, BITMAP* pageJeu)
{
    int a=0;
    int N;
    int nombreJoueurs=0;
    int choix=0;
    int choixClasse=0;
    int saisie=0;
    int choixDebutJeu=0;

    BITMAP* feuille;
    feuille = load_bitmap("Feuille.bmp", NULL);

    int statut;

    t_joueurs *JOUEURS;

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
                nombreJoueurs=2;
                printf("le nombre de joueurs pour cette partie est de : %d ", nombreJoueurs);
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
                    nombreJoueurs=3;
                    printf("le nombre de joueurs pour cette partie est de : %d ", nombreJoueurs);
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
                        nombreJoueurs=4;
                        printf("le nombre de joueurs pour cette partie est de : %d ",nombreJoueurs);
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
            JOUEURS=(t_joueurs*)malloc(nombreJoueurs*sizeof(t_joueurs));

            textprintf_ex(buffer, font, 415, 140, marron,-1, "%s", "Veuillez suivre les instructions sur ");
            textprintf_ex(buffer, font,415,150,marron,-1,"%s","la fenetre de commande : ");
            blit(buffer,screen,0,0,0,0,800,600);
            printf("\n");


            for(int i=0 ; i<nombreJoueurs ; i++)
            {
                printf("saisir le nom du %d e joueur : ", i+1);
                fflush(stdin);
                scanf("%s", &JOUEURS[i].nom);
            }
            printf("\nLES NOMS DES JOUEURS SONT :\n");
            for(int j=0 ; j<N ; j++)
            {
              printf("- %s\n", JOUEURS[j].nom);

            }
            printf("\n----------NOMS DES JOUEURS ENREGISTRES----------\n");
            printf("retour sur la fenetre de jeu\n");
            saisie=1;
        }

        if(saisie==1)
        {
            for(int i=0 ; i<nombreJoueurs ; i++)
            {
                mouse_x=10;
                mouse_y=10;

                choixClasse=0;

                while(choixClasse==0)
                {
                    if(statut == 0)
                    {
                        textprintf_ex(buffer,font,442,215,marron,-1,"Le joueur %d choisi sa classe :\n", i+1);

                        rectfill(buffer,405,250,475,265,blanc);
                        textprintf_ex(buffer,font,407,255,marron,-1,"%s","GUERRIER");
                        rectfill(buffer,479,250,547,265,blanc);
                        textprintf_ex(buffer,font,481,255,marron,-1,"%s","SORCIERE");
                        rectfill(buffer,551,250,650,265,blanc);
                        textprintf_ex(buffer,font,553,255,marron,-1,"%s","GUERRISSEUSE");
                        rectfill(buffer,654,250,720,265,blanc);
                        textprintf_ex(buffer,font,656,255,marron,-1,"%s","CHASSEUR");

                        blit(buffer,screen,0,0,0,0,800,600);
                    }

                    if(((mouse_x>=405)&&(mouse_x<=475))&&((mouse_y>=250)&&(mouse_y<=265)))
                    {
                        statut = 1;
                        rectfill(buffer,405,250,475,265,marron);
                        textprintf_ex(buffer,font,407,255,blanc,-1,"%s","GUERRIER");
                        blit(buffer,screen,0,0,0,0,800,600);
                        if(mouse_b &1)
                        {
                            JOUEURS[i].classes.guerrier=1;
                            choixClasse=1;
                            printf("le joueur %d a choisi la classe : guerrier\n", i+1);
                            break;
                        }
                    }
                    else if(((mouse_x>=479)&&(mouse_x<=547))&&((mouse_y>=250)&&(mouse_y<=265)))
                    {
                        statut = 1;
                        rectfill(buffer,479,250,547,265,marron);
                        textprintf_ex(buffer,font,481,255,blanc,-1,"%s","SORCIERE");
                        blit(buffer,screen,0,0,0,0,800,600);
                        if(mouse_b &1)
                        {
                            JOUEURS[i].classes.sorciere=1;
                            choixClasse=1;
                            printf("le joueur %d a choisi la classe : sorciere\n", i+1);
                            break;
                        }
                    }
                    else if(((mouse_x>=551)&&(mouse_x<=650))&&((mouse_y>=250)&&(mouse_y<=265)))
                    {
                        statut = 1;
                        rectfill(buffer,551,250,650,265,marron);
                        textprintf_ex(buffer,font,553,255,blanc,-1,"%s","GUERRISSEUSE");
                        blit(buffer,screen,0,0,0,0,800,600);
                        if(mouse_b &1)
                        {
                            JOUEURS[i].classes.guerrisseuse=1;
                            choixClasse=1;
                            printf("le joueur %d a choisi la classe : guerrisseuse\n\n", i+1);
                            break;
                        }
                    }
                    else if(((mouse_x>=654)&&(mouse_x<=720))&&((mouse_y>=250)&&(mouse_y<=265)))
                    {
                        statut = 1;
                        rectfill(buffer,654,250,720,265,marron);
                        textprintf_ex(buffer,font,656,255,blanc,-1,"%s","CHASSEUR");
                        blit(buffer,screen,0,0,0,0,800,600);
                        if(mouse_b &1)
                        {
                            JOUEURS[i].classes.chasseur=1;
                            choixClasse=1;
                            printf("le joueur %d a choisi la classe : chasseur", i+1);
                            break;
                        }
                    }
                    else
                    {
                        statut = 0;
                    }



                }
            }

            rectfill(buffer, 415, 400, 700, 430, blanc);
            textprintf_ex(buffer, font, 442, 415, marron,-1, "%s", "APPUYER POUR DEBUTER LA PARTIE");
            blit(buffer,screen,0,0,0,0,800,600);
            a=test1(lancement, regles, options, conception, buffer, image, fond,pageJeu);
            printf("%d", a);

            while(a!=1)
            {
                if(((mouse_x>=415)&&(mouse_x<=700))&&((mouse_y>=400)&&(mouse_y<=430)))
                {
                    rectfill(buffer, 415, 400, 700, 430, marron);
                    textprintf_ex(buffer, font, 442, 415, blanc,-1, "%s", "APPUYER POUR DEBUTER LA PARTIE");
                    blit(buffer,screen,0,0,0,0,800,600);

                    if(mouse_b & 1)
                    {
                        blit(pageJeu,screen,0,0,0,0,800,600);
                        rest(1000);
                        a=1;

                        ///Jeu(JOUEURS,buffer,feuille,nombreJoueurs);
                        //menu(image,fond,buffer,lancement,regles,options,conception,pageJeu);   ///retour au menu principal mais il faudra mettre la fonction du jeu
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



