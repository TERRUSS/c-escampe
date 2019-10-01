
#pragma once

#include "../lib/graphics.h"
#include "../utils/types.h"
#include "../utils/utils.h"
#include "jucy.h"
#include "../movements/movements.h"
#include "../display/draw.h"

#include <math.h>


void affiche_plateau(int ig);

void update_board(int ig);


void affiche_lisere (NUMBOX numB, int nbLisere, int ig);

void affiche_licorne (POINT bg, COUL coulP);
void affiche_paladin (POINT bg, COUL coulP);
void affiche_vide ();

void calcule_pm(NUMBOX numB, int player);
void expand(int x, int y, int i, int player);
void affiche_pm(int ig);

void playable_point(int ig,NUMBOX numB, int playable);
