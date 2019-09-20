
#include "utils/types.h"
#include "utils/init.h"
#include "display/display.h"


/*
POINT numBox_to_pointBG_ig1 (NUMBOX numB);

POINT numBox_to_pointBG_ig1 (NUMBOX numB){

}

POINT numBox_to_pointBG_ig2 (NUMBOX numB);

POINT numBox_to_pointBG_ig2 (NUMBOX numB){

}

NUMBOX point_ig1_to_numBox (POINT P);

NUMBOX point_ig1_to_numBox (POINT P){

}

NUMBOX point_ig2_to_numBox (POINT P);

NUMBOX point_ig2_to_numBox (POINT P){

}
*/


int main() {
	COUL Joueur;
	char restart;
	int ig = 0;
	POINT clic1, clic2;

	init_graphics(900, 900);
	splash_screen();

	while (true) {

		affiche_auto_off();

		// ig = select_view();
		clic1=wait_clic();

		affiche_plateau(ig);
		clic2=wait_clic();

		affiche_all();

	}
}
