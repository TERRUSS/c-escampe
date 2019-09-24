
#include "utils/types.h"
#include "utils/init.h"
#include "display/display.h"


int main() {
	// COUL Joueur;
	// char restart;
	int ig, player = true;
	int player_1;
	int player_2;
	POINT pawn;
	NUMBOX numPawn;


	init_plateau();
	//pions independants de la vue
	init_piece1_debug();

	init_graphics(900, 900);

	splash_screen();

	select_player(&player_1 , &player_2);

	if (player_1 == 0) {
		player = 1;
	} else {
		player = 0;
	}

	ig = select_view();

	affiche_auto_off();
	affiche_plateau(ig);

	while (true) {

		affiche_auto_off();

		update_board(ig,&pawn);
		update_player(player, ig);

		affiche_all();



		affiche_auto_on();

		move(ig, player, &pawn, &numPawn);

		player = !player;
	}
}

/*
	TODO LIST :
		> clean display/display.c/affiche_pm()


		chez nous le langage
		C'est une coutume
		Mon papa fait la variable
		Ma maman fait le printf
		Et l'curé le pointeur

		Chez nous la méca
		c'est une coutume
		Mon papa fait la bielette
		Ma maman fait l'engrenage
		Et le curé la branle

		Chez nous les sciences
		c'est une coutume
		mon papa fait la physique
		ma maman fait le chimie
		et le curé la mathe

		Chez nous les voitures
		c'est une coutume
		Mon papa fait le cartere
		Ma maman fait l'embrayge
		Et l'curé la démonte
*/
