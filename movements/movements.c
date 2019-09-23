
#include "movements.h"

void move (int ig){
	POINT P, pawn;
	NUMBOX numB,numPawn;

		//selction du pion
	hint_message("Selectionne le pion");
	pawn = wait_clic();

	if (ig == 1) {

		numPawn = point_ig1_to_numBox(pawn);

		if (plateau[numPawn.c][numPawn.l].typeP != VIDE  ) {

			hint_message("Selectionne le deplacement");

			P = wait_clic();
			numB = point_ig1_to_numBox(P);

			plateau[numB.c][numB.l].typeP = plateau[numPawn.c][numPawn.l].typeP;
			plateau[numB.c][numB.l].coulP = plateau[numPawn.c][numPawn.l].coulP;
			plateau[numPawn.c][numPawn.l].typeP = VIDE;

			affiche_vide( numBox_to_pointBG_ig1(numPawn) );
		}else{
			hint_message("éééééé no way éééééé");
			wait_clic();
		}

	} else {

		numPawn = point_ig2_to_numBox(pawn);

		if (plateau[numPawn.c][numPawn.l].typeP != VIDE  ) {

			hint_message("Selectionne le deplacement");

			P = wait_clic();
			numB = point_ig2_to_numBox(P);

			plateau[numB.c][numB.l].typeP = plateau[numPawn.c][numPawn.l].typeP;
			plateau[numB.c][numB.l].coulP = plateau[numPawn.c][numPawn.l].coulP;
			plateau[numPawn.c][numPawn.l].typeP = VIDE;

			affiche_vide( numBox_to_pointBG_ig2(numPawn) );
		}else{
			hint_message("éééééé no way éééééé");
			wait_clic();
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

	numB.l = (( P.y - (offset/2))/offset);
	numB.c = 5-(( P.x - (offset/2))/offset);

	return numB;
}
