
#pragma once

#include "../lib/graphics.h"
#include "../utils/types.h"
#include "../display/display.h"


void move (int ig, int player, POINT* pawn, NUMBOX* numPawn);
void select_pawn (int ig, POINT* pawn, NUMBOX* numPawn, int player);
void select_deplacement( int ig, POINT *pawn, NUMBOX *numPawn );

int deplacement_is_valid(POINT P, int ig);

void reset_playable_map();

POINT numBox_to_pointBG_ig1 (NUMBOX numB);
POINT numBox_to_pointBG_ig2 (NUMBOX numB);
NUMBOX point_ig1_to_numBox (POINT P);
NUMBOX point_ig2_to_numBox (POINT P);
