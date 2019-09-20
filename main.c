
#include "utils/types.h"
#include "utils/init.h"
#include "display/display.h"


int main() {
	// COUL Joueur;
	// char restart;
	int ig;

	init_plateau();
	init_piece2_debug();

	init_graphics(900, 900);

	// splash_screen();

	ig = select_view();

	while (true) {

		affiche_auto_off();

		affiche_plateau(ig);

		affiche_all();

		// clic2=wait_clic();
	}
}


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
