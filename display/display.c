
#include <stdio.h>
#include "display.h"


void splash_screen() {

	POINT P;

	int colors_pink[] = {deeppink, darkviolet, fuchsia, lightpink, mediumpurple};
	int colors_blue[] = {blueviolet, aqua, aquamarine, azure, aliceblue};
	int i;

	for (i = 0; i < HEIGHT + 100; i+=15) {

		affiche_auto_off();

		fill_screen(cyan);

		for(int j = 0; j < 5; j++){
			P.x = WIDTH / 2 - 300 + j*2;
			P.y = HEIGHT - i + j*10;
			aff_pol("NOUS SOMMES SUR LE", 40, P, colors_pink[j]);
			P.x = WIDTH / 2 - 200 + j*2;
			P.y = HEIGHT - i - 70 + j*10;
			aff_pol("SERVICE PUBLIC", 40, P, colors_blue[j]);
		}

		affiche_all();
		attendre(50);
	}

	affiche_auto_on();
	fill_screen(black);
}

int select_player(){

	loading_screen();

	return screen_select_player();

}

void loading_screen(){
	int i;
	for (i = 0; i < WIDTH + 100; i+=15) {

		affiche_auto_off();

		fill_screen(cyan);

		POINT P;

		P.x = WIDTH / 2 - 200;
		P.y = 600;
		aff_pol("Selection en cours...", 30, P, deeppink);

		P.x = 0 + i;
		P.y = HEIGHT - 400;
		aff_pol("éé load ... éé", 40, P, deeppink);

		affiche_all();
		attendre(20);
	}
	fill_screen(black);
}

int screen_select_player(){
	int rand, player;

	affiche_auto_off();

	fill_screen(cyan);

	POINT P;

	P.x = WIDTH / 2 - 200;
	P.y = 600;

	rand = myrand() % 2;

	if (rand == 1) {
		player = 1;
		aff_pol("Player 1: Player Black", 30, P, deeppink);
		P.y = 500;
		aff_pol("player 2: Player White", 30, P, deeppink);
	}else{
		player = 0;

		aff_pol("Player 1: Player White", 30, P, deeppink);
		P.y = 500;
		aff_pol("Player 2: Player Black", 30, P, deeppink);
	}

	affiche_all();
	attendre(1000);

	affiche_auto_on();
	fill_screen(black);

	return player;
}

int select_view(){
	POINT P;
	// POINT clic;

	fill_screen(cyan);

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

	// return 1;

}


void affiche_plateau(int ig) { //TODO : variation

	draw_board_grid(ig);
	print_ruler();

}

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


void update_board(int ig, POINT* pawn){
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

void update_player(int player, int ig) {
	POINT P, Q;
	int i, j;
	char * playerName[2][12] = {
		{"J", "o", "u", "e", "u", "r", " ", "B", "l", "a", "n", "c"},
		{"J", "o", "u", "e", "u", "r", " ", "N", "o", "i", "r"," "}
	};

		//clean area and print player
	P.x = WIDTH - 45; P.y = HEIGHT;
	Q.x = WIDTH; Q.y = 0;

	affiche_auto_off();

	draw_fill_rectangle(P, Q, cyan);

	for (i = 0; i < 12; i++){
		P.x = WIDTH - 45;
		P.y = HEIGHT - 120 - i*40;
		aff_pol(playerName[player][i], 40, P, deeppink);
	}

		//highlight player's pawns
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
			if (plateau[i][j].coulP == player+1) { //ie. coulP != {NONE, PLAYABLE}
				draw_circle_from_numb(numB, 41, yellow, ig);
			}
		}
	}

	affiche_all();
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
	int i, j;
	NUMBOX numB;

	affiche_auto_off();

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (plateau[i][j].coulP == NONE || plateau[i][j].coulP == PLAYABLE || plateau[i][j].coulP == UNPLAYABLE ) {
				numB.c = i;
				numB.l = j;
				draw_fill_circle_from_numb(numB, 50, cyan, 1);
			}
		}
	}

	affiche_all();
}



