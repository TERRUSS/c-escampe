
#pragma once

#include "../lib/graphics.h"
#include "../utils/types.h"
#include "../movements/movements.h"


void splash_screen();
int select_view();

void affiche_plateau(int ig);
void draw_board_grid(int ig);
void update_board(int ig);
void print_ruler();

void affiche_lisere (POINT bg, int nbLisere);

void affiche_licorne (POINT bg, COUL coulP);
void affiche_paladin (POINT bg, COUL coulP);
void affiche_vide (POINT bg);


void hint_message(char *);
