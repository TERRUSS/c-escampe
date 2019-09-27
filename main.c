
#include "utils/types.h"
#include "utils/init.h"
#include "strategy/start.h"
#include "display/display.h"


int main() {
	int ig, currentPlayer = 0, gagnant = false, replay;

	init_plateau();
	init_piece2_debug();

	init_graphics(900, 900);

	splash_screen();
	select_player();

	ig = select_view();

	affiche_plateau(ig);
	affiche_auto_off();

	//init plateau
	// select_pawn_position(ig);


	while (gagnant == false) {

		affiche_auto_off();

		init_play();

		update_board(ig);
		update_player(currentPlayer, ig);

		affiche_all();


		affiche_auto_on();

		replay = move(ig, currentPlayer);

		affiche_vide();

		gagnant = get_winner(currentPlayer);

		if (replay == false) {
			currentPlayer = !currentPlayer;
		}else{
			currentPlayer = currentPlayer;
		}

	}
	// */
	victory_screen(currentPlayer);

	return 0;
}

/*
	TODO LIST :
		> clean display/display.c/affiche_pm()
*/
