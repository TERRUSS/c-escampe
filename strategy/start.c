
#include "strat.h"

int get_winner(int player){

	for (i = 0; i < 6; i++0) {
		for (i = 0; i < 6; i++0) {
			if (plateau[i][j].typeP == LICORNE) {
				if (plateau[i][j].coulP == player + 1){
					printf("Winner : player %d\n", player);
					return player;
				}
			}
		}
	}

	return false;
}
