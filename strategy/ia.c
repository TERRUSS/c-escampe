#include "ia.h"

void ia_player(int ia_color, int * turn_pm){

	int i, j, x, y;
	int nPlayablePawns = 0, nPlayableMoves = 0,playablePawns=0, playableMoves=0;
	int randomPawn, randomMove;
	NUMBOX numB, numPawn;

		// On veut manger la licorne adverse
  for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {

			if (plateau[i][j].lisere == *turn_pm){
				if (plateau[i][j].coulP == ia_color){

					for (x = 0; x < 6; x++) {
						for (y = 0; y < 6; y++) {
							plateau[x][y].playP = UNPLAYABLE;
						}
					}

					nPlayablePawns++;

	        numPawn.c=i;
	        numPawn.l=j;
	      	calcule_pm(numPawn, (ia_color-1));

					for (x = 0; x < 6; x++) {
						for (y = 0; y < 6; y++) {
							if (plateau[x][y].playP == PLAYABLE && plateau[x][y].typeP == LICORNE && plateau[x][y].coulP != ia_color) {

                numB.c=x;
                numB.l=y;

                plateau[numB.c][numB.l].typeP = plateau[numPawn.c][numPawn.l].typeP;
                plateau[numB.c][numB.l].coulP = plateau[numPawn.c][numPawn.l].coulP;
                plateau[numPawn.c][numPawn.l].typeP = VIDE;
                plateau[numPawn.c][numPawn.l].coulP = NONE;

                affiche_vide( numBox_to_pointBG_ig1(numPawn));

                *turn_pm = plateau[numB.c][numB.l].lisere;
								return;
							}
						}
					}

					for (x = 0; x < 6; x++) {
						for (y = 0; y < 6; y++) {
							plateau[x][y].playP = UNPLAYABLE;
            }
					}
				}
			}
		}
  }


		//Si on ne peut pas finir, on fait un coup au hasard
	randomPawn = nPlayablePawns ? (myrand() % (nPlayablePawns)) : 0;
  playablePawns=0;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (plateau[i][j].lisere == *turn_pm) {
				if (plateau[i][j].coulP == ia_color && plateau[i][j].typeP != VIDE){


	        if (playablePawns == randomPawn) {
						numB.c=i;
		        numB.l=j;

						for (x = 0; x < 6; x++) {
							for (y = 0; y < 6; y++) {
								plateau[x][y].playP = UNPLAYABLE;
	            }
						}

		      	calcule_pm(numB, (ia_color-1));

						//on compte le nombre de coups possibles à partir du pion
						for (x = 0; x < 6; x++) {
							for (y = 0; y < 6; y++) {
								if (plateau[x][y].playP == PLAYABLE) {
									nPlayableMoves++;
								}
							}
						}

						//on joue un coup au hasard
						randomMove = nPlayableMoves ? (myrand() % (nPlayableMoves)) : 0;
            playableMoves=0;
						for (x = 0; x < 6; x++) {
							for (y = 0; y < 6; y++) {
								if (plateau[x][y].playP == PLAYABLE) {

									if (playableMoves == randomMove){
										numB.c=x;
										numB.l=y;

										plateau[numB.c][numB.l].typeP = plateau[numPawn.c][numPawn.l].typeP;
										plateau[numB.c][numB.l].coulP = plateau[numPawn.c][numPawn.l].coulP;
										plateau[numPawn.c][numPawn.l].typeP = VIDE;
										plateau[numPawn.c][numPawn.l].coulP = NONE;

										affiche_vide( numBox_to_pointBG_ig1(numPawn));

										*turn_pm = plateau[numB.c][numB.l].lisere;
										return;
									}
									playableMoves++;
								}
							}
						}
					}
          playablePawns++;
				}
			}
		}
  }
}
