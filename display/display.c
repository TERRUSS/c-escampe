
#include <stdio.h>
#include "display.h"


void splash_screen() {

	POINT P;

	int colors_pink[] = {deeppink, darkviolet, fuchsia, lightpink, mediumpurple};
	int colors_blue[] = {blueviolet, aqua, aquamarine, azure, aliceblue};
	int i;

	for (i = 0; i < HEIGHT + 100; i+=15) {

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

int select_view(){
	POINT P;
	// POINT clic;

	fill_screen(turquoise);

	P.x = WIDTH / 2 - 300;
	P.y = 600;
	aff_pol("Selectionner le sens du plateau", 30, P, deeppink);

	P.y = 400;

	P.x = WIDTH / 4;
	aff_pol("Normal", 40, P, deeppink);

	P.x = WIDTH / 2 + 100;
	aff_pol("Tilted", 40, P, deeppink);

	P.x = 10;
	P.y = 20;
	aff_pol("Made with love by Terruss and Cousteau", 20, P, mediumpurple);
	while (true) {
		P=wait_clic();

		if ( 350 < P.y && P.y < 500 ) {
			if ( P.x < WIDTH/2) {
				return 1;
			} else {
				return 2;
			}
		}
	}

	return 1;

}


void affiche_plateau(int ig) { //TODO : variation

	draw_board_grid(ig);
	print_ruler();

}

void draw_board_grid(int ig) {

	POINT P;
	int i=0, j=0, offset;
	//Le y corespond au ligne
	//Le x corespond aucologne

	fill_screen(aqua);
	P.x = WIDTH / 2 - 80;
	P.y = HEIGHT - 10;
	aff_pol("SPLASH", 40, P, deeppink);

	offset = WIDTH / 7;
	for (j = 0; j < 6; j++) {;
		for (i = 0; i < 6; i++) {

				// on affiche la grille
				//a faire au debut puis plus y toucher !!!
			P.x = offset * (i+1);
			P.y = offset * (j+1);

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

void update_board(int ig){
	int i, j;
	NUMBOX numB;
	POINT P;

	P.x = 0; P.y = 0; // On initialise pour éviter les erreures

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			// on affiche les pions
			numB.c = i;
			numB.l = j;

			if (plateau[i][j].typeP == LICORNE) {

				if (ig == 1) { // suivant ig
					P = numBox_to_pointBG_ig1(numB);
				} else if (ig == 2) {
					P = numBox_to_pointBG_ig2(numB);
				}
				affiche_licorne(P, plateau[i][j].coulP);

			} else if (plateau[i][j].typeP == PALADIN) {
				if (ig == 1) { // suivant ig
					P = numBox_to_pointBG_ig1(numB);
				} else if (ig == 2) {
					P = numBox_to_pointBG_ig2(numB);
				}
				affiche_paladin(P, plateau[i][j].coulP);
			}
		}
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
		draw_fill_circle(bg, 40, white);
	} else {
		draw_fill_circle(bg, 40, black);
	}
	draw_fill_circle(bg, 15, blueviolet);
}


void affiche_paladin (POINT bg, COUL coulP){
	if (coulP == BLANC) {
		draw_fill_circle(bg, 40, white);
	} else {
		draw_fill_circle(bg, 40, black);
	}
	draw_fill_circle(bg, 15, deeppink);
}

void affiche_vide (POINT bg){
	draw_fill_circle(bg, 40, cyan);
}


void hint_message(char * message) {
	POINT P, Q;

		//clean area
	P.x = 0; P.y = HEIGHT;
	Q.x = WIDTH; Q.y = HEIGHT-50;
	draw_fill_rectangle(P, Q, cyan);

	P.x = 10;
	P.y = HEIGHT - 10;
	aff_pol(message, 40, P, deeppink);

}
