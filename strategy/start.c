
#include <stdio.h>
#include "../utils/types.h"
#include "start.h"


int get_winner(int player){

	int i, j;

	printf("player %d\n", player);

	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (plateau[i][j].typeP == LICORNE) {
				if (plateau[i][j].coulP == player + 1){
					return 0;
				}
			}
		}
	}

	return player + 1;
}
