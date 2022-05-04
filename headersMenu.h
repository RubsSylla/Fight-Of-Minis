#ifndef HEADERSMENU_H_INCLUDED
#define HEADERSMENU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <allegro.h>
#include "string.h"

#define blanc makecol(255,255,255)
#define marron makecol(120,67,21)


void menu(BITMAP* image, BITMAP* fond, BITMAP* buffer, BITMAP* lancement, BITMAP* regles, BITMAP* options, BITMAP* conception, BITMAP* pageJeu);

void lancementPartie(BITMAP* lancement, BITMAP* regles, BITMAP* options, BITMAP* conception, BITMAP*  buffer, BITMAP* image, BITMAP* fond, BITMAP* pageJeu);
int reglesMenu(BITMAP* lancement, BITMAP* regles, BITMAP* options, BITMAP* conception, BITMAP*  buffer, BITMAP* image, BITMAP* fond, BITMAP* pageJeu);
int conceptionMenu(BITMAP* lancement, BITMAP* regles, BITMAP* options, BITMAP* conception, BITMAP*  buffer, BITMAP* image, BITMAP* fond, BITMAP* pageJeu);

int choixNombre(BITMAP* lancement, BITMAP* regles, BITMAP* options, BITMAP* conception, BITMAP*  buffer, BITMAP* image, BITMAP* fond, BITMAP* pageJeu);
int test1(BITMAP* lancement, BITMAP* regles, BITMAP* options, BITMAP* conception, BITMAP*  buffer, BITMAP* image, BITMAP* fond, BITMAP* pageJeu);
int test3(BITMAP* lancement, BITMAP* regles, BITMAP* options, BITMAP* conception, BITMAP*  buffer, BITMAP* image, BITMAP* fond, BITMAP* pageJeu);


void affichageDeBase(BITMAP* fond, BITMAP* buffer);


#endif // HEADERSMENU_H_INCLUDED
