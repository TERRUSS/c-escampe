
#include "lib/graphics.h"

void draw_board();

int main() {

	init_graphics(700, 700); /* (largeur, hauteur) */
	affiche_auto_off();

	draw_board();

	affiche_all(); //render

	wait_escape();
	return(0);
}


void draw_board() {
	// draw_board_grid();
	// draw_board_circles();
	// print_markers();
}