void affiche_pm(NUMBOX* numPawn, int ig){
	int i, j;
	int nb_lisere = plateau[numPawn->c][numPawn->l].lisere;
	affiche_auto_off();

	for (i = 0; i <= nb_lisere; i++) {
		for (j = 0; j <= nb_lisere; j++) {

			switch (nb_lisere) {
				case 1:
				lisere_1(numPawn,ig,i,j,nb_lisere);
				break;
				case 2:
				lisere_2(numPawn,ig,i,j,nb_lisere);
				break;
				case 3:
				lisere_3(numPawn,ig,i,j,nb_lisere);
				break;
			}
		}
	}
	affiche_all();
}

void lisere_1(NUMBOX* numPawn, int ig, int i, int j, int nb_lisere){
	NUMBOX numB;
	int playable = true;
	int verif_lisere;

	verif_lisere = i + j;

	if ((verif_lisere == nb_lisere)){
		if ((plateau[numPawn->c - i ][numPawn->l - j].typeP == VIDE) && (numPawn->c - i >= 0) && (numPawn->l - j >= 0)){
			numB.c = numPawn->c - i;
			numB.l = numPawn->l - j;
			playable_point(ig,numB,playable);
		}
		if ((plateau[numPawn->c + i ][numPawn->l + j].typeP == VIDE) && (numPawn->c + i < 6) && (numPawn->l + j < 6)){
			numB.c = numPawn->c + i;
			numB.l = numPawn->l + j;
			playable_point(ig,numB,playable);
		}

	}
}

void lisere_2(NUMBOX* numPawn, int ig, int i, int j, int nb_lisere){
	NUMBOX numB;
	int playable = true;
	int verif_lisere;

	verif_lisere = i + j;
	printf("c: %d l: %d\n",numPawn->c,numPawn->l );
	if (verif_lisere == 1) {
		playable = false;
		if ((plateau[numPawn->c - i ][numPawn->l - j].typeP == VIDE) && (numPawn->c - i >= 0) && (numPawn->l - j >= 0)){
			numB.c = numPawn->c - i;
			numB.l = numPawn->l - j;
			playable_point(ig,numB,playable);
		}
		if ((plateau[numPawn->c + i ][numPawn->l + j].typeP == VIDE) && (numPawn->c + i < 6) && (numPawn->l + j < 6)){
			numB.c = numPawn->c + i;
			numB.l = numPawn->l + j;
			playable_point(ig,numB,playable);
		}
	}

	if (verif_lisere == nb_lisere){
		playable = true;
		printf("check : [%d %d] %d\n", numPawn->c -1, numPawn->l, plateau[numPawn->c -1][numPawn->l].typeP );

		if ((plateau[numPawn->c][numPawn->l - 1].typeP == VIDE) && (numPawn->l - j >= 0)){

			if ((i==0) && (plateau[numPawn->c][numPawn->l - j].typeP == VIDE)) {
				numB.c = numPawn->c;
				numB.l = numPawn->l - j;
				playable_point(ig,numB,playable);
			}
			if((j!=0) && (plateau[numPawn->c - i][numPawn->l - j].typeP == VIDE)) {
				numB.c = numPawn->c - i;
				numB.l = numPawn->l - j;
				playable_point(ig,numB,playable);
			}
			if((j!=0) && (plateau[numPawn->c + i][numPawn->l - j].typeP == VIDE)) {
				numB.c = numPawn->c + i;
				numB.l = numPawn->l - j;
				playable_point(ig,numB,playable);
			}
		}
		if ((plateau[numPawn->c][numPawn->l + 1].typeP == VIDE) && (numPawn->l + j < 6)){

			if ((i==0) && (plateau[numPawn->c][numPawn->l + j].typeP == VIDE)) {
				numB.c = numPawn->c;
				numB.l = numPawn->l + j;
				playable_point(ig,numB,playable);
			}


			if((j!=0) && (plateau[numPawn->c + i][numPawn->l + j].typeP == VIDE)) {
				numB.c = numPawn->c + i;
				numB.l = numPawn->l + j;
				playable_point(ig,numB,playable);
			}
			if((j!=0) && (plateau[numPawn->c - i][numPawn->l + j].typeP == VIDE)) {
				numB.c = numPawn->c - i;
				numB.l = numPawn->l + j;
				playable_point(ig,numB,playable);
			}
		}

		////

		if((plateau[numPawn->c - 1][numPawn->l].typeP == VIDE) && (numPawn->c - i >= 0)) {

			if ((j==0) && (plateau[numPawn->c - i][numPawn->l].typeP == VIDE)) {
				numB.c = numPawn->c - i;
				numB.l = numPawn->l;
				playable_point(ig,numB,playable);
			}
			if((i!= 0) && (plateau[numPawn->c - i][numPawn->l + j].typeP == VIDE)) {
				numB.c = numPawn->c - i;
				numB.l = numPawn->l + j;
				playable_point(ig,numB,playable);
			}
			if((i!= 0) && (plateau[numPawn->c - i][numPawn->l - j].typeP == VIDE)) {
				numB.c = numPawn->c - i;
				numB.l = numPawn->l - j;
				playable_point(ig,numB,playable);
			}
		}
		if((plateau[numPawn->c + 1][numPawn->l].typeP == VIDE) && (numPawn->c + i < 6)) {
			if ((j==0) && (plateau[numPawn->c + i][numPawn->l].typeP == VIDE)) {
				numB.c = numPawn->c + i;
				numB.l = numPawn->l;
				playable_point(ig,numB,playable);
			}
			if((i!= 0) && (plateau[numPawn->c + i][numPawn->l + j].typeP == VIDE)) {
				numB.c = numPawn->c + i;
				numB.l = numPawn->l + j;
				playable_point(ig,numB,playable);
			}
			if((i!= 0) && plateau[numPawn->c + i][numPawn->l - j].typeP == VIDE) {
				numB.c = numPawn->c + i;
				numB.l = numPawn->l - j;
				playable_point(ig,numB,playable);
			}
		}
	}
}

