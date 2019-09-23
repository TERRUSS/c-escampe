
#pragma once

#include "../lib/graphics.h"
#include "../utils/types.h"
#include "../display/display.h"

POINT numBox_to_pointBG_ig1 (NUMBOX numB);
POINT numBox_to_pointBG_ig2 (NUMBOX numB);
NUMBOX point_ig1_to_numBox (POINT P);
NUMBOX point_ig2_to_numBox (POINT P);

void move (int ig, int player);
