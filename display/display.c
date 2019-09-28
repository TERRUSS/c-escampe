
#include <stdio.h>
#include "display.h"

void affiche_plateau(int ig) { //TODO : variation

	draw_board_grid(ig);
	print_ruler();

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
	} else if (coulP == NOIR){
		draw_fill_circle(bg, 40, black);
	}
	draw_fill_circle(bg, 15, blueviolet);
}

void affiche_paladin (POINT bg, COUL coulP){
	if (coulP == BLANC) {
		draw_fill_circle(bg, 40, white);
	} else if (coulP == NOIR){
		draw_fill_circle(bg, 40, black);
	}
	draw_fill_circle(bg, 15, deeppink);
}

void affiche_vide (){
	int i, j;
	NUMBOX numB;

	affiche_auto_off();

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (plateau[i][j].coulP == NONE || plateau[i][j].playP == PLAYABLE || plateau[i][j].playP == UNPLAYABLE ) {
				numB.c = i;
				numB.l = j;
				draw_fill_circle_from_numb(numB, 50, cyan, 1);
			}
		}
	}

	affiche_all();
}

void calcule_pm(NUMBOX numB){
	int i, x, y;
	int pm = plateau[numB.c][numB.l].lisere;

		//clean
	for (x = 0; x < 6; x++) {
		for (y = 0; y < 6; y++) {
			plateau[x][y].tmp_play = 0;
		}
	}

	printf("--- [%d %d]\n", numB.c, numB.l);

	expand(numB.c, numB.l, 1);

	for (i = 2; i <= pm; i++){

		for (x = 0; x < 6; x++) {
			for (y = 0; y < 6; y++) {
				if (plateau[x][y].tmp_play == i-1 ){
						expand(x, y, i);
					printf("CHECKING [%d %d]\n", x, y);
				}
			}
		}

	}
}

void expand(int x, int y, int i) {
	if (x+1 < 6) {
		if (plateau[x+1][y].typeP == VIDE) {
			if(plateau[x][y].tmp_play == 2 && plateau[x+1][y].tmp_play == 1){
				if ( is_surrounded_by_1(x+1, y)){
					plateau[x+1][y].tmp_play = i;
				}
			} else {
				plateau[x+1][y].tmp_play = i;
			}
		}
	}

	if (x-1 >= 0) {
		if (plateau[x-1][y].typeP == VIDE) {
			if(plateau[x][y].tmp_play == 2 && plateau[x-1][y].tmp_play == 1){
				if ( is_surrounded_by_1(x-1, y)){
					plateau[x-1][y].tmp_play = i;
				}
			} else {
				plateau[x-1][y].tmp_play = i;
			}
		}
	}

	if (y+1 < 6) {
		if (plateau[x][y+1].typeP == VIDE) {
			if(plateau[x][y].tmp_play == 2 && plateau[x][y+1].tmp_play == 1){
				if ( is_surrounded_by_1(x, y+1)){
					plateau[x][y+1].tmp_play = i;
				}
			} else {
				plateau[x][y+1].tmp_play = i;
			}
		}
	}

			if (y-1 >= 0) {
		if (plateau[x][y-1].typeP == VIDE) {
			if(plateau[x][y].tmp_play == 2 && plateau[x][y-1].tmp_play == 1){
				if ( is_surrounded_by_1(x, y-1)){
					plateau[x][y-1].tmp_play = i;
				}
			} else {
				plateau[x][y-1].tmp_play = i;
			}
		}
	}

}

int is_surrounded_by_1(int x, int y) {

	if (plateau[x+1][y+1].tmp_play == 1){
		return 1;
	}
	if (plateau[x+1][y-1].tmp_play == 1){
		return 1;
	}
	if (plateau[x-1][y+1].tmp_play == 1){
		return 1;
	}
	if (plateau[x-1][y-1].tmp_play == 1){
		return 1;
	}

printf("surrounding check : [%d %d] is alone", x, y);
	return 0;
}

void affiche_pm(int ig){
	int i, j, pm = 0;
	NUMBOX numB;

	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){
			if (plateau[i][j].tmp_play > pm){
				pm = plateau[i][j].tmp_play;
			}
			printf(" %d ", plateau[i][j].tmp_play);
		}
		printf("\n");
	}

	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){
			if (plateau[i][j].tmp_play == pm){
				numB.c = i;
				numB.l = j;
				playable_point(ig,numB,true);
			}
		}
	}
}


void playable_point(int ig,NUMBOX numB,int playable){

	if (playable == true) {
		plateau[numB.c][numB.l].playP = PLAYABLE;
	}
	if (plateau[numB.c][numB.l].playP == PLAYABLE) {
		draw_fill_circle_from_numb(numB, 41, red, ig);
	}
}
