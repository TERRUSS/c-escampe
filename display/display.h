
#pragma once

#include "../lib/graphics.h"
#include "../utils/types.h"
#include "../utils/utils.h"
#include "../movements/movements.h"


void splash_screen();
void select_player(int* player_B, int* player_W);
int select_view();

void affiche_plateau(int ig);
void draw_board_grid(int ig);
void update_board(int ig);
void update_player(int player);
void print_ruler();

void affiche_lisere (POINT bg, int nbLisere);

void affiche_licorne (POINT bg, COUL coulP);
void affiche_paladin (POINT bg, COUL coulP);
void affiche_vide (POINT bg);


void hint_message(char *);
