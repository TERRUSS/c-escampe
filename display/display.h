
#pragma once

#include "../lib/graphics.h"
#include "../utils/types.h"
#include "../utils/utils.h"
#include "../movements/movements.h"

#include <math.h>


void splash_screen();
int select_player();
void loading_screen();
int screen_select_player();
int select_view();

void affiche_plateau(int ig);
void draw_board_grid(int ig);
void update_board(int ig,POINT* pawn);
void update_player(int player, int ig);
void print_ruler();

void affiche_lisere (POINT bg, int nbLisere);

void affiche_licorne (POINT bg, COUL coulP);
void affiche_paladin (POINT bg, COUL coulP);
void affiche_vide (POINT bg);

void affiche_pm(NUMBOX* numPawn, int ig);
void playable_point(int ig,NUMBOX numB, int playable);
void lisere_1(NUMBOX* numPawn, int ig, int i, int j,int nb_lisere);
void lisere_2(NUMBOX* numPawn, int ig, int i, int j,int nb_lisere);
void lisere_3(NUMBOX* numPawn, int ig, int i, int j, int nb_lisere);


void draw_circle_from_numb(NUMBOX numB, int radius, int color, int ig);
void draw_fill_circle_from_numb(NUMBOX numB, int radius, int color, int ig);
void hint_message(char * message);
