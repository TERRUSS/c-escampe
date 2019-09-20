
#pragma once

#include "../lib/graphics.h"
#include "../utils/types.h"


void splash_screen();
int select_view();

void affiche_plateau(int ig);
void draw_board_grid(int ig);
void print_ruler();

void affiche_lisere (POINT bg, int nbLisere);

void affiche_licorne (POINT bg, COUL coulP);
void affiche_paladin (POINT bg, COUL coulP);

POINT numBox_to_pointBG_ig1 (NUMBOX numB);
POINT numBox_to_pointBG_ig2 (NUMBOX numB);
NUMBOX point_ig1_to_numBox (POINT P);
NUMBOX point_ig2_to_numBox (POINT P);
