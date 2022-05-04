#include "headersMenu.h"

int main()
{
    srand(time(NULL));

    printf("->Initialisation d'Allegro en cours ...\n");
    allegro_init();
    printf("OK\n");

    printf("->Initialisation couleur de fond en cours ...\n");
    set_color_depth(desktop_color_depth());
    printf("OK\n");

    printf("->Initialisation du mode graphique en cours ...\n");
    if((set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0))!=0)
    {
        allegro_message("Pb de mode graphique");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    printf("OK\n");

    install_mouse();
    show_mouse(screen);
    install_keyboard();

    BITMAP* fond;
    fond=create_bitmap(800,600);

    BITMAP* buffer;
    buffer=create_bitmap(800,600);

    BITMAP* image;
    image=load_bitmap("fond.bmp", NULL);

    BITMAP* lancement;
    lancement=load_bitmap("fond.bmp", NULL);

    BITMAP* regles;
    regles=load_bitmap("fond.bmp", NULL);

    BITMAP* options;
    options=load_bitmap("fond.bmp", NULL);

    BITMAP* conception;
    conception=load_bitmap("fond.bmp", NULL);

    BITMAP* pageJeu;
    pageJeu=load_bitmap("pageJeu.bmp", NULL);
    /*******************************************************************************************************************/

    mouse_x=5;
    mouse_b=5;

    while(!key[KEY_ESC])
    {
        clear(buffer);

        blit(image,buffer,0,0,0,0,800,600);

        menu(image,fond,buffer,lancement,regles,options,conception,pageJeu);

        blit(buffer,screen,0,0,0,0,800,600);
    }

    /*******************************************************************************************************************/
    return 0;

}END_OF_MAIN();

