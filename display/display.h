
#pragma once

#include "../lib/graphics.h"
#include "../utils/types.h"


void splash_screen();

void affiche_plateau(int ig);
void draw_board_grid(int ig);
void print_ruler();

void affiche_lisere (POINT bg, int nbLisere);

void affiche_licorne (POINT bg, COUL coulP);
void affiche_paladin (POINT bg, COUL coulP);
