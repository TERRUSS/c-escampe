
#include "utils/types.h"
#include "utils/init.h"
#include "strategy/start.h"
#include "display/display.h"
#include "strategy/ia.h"


int main() {
	int ig, currentPlayer = 0, gagnant = false;
	int replay = false, mode;
	int next_turn_pm;
	int color, ia_color;

	init_plateau();
	//init_piece2_debug();
	init_graphics(900, 900);
	affiche_auto_off();

	splash_screen();

	mode = select_player(&color);
	ig = select_view();

	affiche_plateau(ig);
	select_pawn_position(ig);

	if (color == 1) {
		ia_color = BLANC;
	}else{
		ia_color = NOIR;
	}


	while (gagnant == false) {

		init_play();

		update_board(ig);
		update_player(currentPlayer, ig, next_turn_pm);

		affiche_all();


		if ((mode == 2) && (currentPlayer == ia_color-1)) {
			ia_player(ia_color, &next_turn_pm);
		}else{

			replay = move(ig, currentPlayer, &next_turn_pm);

		}

		affiche_vide();

		gagnant = get_winner(currentPlayer);

		if (replay == false) {
			currentPlayer = !currentPlayer;
		}
	}

	victory_screen(currentPlayer);

	return 0;
}