void lisere_3(NUMBOX* numPawn, int ig, int i, int j, int nb_lisere){
	NUMBOX numB;
	int playable = true;
	int verif_lisere;
	verif_lisere = i + j;

	if (verif_lisere == 1) {
		playable = true;

		if ((i == 0) && (plateau[numPawn->c][numPawn->l - j].typeP == VIDE) && (numPawn->l - j >= 0)) {
			if ((plateau[numPawn->c - j][numPawn->l].typeP == VIDE) && (plateau[numPawn->c - j][numPawn->l - j].typeP == VIDE)) {
				numB.c = numPawn->c;
				numB.l = numPawn->l - j;
				playable_point(ig,numB,playable);
			}

			if ((plateau[numPawn->c + j][numPawn->l].typeP == VIDE) && (plateau[numPawn->c + j][numPawn->l - j].typeP == VIDE)) {
				numB.c = numPawn->c;
				numB.l = numPawn->l - j;
				playable_point(ig,numB,playable);
			}

		}
		if (( j == 0) && (plateau[numPawn->c - i][numPawn->l].typeP == VIDE) && (numPawn->c - i >= 0)) {
			if ((plateau[numPawn->c][numPawn->l - i].typeP == VIDE) && (plateau[numPawn->c - i][numPawn->l - i].typeP == VIDE)) {
				numB.c = numPawn->c - i;
				numB.l = numPawn->l;
				playable_point(ig,numB,playable);
			}
			if ((plateau[numPawn->c][numPawn->l + i].typeP == VIDE) && (plateau[numPawn->c - i][numPawn->l + i].typeP == VIDE)) {
				numB.c = numPawn->c - i;
				numB.l = numPawn->l;
				playable_point(ig,numB,playable);
			}
		}
		if ((i == 0) && (plateau[numPawn->c][numPawn->l + j].typeP == VIDE) && (numPawn->l + j < 6)) {

			if ((plateau[numPawn->c + j][numPawn->l].typeP == VIDE) && (plateau[numPawn->c + j][numPawn->l + j ].typeP == VIDE)) {
				numB.c = numPawn->c;
				numB.l = numPawn->l + j;
				playable_point(ig,numB,playable);
			}

			if ((plateau[numPawn->c - j][numPawn->l].typeP == VIDE) && (plateau[numPawn->c - j][numPawn->l + j].typeP == VIDE)) {
				numB.c = numPawn->c;
				numB.l = numPawn->l + j;
				playable_point(ig,numB,playable);
			}
		}
		if (( j == 0) && (plateau[numPawn->c + i][numPawn->l].typeP == VIDE) && (numPawn->c + i < 6)) {

			if ((plateau[numPawn->c][numPawn->l + i].typeP == VIDE) && (plateau[numPawn->c + i][numPawn->l + i].typeP == VIDE)) {
				numB.c = numPawn->c + i;
				numB.l = numPawn->l;
				playable_point(ig,numB,playable);
			}
			if ((plateau[numPawn->c][numPawn->l - i].typeP == VIDE) && (plateau[numPawn->c + i][numPawn->l - i].typeP == VIDE)) {
				numB.c = numPawn->c + i;
				numB.l = numPawn->l;
				playable_point(ig,numB,playable);
			}
		}
	}

	if (verif_lisere == 2) {
		playable = false;
		if ((plateau[numPawn->c - i ][numPawn->l - j].typeP == VIDE) && (numPawn->c - i >= 0) && (numPawn->l - j >= 0)){
				numB.c = numPawn->c - i;
				numB.l = numPawn->l - j;
				playable_point(ig,numB,playable);
		}
		if ((plateau[numPawn->c + i ][numPawn->l + j].typeP == VIDE) && (numPawn->c + i < 6) && (numPawn->l + j < 6)){
			numB.c = numPawn->c + i;
			numB.l = numPawn->l + j;
			playable_point(ig,numB,playable);
		}
		if ((plateau[numPawn->c + i ][numPawn->l - j].typeP == VIDE) && (numPawn->c + i < 6) && (numPawn->l - j >= 0)){
			numB.c = numPawn->c + i;
			numB.l = numPawn->l - j;
			playable_point(ig,numB,playable);
		}
		if ((plateau[numPawn->c - i ][numPawn->l + j].typeP == VIDE) && (numPawn->c - i >= 0) && (numPawn->l + j < 6)){
			numB.c = numPawn->c - i;
			numB.l = numPawn->l + j;
			playable_point(ig,numB,playable);
		}
	}
	if (verif_lisere == nb_lisere){
		playable = true;
		////////////////


		if ((plateau[numPawn->c][numPawn->l - 1].typeP == VIDE) && (numPawn->l - j >= 0)){
			if((plateau[numPawn->c][numPawn->l - 2].typeP == VIDE) && (i==0)) {
				numB.c = numPawn->c;
				numB.l = numPawn->l - j;
				playable_point(ig,numB,playable);
			}
			if (plateau[numPawn->c - 1][numPawn->l - 1].typeP == VIDE) {
				numB.c = numPawn->c - i;
				numB.l = numPawn->l - j;
				playable_point(ig,numB,playable);
			}
			if (plateau[numPawn->c + 1][numPawn->l - 1].typeP == VIDE) {
				numB.c = numPawn->c + i;
				numB.l = numPawn->l - j;
				playable_point(ig,numB,playable);
			}
		}
		if ((plateau[numPawn->c][numPawn->l + 1].typeP == VIDE) && (numPawn->l + j < 6)){
				if ((plateau[numPawn->c][numPawn->l + 2].typeP == VIDE) && (i==0)) {
					numB.c = numPawn->c;
					numB.l = numPawn->l + j;
					playable_point(ig,numB,playable);
				}
				if (plateau[numPawn->c - 1][numPawn->l + 1].typeP == VIDE) {
					numB.c = numPawn->c - i;
					numB.l = numPawn->l + j;
					playable_point(ig,numB,playable);
				}
				if (plateau[numPawn->c + 1][numPawn->l + 1].typeP == VIDE) {
					numB.c = numPawn->c + i;
					numB.l = numPawn->l + j;
					playable_point(ig,numB,playable);
				}
			}
			if ((plateau[numPawn->c + 1][numPawn->l].typeP == VIDE) && (numPawn->c + i < 6)) {
				if ((plateau[numPawn->c + 2][numPawn->l].typeP == VIDE)  && (j==0)) {
					numB.c = numPawn->c + i;
					numB.l = numPawn->l;
					playable_point(ig,numB,playable);
				}
				if (plateau[numPawn->c + 1][numPawn->l + 1].typeP == VIDE) {
					numB.c = numPawn->c + i;
					numB.l = numPawn->l + j;
					playable_point(ig,numB,playable);
				}
				if (plateau[numPawn->c + 1][numPawn->l - 1].typeP == VIDE) {
					numB.c = numPawn->c + i;
					numB.l = numPawn->l - j;
					playable_point(ig,numB,playable);
				}
			}
			if ((plateau[numPawn->c - 2][numPawn->l].typeP == VIDE)  && (j==0)) {
				numB.c = numPawn->c - i;
				numB.l = numPawn->l;
				playable_point(ig,numB,playable);
			}
			if (plateau[numPawn->c - 1][numPawn->l - 1].typeP == VIDE) {
				numB.c = numPawn->c - i;
				numB.l = numPawn->l - j;
				playable_point(ig,numB,playable);
			}
			if (plateau[numPawn->c - 1][numPawn->l + 1].typeP == VIDE) {
				numB.c = numPawn->c - i;
				numB.l = numPawn->l + j;
				playable_point(ig,numB,playable);
			}
	}
}


