
#include "movements.h"

int move (int ig, int player){

 NUMBOX numPawn;
 int replay = false;

		//selction du pion
	numPawn = select_pawn(ig, player);

	replay = select_deplacement(ig, numPawn, player);

	reset_playable_map();

  return replay;
}


NUMBOX select_pawn (int ig, int player){
	int couleur, ok;
	POINT P;
	NUMBOX numPawn;


	do {
		hint_message("Selectionne le pion");

		P = wait_clic();

		if (ig == 1) {
			numPawn = point_ig1_to_numBox(P);
		} else {
			numPawn = point_ig2_to_numBox(P);
		}

		if (player == 1) {
			couleur = NOIR;
		}else{
			couleur = BLANC;
		}

		ok = false;

		if (plateau[numPawn.c][numPawn.l].typeP != VIDE) {
			if (plateau[numPawn.c][numPawn.l].coulP == couleur){
				ok = true;
				break;
			}
		} else {
			hint_message("éééééé no way éééééé");
			attendre(500);
		}
	} while(!ok);

	calcule_pm(numPawn);
	affiche_pm(ig);

	return numPawn;
}

int select_deplacement( int ig, NUMBOX numPawn, int player ) {
	POINT P;
	NUMBOX numB;

	hint_message("Selectionne le deplacement  [CHANGE]");

	// if (plateau[numPawn.c][numPawn.l].typeP != VIDE  ) {
	do {
		P = wait_clic();

		if (P.x > WIDTH-WIDTH/7 && P.y > HEIGHT - HEIGHT/7) {
      return true;
		}

	} while (!deplacement_is_valid(P, ig, player));

	if (ig ==1) {
		numB = point_ig1_to_numBox(P);
	} else {
		numB = point_ig2_to_numBox(P);
	}
	printf("1 :: l: %d c: %d %d %d\n",numB.c ,numB.l,plateau[numB.c][numB.l].typeP == VIDE,plateau[numB.c][numB.l].playP);

	plateau[numB.c][numB.l].typeP = plateau[numPawn.c][numPawn.l].typeP;
	plateau[numB.c][numB.l].coulP = plateau[numPawn.c][numPawn.l].coulP;
	plateau[numPawn.c][numPawn.l].typeP = VIDE;
	plateau[numPawn.c][numPawn.l].coulP = NONE;
	printf("2 :: l: %d c: %d %d %d\n",numPawn.c ,numPawn.l,plateau[numPawn.c][numPawn.l].typeP == VIDE,plateau[numPawn.c][numPawn.l].playP);

	affiche_vide( numBox_to_pointBG_ig1(numPawn));
  return false;
}
	// }else{

		// hint_message("éééééé no way éééééé");
		// attendre(500);
	// }


int deplacement_is_valid(POINT P, int ig, int player){

	if (P.x > WIDTH/7 && P.x < WIDTH - WIDTH/7 && P.y > HEIGHT/7 && P.y < HEIGHT - HEIGHT/7){
		NUMBOX newPosition;

		if (ig ==1) {
			newPosition = point_ig1_to_numBox(P);
		} else {
			newPosition = point_ig2_to_numBox(P);
		}

		if ( plateau[newPosition.c][newPosition.l].playP == PLAYABLE ) {
			return 1;
		} else {
			return 0;
		}
	} else {
		return 0;
	}
	return 0;
}

void reset_playable_map(){
	int i, j;

	for (i = 0; i < 6; i++){
		for (j = 0; j < 6; j++){

			plateau[i][j].playP = UNPLAYABLE;

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
