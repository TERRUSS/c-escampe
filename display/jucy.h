#pragma once

#include "../lib/graphics.h"
#include "../utils/types.h"
#include "../display/display.h"
#include "../movements/movements.h"

void splash_screen();

int select_player(int* color);

void loading_screen();

void screen_select_player(int* color);

int select_view();

void victory_screen(int player);