void playable_point(int ig,NUMBOX numB,int playable){

	if (playable == true) {
		plateau[numB.c][numB.l].coulP = PLAYABLE;
	} else if (playable == false){
		plateau[numB.c][numB.l].coulP = UNPLAYABLE;
	}

	if (plateau[numB.c][numB.l].coulP == PLAYABLE) {
		draw_fill_circle_from_numb(numB, 41, red, ig);
	} else if (plateau[numB.c][numB.l].coulP == UNPLAYABLE){
		draw_fill_circle_from_numb(numB, 41, yellow, ig);
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
}

void draw_circle_from_numb(NUMBOX numB, int radius, int color, int ig){

	POINT P;

	if (ig == 1) {
		P = numBox_to_pointBG_ig1(numB);
	} else if (ig == 2) {
		P = numBox_to_pointBG_ig2(numB);
	}
	draw_circle(P, radius, color);

}

void draw_fill_circle_from_numb(NUMBOX numB, int radius, int color, int ig){

	POINT P;

	if (ig == 1) {
		P = numBox_to_pointBG_ig1(numB);
	} else if (ig == 2) {
		P = numBox_to_pointBG_ig2(numB);
	}
	draw_fill_circle(P, radius, color);

}


void victory_screen(int gagnant){
	POINT P;

	int colors_pink[] = {deeppink, darkviolet, fuchsia, lightpink, mediumpurple};
	int colors_blue[] = {blueviolet, aqua, aquamarine, azure, aliceblue};
	int i;
	// int sens = true;
	int vPos = 0, cPos = WIDTH;

	// while(true){
		// sens = !sens;

		for (i = 0; i < WIDTH; i+=15) {

			affiche_auto_off();

			fill_screen(cyan);

			for(int j = 0; j < 5; j++){
				vPos += 1;
				P.x = vPos;
				P.y = HEIGHT/2 + j*2;
				aff_pol("VICTOIRE ROYALE", 70, P, colors_pink[j]);

				cPos -= 1;
				P.x = cPos;
				P.y = HEIGHT/2 + j*2;
				aff_pol("VICTOIRE ROYALE", 70, P, colors_blue[j]);
			}

			P.x = WIDTH / 6;
			P.y = HEIGHT/2 + 50;
			aff_pol("NOIR A GAGNE", 80, P, deeppink);
			P.y = HEIGHT/2 - 10;
			aff_pol("ON A RIEN PU FAIRE", 30, P, fuchsia);


			affiche_all();
			attendre(25);
		}
	// }

	affiche_auto_on();
	fill_screen(black);
}
