
#include "init.h"
#include "../movements/movements.h"

void init_plateau(){

	int i, j;

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			plateau[i][j].typeP = VIDE;
		}
	}

	plateau[0][0].lisere=3;plateau[0][4].lisere=3;plateau[1][1].lisere=3;plateau[1][3].lisere=3;plateau[2][2].lisere=3;plateau[2][4].lisere=3;plateau[3][1].lisere=3;plateau[3][5].lisere=3;plateau[4][0].lisere=3;plateau[4][2].lisere=3;plateau[4][4].lisere=3;plateau[5][3].lisere=3;
	plateau[0][1].lisere=2;plateau[0][2].lisere=2;plateau[0][5].lisere=2;plateau[1][5].lisere=2;plateau[2][0].lisere=2;plateau[2][3].lisere=2;plateau[3][0].lisere=2;plateau[3][3].lisere=2;plateau[4][5].lisere=2;plateau[5][1].lisere=2;plateau[5][2].lisere=2;plateau[5][5].lisere=2;
	plateau[0][3].lisere=1;plateau[1][0].lisere=1;plateau[1][2].lisere=1;plateau[1][4].lisere=1;plateau[2][1].lisere=1;plateau[2][5].lisere=1;plateau[3][2].lisere=1;plateau[3][4].lisere=1;plateau[4][1].lisere=1;plateau[4][3].lisere=1;plateau[5][0].lisere=1;plateau[5][4].lisere=1;
}

void init_play(){
	int i, j;

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			plateau[i][j].playP=UNPLAYABLE;
			if ((plateau[i][j].coulP != NOIR) && (plateau[i][j].coulP != BLANC)) {
				plateau[i][j].typeP = VIDE;
			}
		}
	}
}


void init_piece1_debug(){
	plateau[0][2].typeP=PALADIN;plateau[0][2].coulP=NOIR;
	plateau[0][4].typeP=PALADIN;plateau[0][4].coulP=NOIR;
	plateau[1][0].typeP=PALADIN;plateau[1][0].coulP=NOIR;
	plateau[1][2].typeP=PALADIN;plateau[1][2].coulP=NOIR;
	plateau[1][5].typeP=PALADIN;plateau[1][5].coulP=NOIR;
	plateau[1][1].typeP=LICORNE;plateau[1][1].coulP=NOIR;
	plateau[4][4].typeP=PALADIN;plateau[4][4].coulP=BLANC;
	plateau[4][3].typeP=PALADIN;plateau[4][3].coulP=BLANC;
	plateau[4][1].typeP=PALADIN;plateau[4][1].coulP=BLANC;
	plateau[5][1].typeP=PALADIN;plateau[5][1].coulP=BLANC;
	plateau[5][2].typeP=PALADIN;plateau[5][2].coulP=BLANC;
	plateau[5][3].typeP=LICORNE;plateau[5][3].coulP=BLANC;
}

void init_piece2_debug(){
	plateau[5][5].typeP=PALADIN;plateau[5][5].coulP=NOIR;
	plateau[4][5].typeP=PALADIN;plateau[4][5].coulP=NOIR;
	plateau[3][5].typeP=LICORNE;plateau[3][5].coulP=NOIR;
	plateau[2][5].typeP=PALADIN;plateau[2][5].coulP=NOIR;
	plateau[1][5].typeP=PALADIN;plateau[1][5].coulP=NOIR;
	plateau[0][5].typeP=PALADIN;plateau[0][5].coulP=NOIR;
	plateau[0][0].typeP=LICORNE;plateau[0][0].coulP=BLANC;
	plateau[5][0].typeP=PALADIN;plateau[5][0].coulP=BLANC;
	plateau[4][0].typeP=PALADIN;plateau[4][0].coulP=BLANC;
	plateau[2][0].typeP=PALADIN;plateau[2][0].coulP=BLANC;
	plateau[1][0].typeP=PALADIN;plateau[1][0].coulP=BLANC;
	plateau[3][0].typeP=PALADIN;plateau[3][0].coulP=BLANC;
}

void select_pawn_position(int ig){
	NUMBOX licorn;
	// NUMBOX Paladin;
	int i;

	hint_message("Joueur NOIR : Selectionne l'emplacement de la licorne");
	licorn = select_pawn(ig, 0);
	plateau[licorn.c][licorn.l].typeP = LICORNE;

	for (i = 0; i < 5; i++) {
		hint_message("Joueur NOIR : Selectionne l'emplacement du paladin");
		licorn = select_pawn(ig, 0);
		plateau[licorn.c][licorn.l].typeP = PALADIN;
	}

	hint_message("Joueur BLANC : Selectionne l'emplacement de la licorne");
	licorn = select_pawn(ig, 1);
	plateau[licorn.c][licorn.l].typeP = LICORNE;

	for (i = 0; i < 5; i++) {
		hint_message("Joueur BLANC : Selectionne l'emplacement du paladin");
		licorn = select_pawn(ig, 0);
		plateau[licorn.c][licorn.l].typeP = PALADIN;
	}
}
