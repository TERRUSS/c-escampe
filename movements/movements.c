
#include "movements.h"

void move (int ig, int player, POINT* pawn, NUMBOX* numPawn){

		//selction du pion
	hint_message("Selectionne le pion");

	select_pawn(ig, pawn, numPawn, player);
	printf("c l-1: %d\n",plateau[numPawn->c][numPawn->l - 1].typeP );
	printf("c l+1: %d\n",plateau[numPawn->c][numPawn->l + 1].typeP );
	printf("c-1 l: %d\n",plateau[numPawn->c - 1][numPawn->l].typeP );
	printf("c+1 l: %d\n",plateau[numPawn->c + 1][numPawn->l].typeP );

	select_deplacement(ig, pawn, numPawn);

	reset_playable_map();
}


void select_pawn (int ig, POINT* pawn, NUMBOX* numPawn, int player){
	int couleur;
	do {
		*pawn = wait_clic();

		if (ig == 1) {
			*numPawn = point_ig1_to_numBox(*pawn);
		} else {
			*numPawn = point_ig2_to_numBox(*pawn);
		}
		if (player == 0) {
			couleur = NOIR;
		}else{
			couleur = BLANC;
		}
	} while(plateau[numPawn->c][numPawn->l].coulP == couleur);

	affiche_pm(numPawn, ig);
}



void select_deplacement( int ig, POINT *pawn, NUMBOX *numPawn ) {
	POINT P;
	NUMBOX numB;

	if (ig == 1) {
		*numPawn = point_ig1_to_numBox(*pawn);
	} else {
		*numPawn = point_ig2_to_numBox(*pawn);
	}
	printf(" c:%d l:%d \n",numPawn->c,numPawn->l);
	if (plateau[numPawn->c][numPawn->l].typeP != VIDE  ) {

		hint_message("Selectionne le deplacement");

		do {
			P = wait_clic();
		} while (!deplacement_is_valid(P, ig));

		if (ig ==1) {
			numB = point_ig1_to_numBox(P);
		} else {
			numB = point_ig2_to_numBox(P);
		}

		plateau[numB.c][numB.l].typeP = plateau[numPawn->c][numPawn->l].typeP;
		plateau[numB.c][numB.l].coulP = plateau[numPawn->c][numPawn->l].coulP;
		plateau[numPawn->c][numPawn->l].typeP = VIDE;
		plateau[numPawn->c][numPawn->l].coulP = NONE;

		affiche_vide( numBox_to_pointBG_ig1(*numPawn));
	}else{

		hint_message("éééééé no way éééééé");
		attendre(500);
	}
}

void reinit_select_pawn(int ig, POINT* pawn, NUMBOX* numPawn, int player) {

	if (P.x > WIDTH-WIDTH/7 && P.y > HEIGHT - HEIGHT/7) {
		reset_playable_map();
		affiche_vide();
		select_pawn(ig, pawn, numPawn, player);
	}
}

int deplacement_is_valid(POINT P, int ig){

	if (P.x > WIDTH/7 && P.x < WIDTH - WIDTH/7 && P.y > HEIGHT/7 && P.y < HEIGHT - HEIGHT/7){
		NUMBOX newPosition;

		if (ig ==1) {
			newPosition = point_ig1_to_numBox(P);
		} else {
			newPosition = point_ig2_to_numBox(P);
		}

		if ( plateau[newPosition.c][newPosition.l].coulP == PLAYABLE ) {
			return 1;
		} else {
			return 0;
		}

	} else {
		return 0;
	}
}

void reset_playable_map(){
	int i, j;

	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){
			if (plateau[i][j].coulP == PLAYABLE || plateau[i][j].coulP == UNPLAYABLE){
				plateau[i][j].coulP = VIDE;
			}
		}
	}
}

POINT numBox_to_pointBG_ig1 (NUMBOX numB){
	int offset = WIDTH / 14;
	POINT pointBG;

	pointBG.x = (offset * 2) + (offset * 2) * numB.l;
	pointBG.y = (offset * 2) + (offset * 2) * numB.c;
	return pointBG;
}

POINT numBox_to_pointBG_ig2 (NUMBOX numB){
	int offset = WIDTH / 14;
	POINT pointBG;

	pointBG.x = HEIGHT - 4 - ((offset * 2) + (offset * 2) * numB.c);
	pointBG.y = WIDTH - 4 - ((offset * 12) - (offset * 2) * numB.l);

	return pointBG;
}

NUMBOX point_ig1_to_numBox (POINT P){
	int offset = WIDTH / 7;
	NUMBOX numB;

	numB.l = ( P.x - (offset/2))/offset;
	numB.c = ( P.y - (offset/2))/offset;

	return numB;
}

NUMBOX point_ig2_to_numBox (POINT P){
	int offset = WIDTH / 7;
	NUMBOX numB;

	numB.l = 5-(( P.x - (offset/2))/offset);
	numB.c = (( P.y - (offset/2))/offset);

	return numB;
}
