
#pragma once

#include "../lib/graphics.h"
#include "../utils/types.h"
#include "display.h"


void draw_board_grid(int ig);

void update_player(int player, int ig);

void print_ruler();

void draw_circle_from_numb(NUMBOX numB, int radius, int color, int ig);

void draw_fill_circle_from_numb(NUMBOX numB, int radius, int color, int ig);

void hint_message(char * message);
