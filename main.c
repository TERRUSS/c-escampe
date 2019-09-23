
#include "utils/types.h"
#include "utils/init.h"
#include "display/display.h"


int main() {
	// COUL Joueur;
	// char restart;
	int ig, player = true;
	int player_1;
	int player_2;

	init_plateau();
	//pions independants de la vue
	init_piece1_debug();

	init_graphics(900, 900);

	splash_screen();

	select_player(&player_1 , &player_2);

	if (player_1 == 1) {
		player = 1;
	} else {
		player = 0;
	}

	ig = select_view();

	affiche_auto_off();
	affiche_plateau(ig);

	while (true) {

		affiche_auto_off();

		update_board(ig);
		update_player(player);

		affiche_all();

		affiche_auto_on();
		move(ig,player);

		player = !player;
	}
}
