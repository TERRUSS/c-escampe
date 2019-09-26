#include <stdio.h>
#include "draw.c.h"

void draw_board_grid(int ig) {

	POINT P;
	int i=0, j=0, offset;
	//Le y corespond au ligne
	//Le x corespond au cologne

	fill_screen(aqua);
	P.x = WIDTH / 2 - 80;
	P.y = HEIGHT - 10;
	aff_pol("SPLASH", 40, P, deeppink);

	offset = WIDTH / 7;
	for (j = 0; j < 6; j++) {;
		for (i = 0; i < 6; i++) {

				// on affiche la grille
			P.x = offset * (j+1);
			P.y = offset * (i+1);

			affiche_lisere(P, plateau[i][j].lisere);
		}
	}
}

void print_ruler(){
	POINT P;
	int i, offset;
	char * rulerLetters[] = {"A", "B", "C", "D", "E", "F"};
	char * rulerDigits[] = {"1", "2", "3", "4", "5", "6"};

	offset = WIDTH / 7;

	for(i = 1; i < 7; i++) {	// print letters
		P.x = offset/7;
		P.y = offset * i;

		aff_pol(rulerLetters[6-i], 40, P, deeppink);
	}

	for(i = 1; i < 7; i++) { // print digits
		P.y = offset/3;
		P.x = offset * i;

		aff_pol(rulerDigits[i-1], 40, P, deeppink);
	}
}
