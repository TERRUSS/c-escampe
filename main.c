
#include "utils/types.h"
#include "utils/init.h"
#include "display/display.h"


int main() {
	// COUL Joueur;
	// char restart;
	int ig;

	init_plateau();
	//pions independants de la vue
	init_piece1_debug();

	init_graphics(900, 900);

	splash_screen();

	ig = select_view();

	affiche_auto_off();
	affiche_plateau(ig);

	while (true) {

		affiche_auto_off();
		update_board(ig);
		affiche_all();

		affiche_auto_on();
		move(ig);
	}
}
