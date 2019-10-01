#include <stdio.h>
#include "draw.h"

void draw_board_grid(int ig) {

	POINT P;
	int i=0, j=0;

	NUMBOX numB;
	//Le y corespond au ligne
	//Le x corespond au cologne

	fill_screen(aqua);
	P.x = WIDTH / 2 - 80;
	P.y = HEIGHT - 10;
	aff_pol("SPLASH", 40, P, deeppink);

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			numB.c = i;
			numB.l = j;
			affiche_lisere(numB, plateau[i][j].lisere, ig);
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

void hint_message(char * message) {
	POINT P, Q;

		//clean area
	P.x = 0; P.y = HEIGHT;
	Q.x = WIDTH; Q.y = HEIGHT-50;
	draw_fill_rectangle(P, Q, cyan);

	P.x = 10;
	P.y = HEIGHT - 10;
	aff_pol(message, 40, P, deeppink);

	affiche_all();
}

void draw_circle_from_numb(NUMBOX numB, int radius, int color, int ig){

	POINT P;
	P.x = 0; P.y = 0; //on evite les warnings

	if (ig == 1) {
		P = numBox_to_pointBG_ig1(numB);
	} else if (ig == 2) {
		P = numBox_to_pointBG_ig2(numB);
	}
	draw_circle(P, radius, color);
}

void draw_fill_circle_from_numb(NUMBOX numB, int radius, int color, int ig){

	POINT P;

	P.x = 0; P.y = 0; //on evite les warnings

	if (ig == 1) {
		P = numBox_to_pointBG_ig1(numB);
	} else if (ig == 2) {
		P = numBox_to_pointBG_ig2(numB);
	}
	draw_fill_circle(P, radius, color);
}


void update_player(int player, int ig, int turn_pm) {
	POINT P, Q;
	int i, j;
	char * playerName[2][12] = {
		{"J", "o", "u", "e", "u", "r", " ", "B", "l", "a", "n", "c"},
		{"J", "o", "u", "e", "u", "r", " ", "N", "o", "i", "r"," "}
	};

		//clean area and print player
	P.x = WIDTH - 45; P.y = HEIGHT;
	Q.x = WIDTH; Q.y = 0;

	draw_fill_rectangle(P, Q, cyan);

	for (i = 0; i < 12; i++){
		P.x = WIDTH - 45;
		P.y = HEIGHT - 120 - i*40;
		aff_pol(playerName[player][i], 40, P, deeppink);
	}

		//highlight player's playable pawns
	NUMBOX numB;

	P.x = 0; P.y = 0; // On initialise pour éviter les erreures

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			numB.c = i;
			numB.l = j;

				//on clean le highlight du tour précédent
			P = numBox_to_pointBG_ig1(numB);
			draw_circle(P, 40, cyan);
			draw_circle(P, 41, cyan);

				//On hilight les pions jouables / Joueur
			if (plateau[i][j].coulP == player+1 && plateau[i][j].lisere == turn_pm) { //ie. coulP != {NONE, PLAYABLE}
				draw_circle_from_numb(numB, 41, yellow, ig);
			}
		}
	}

	affiche_all();
}
