
#include "utils/types.h"
#include "utils/init.h"
#include "display/display.h"


int main() {
	// COUL Joueur;
	// char restart;
	int ig, currentPlayer = true, gagnant = false;
	POINT pawn;
	NUMBOX numPawn;


	init_plateau();
	//pions independants de la vue
	init_piece2_debug();

	init_graphics(900, 900);

	// /*
	splash_screen();
	currentPlayer = select_player();

	ig = select_view();

	affiche_auto_off();
	affiche_plateau(ig);


	while (gagnant == false) {

		affiche_auto_off();

		update_board(ig,&pawn);
		update_player(currentPlayer, ig);

		affiche_all();



		affiche_auto_on();

		move(ig, currentPlayer, &pawn, &numPawn);
		// gagnant = get_winner(currentPlayer);


		currentPlayer = !currentPlayer;
	}
	// */
	victory_screen(gagnant);

	return 0;
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

/*
void compute_pm(NUMBOX numPawn, int ig){

	int i, j;
	int nb = plateau[numPawn->c][numPawn->l].lisere;

	for (i = 0; i < nb; i++){
		for (j = 0; j < nb; i++){

		}
	}
}
// */
