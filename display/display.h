
#pragma once

#include "../lib/graphics.h"
#include "../utils/types.h"
#include "../utils/utils.h"
#include "../init/init.h"
#include "../movements/movements.h"
#include "../display/draw.h"

#include <math.h>


void affiche_plateau(int ig);

void update_board(int ig,POINT* pawn);
void update_player(int player, int ig);


void affiche_lisere (POINT bg, int nbLisere);

void affiche_licorne (POINT bg, COUL coulP);
void affiche_paladin (POINT bg, COUL coulP);
void affiche_vide ();

void affiche_pm(NUMBOX* numPawn, int ig);

void playable_point(int ig,NUMBOX numB, int playable);

void lisere_1(NUMBOX* numPawn, int ig, int i, int j,int nb_lisere);
void lisere_2(NUMBOX* numPawn, int ig, int i, int j,int nb_lisere);
void lisere_3(NUMBOX* numPawn, int ig, int i, int j, int nb_lisere);
