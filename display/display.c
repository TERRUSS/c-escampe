
#include <stdio.h>
#include "display.h"

void splash_screen() {

	POINT P;

	int colors_pink[] = {deeppink, darkviolet, fuchsia, lightpink, mediumpurple};
	int colors_blue[] = {blueviolet, aqua, aquamarine, azure, aliceblue};

	for (int i = 0; i < HEIGHT + 100; i+=15) {

		fill_screen(turquoise);

		for(int j = 0; j < 5; j++){
			P.x = 100 + j*2;
			P.y = HEIGHT - i + j*10;
			aff_pol("NOUS SOMMES SUR LE", 40, P, colors_pink[j]);
			P.x = 200 + j*2;
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
	for (i = 1; i < 7; i++) {
		for (j = 1; j < 7; j++) {
			P.x = offset * i;
			P.y = offset * j;

			draw_circle(P, offset/2, deeppink);
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

		aff_pol(rulerLetters[i-1], 40, P, deeppink);
	}

	for(i = 1; i < 7; i++) { // print digits
		P.y = offset/3;
		P.x = offset * i;

		aff_pol(rulerDigits[i-1], 40, P, deeppink);
	}
}


void affiche_lisere (POINT bg, int nbLisere){
	int i,j;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			switch (plateau[i][j].lisere) {
				case 1:
				//1 lesere
				break;
				case 2:
				//2 nbLisere
				break;
				case 3:
				//3 lisere
				break;
			}
		}
	}
}


void affiche_licorne (POINT bg, COUL coulP){
	int i,j;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (plateau[i][j].typeP == LICORNE) {
				//affiche le paladin
				if (plateau[i][j].coulP == NOIR) {
					//noir
				}else if (plateau[i][j].coulP == BLANC){
					//blanc
				}
			}
		}
	}
}


void affiche_paladin (POINT bg, COUL coulP){
	int i,j;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (plateau[i][j].typeP == PALADIN) {
				//affiche le paladin
				if (plateau[i][j].coulP == NOIR) {
					//noir
				}else if (plateau[i][j].coulP == BLANC){
					//blanc
				}
			}
		}
	}
}
