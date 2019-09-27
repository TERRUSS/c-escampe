
#pragma once

#include "../lib/graphics.h"
#include "../utils/types.h"
#include "../display/display.h"


int move (int ig, int player);
NUMBOX select_pawn (int ig, int player);
int select_deplacement( int ig, NUMBOX numPawn, int player );

int deplacement_is_valid(POINT P, int ig, int player);

void reset_playable_map();

POINT numBox_to_pointBG_ig1 (NUMBOX numB);
POINT numBox_to_pointBG_ig2 (NUMBOX numB);
NUMBOX point_ig1_to_numBox (POINT P);
NUMBOX point_ig2_to_numBox (POINT P);
