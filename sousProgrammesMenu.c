#include "headersMenu.h"

/*****************************************************SOUS PROGRAMMES***********************************************************/
/*******************************************************************************************************************************/

void menu(BITMAP* image, BITMAP* fond, BITMAP* buffer, BITMAP* lancement, BITMAP* regles, BITMAP* options, BITMAP* conception, BITMAP* pageJeu)
{
    int b=0, c=0, d=0;
    int constanteDebutDeJeu=0;

    clear(buffer);
    blit(image,buffer,0,0,0,0,800,600);

    while(constanteDebutDeJeu==0)
    {
        if(((mouse_x>=450)&&(mouse_x<=650))&&((mouse_y>=100)&&(mouse_y<=150)))
        {

            blit(image,buffer,0,0,0,0,800,600);
            affichageDeBase(fond, buffer);
            rectfill(buffer,450,100,650,150,marron);
            textprintf_centre_ex(buffer,font,550,125,blanc,-1,"%s","LANCEMENT PARTIE");

            if(mouse_b &1)
            {
                lancementPartie(lancement,regles,options,conception,buffer,image,fond,pageJeu);
                constanteDebutDeJeu=1;
            }
            blit(buffer,screen,0,0,0,0,800,600);
            rest(30);
        }

        if(((mouse_x>=450)&&(mouse_x<=650))&&((mouse_y>=200)&&(mouse_y<=250)))
        {
            blit(image,buffer,0,0,0,0,800,600);
            affichageDeBase(fond, buffer);
            rectfill(buffer,450,200,650,250,marron);
            textprintf_centre_ex(buffer,font,550,225,blanc,-1,"%s","REGLES");

            if(mouse_b &1)
            {
                while(b!=1)
                {
                    b=reglesMenu(lancement, regles, options, conception, buffer, image, fond,pageJeu);
                    if(b==1)
                    {
                        clear(buffer);
                        affichageDeBase(fond, buffer);
                    }
                }
            }
            blit(buffer,screen,0,0,0,0,800,600);
            rest(30);
        }

        if(((mouse_x>=450)&&(mouse_x<=650))&&((mouse_y>=300)&&(mouse_y<=350)))
        {
            blit(image,buffer,0,0,0,0,800,600);
            affichageDeBase(fond, buffer);
            rectfill(buffer,450,300,650,350,marron);
            textprintf_centre_ex(buffer,font,550,325,blanc,-1,"%s","OPTIONS");

            if(mouse_b &1)
            {
                while(c!=1)
                {
                    c=test3(lancement, regles, options, conception, buffer, image, fond,pageJeu);
                    if(c==1)
                    {
                        clear_bitmap(buffer);
                        affichageDeBase(fond, buffer);
                    }
                }
            }
            blit(buffer,screen,0,0,0,0,800,600);
            rest(30);
        }

        if(((mouse_x>=450)&&(mouse_x<=650))&&((mouse_y>=400)&&(mouse_y<=450)))
        {
                blit(image,buffer,0,0,0,0,800,600);
                affichageDeBase(fond, buffer);
                rectfill(buffer,450,400,650,450,marron);
                textprintf_centre_ex(buffer,font,550,425,blanc,-1,"%s","CONCEPTION");

                if(mouse_b &1)
                {
                    while(d!=1)
                    {
                        d=conceptionMenu(lancement, regles, options, conception, buffer, image, fond,pageJeu);
                        if(d==1)
                        {
                            clear_bitmap(buffer);
                            affichageDeBase(fond, buffer);
                        }
                    }
                }
            blit(buffer,screen,0,0,0,0,800,600);
        }

        else
        {
            affichageDeBase(fond, buffer);
            blit(buffer,screen,0,0,0,0,800,600);
        }
    }
}
/*******************************************************************************************************************************/
/*******************************************************************************************************************************/






/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
void affichageDeBase(BITMAP* fond, BITMAP* buffer)
{

    rect(buffer,450,100,650,150,blanc);
    textprintf_centre_ex(buffer, font, 550,125,marron,-1,"%s", "LANCEMENT PARTIE");
    rect(buffer,450,200,650,250,blanc);
    textprintf_centre_ex(buffer, font, 550,225,marron,-1,"%s", "REGLES");
    rect(buffer,450,300,650,350,blanc);
    textprintf_centre_ex(buffer, font, 550,325,marron,-1,"%s", "OPTIONS");
    rect(buffer,450,400,650,450,blanc);
    textprintf_centre_ex(buffer, font, 550,425,marron,-1,"%s", "CONCEPTION");
}

/*******************************************************************************************************************************/
/*******************************************************************************************************************************/
