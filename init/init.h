#pragma once

#include "../lib/graphics.h"
#include "../utils/types.h"
#include "../init/init.h"
#include "../display/display.h"
#include "../movements/movements.h"

void splash_screen();

int select_player();

void loading_screen();

int screen_select_player();

int select_view();

void victory_screen(int gagnant);
