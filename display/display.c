
#include <stdio.h>
#include "display.h"

void splash_screen() {

	POINT P;

	int colors_pink[] = {deeppink, darkviolet, fuchsia, lightpink, mediumpurple};
	int colors_blue[] = {blueviolet, aqua, aquamarine, azure, aliceblue};

	for (int i = 0; i < HEIGHT + 100; i+=15) {

		fill_screen(turquoise);

		for(int j = 0; j < 5; j++){
			P.x = WIDTH / 2 - 300 + j*2;
			P.y = HEIGHT - i + j*10;
			aff_pol("NOUS SOMMES SUR LE", 40, P, colors_pink[j]);
			P.x = WIDTH / 2 - 200 + j*2;
			P.y = HEIGHT - i - 70 + j*10;
			aff_pol("SERVICE PUBLIC", 40, P, colors_blue[j]);
		}

		attendre(50);
	}

	fill_screen(black);

}

void affiche_plateau(int ig) { //TODO : variation

	draw_board_grid(ig);
	print_ruler(ig);

}

void draw_board_grid(int ig){

	POINT P;
	int i, j, offset;

	fill_screen(aqua);
	P.x = WIDTH / 2 - 80;
	P.y = HEIGHT - 10;
	aff_pol("SPLASH", 40, P, deeppink);

	offset = WIDTH / 7;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			P.x = offset * (i+1);
			P.y = offset * (j+1);

			affiche_lisere(P, plateau[i][j].lisere);

			switch (plateau[i][j].typeP) {
				case LICORNE:
					affiche_licorne(P, plateau[i][j].coulP);
					break;;
				case PALADIN:
					affiche_paladin(P, plateau[i][j].coulP);
					break;
			}
		}
	}

}


void print_ruler(int ig){
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

void affiche_lisere (POINT bg, int nbLisere){

	int i;
	int offset = WIDTH / 7;

	for(i = 0; i < nbLisere; i++) {
		draw_circle(bg, offset/2 - i*5, deeppink);
	}

}


void affiche_licorne (POINT bg, COUL coulP){
	if (coulP == BLANC) {
		draw_fill_circle(bg, 40, black);
	} else {
		draw_fill_circle(bg, 40, white);
	}
	draw_fill_circle(bg, 15, blueviolet);
}


void affiche_paladin (POINT bg, COUL coulP){
	if (coulP == BLANC) {
		draw_fill_circle(bg, 40, black);
	} else {
		draw_fill_circle(bg, 40, white);
	}
	draw_fill_circle(bg, 15, deeppink);
}
