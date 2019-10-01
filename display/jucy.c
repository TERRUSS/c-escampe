#include <stdio.h>
#include "jucy.h"

void splash_screen() {

	POINT P;

	int colors_pink[] = {deeppink, darkviolet, fuchsia, lightpink, mediumpurple};
	int colors_blue[] = {blueviolet, aqua, aquamarine, azure, aliceblue};
	int i;

	for (i = 0; i < HEIGHT + 100; i+=15) {

		affiche_auto_off();

		fill_screen(cyan);

		for(int j = 0; j < 5; j++){
			P.x = WIDTH / 2 - 300 + j*2;
			P.y = HEIGHT - i + j*10;
			aff_pol("NOUS SOMMES SUR LE", 40, P, colors_pink[j]);
			P.x = WIDTH / 2 - 200 + j*2;
			P.y = HEIGHT - i - 70 + j*10;
			aff_pol("SERVICE PUBLIC", 40, P, colors_blue[j]);
		}

		affiche_all();
		attendre(50);
	}

	affiche_auto_on();
	fill_screen(black);
}

int select_player(int* color){
	POINT P;
	int mode;

	fill_screen(cyan);

	P.x = 50;
	P.y = 600;
	aff_pol("MODE :", 40, P, deeppink);
	P.y = 400;

	P.x = 50;
	aff_pol("Player VS Player", 40, P, deeppink);

	P.x = WIDTH / 2 + 100;
	aff_pol("Player VS IA", 40, P, deeppink);
	while (true) {
		P=wait_clic();

		if ( 350 < P.y && P.y < 500 ) {
			if ( P.x < WIDTH/2) {
				mode = 1;
				break;
			} else {
				mode = 2;
				break;
			}
		}
	}
	affiche_all();

	loading_screen();

	screen_select_player(color);

	affiche_auto_on();
	fill_screen(black);
	return mode;
}

void loading_screen(){
	int i;
	for (i = 0; i < WIDTH + 100; i+=15) {

		affiche_auto_off();

		fill_screen(cyan);

		POINT P;

		P.x = WIDTH / 2 - 200;
		P.y = 600;
		aff_pol("Selection en cours...", 30, P, deeppink);

		P.x = 0 + i;
		P.y = HEIGHT - 400;
		aff_pol("éé load ... éé", 40, P, deeppink);

		affiche_all();
		attendre(20);
	}
	fill_screen(black);
}

void screen_select_player(int* color){
	int rand, player = 0;
	// player = 0;

	affiche_auto_off();

	fill_screen(cyan);

	POINT P;

	P.x = WIDTH / 2 - 200;
	P.y = 600;

	rand = myrand() % 2;
	*color = rand;

	if (rand == 1) {
		player = 1;
		aff_pol("Player 1: Player Black", 30, P, deeppink);
		P.y = 500;
		aff_pol("player 2: Player White", 30, P, deeppink);
	}else{
		player = 0;

		aff_pol("Player 1: Player White", 30, P, deeppink);
		P.y = 500;
		aff_pol("Player 2: Player Black", 30, P, deeppink);
	}

	affiche_all();
	attendre(1000);

	affiche_auto_on();
	fill_screen(black);

}

int select_view(){
	POINT P;
	// POINT clic;

	fill_screen(cyan);

	P.x = WIDTH / 2 - 300;
	P.y = 600;
	aff_pol("Selectionner le sens du plateau", 30, P, deeppink);

	P.y = 400;

	P.x = WIDTH / 4;
	aff_pol("Normal", 40, P, deeppink);

	P.x = WIDTH / 2 + 100;
	aff_pol("Tilted", 40, P, deeppink);

	P.x = 10;
	P.y = 20;
	aff_pol("Made with love by Terruss and Cousteau", 20, P, mediumpurple);
	while (true) {
		P=wait_clic();

		if ( 350 < P.y && P.y < 500 ) {
			if ( P.x < WIDTH/2) {
				return 1;
			} else {
				return 2;
			}
		}
	}

	// return 1;

}

void victory_screen(int player){
	POINT P;

	int colors_pink[] = {deeppink, darkviolet, fuchsia, lightpink, mediumpurple};
	int colors_blue[] = {blueviolet, aqua, aquamarine, azure, aliceblue};
	int i;
	// int sens = true;
	int vPos = 0, cPos = WIDTH;

		// sens = !sens;
		// while(true){

		for (i = 0; i < WIDTH*2; i+=15) {

			affiche_auto_off();

			fill_screen(cyan);

			for(int j = 0; j < 5; j++){
				vPos += 1;
				P.x = vPos;
				P.y = HEIGHT/2 + j*2;
				aff_pol("VICTOIRE ROYALE", 70, P, colors_pink[j]);

				cPos -= 1;
				P.x = cPos;
				P.y = HEIGHT/2 + j*2;
				aff_pol("VICTOIRE ROYALE", 70, P, colors_blue[j]);
			}

			P.x = WIDTH / 6;
			P.y = HEIGHT/2 + 50;
			if (player == 1) {
				aff_pol("NOIR A GAGNE", 80, P, deeppink);
			} else if (player == 0){
				aff_pol("BLANC A GAGNE", 80, P, deeppink);
			}
			P.y = HEIGHT/2 - 10;
			aff_pol("ON A RIEN PU FAIRE", 30, P, fuchsia);


			affiche_all();
			attendre(25);
		}
	// }

	affiche_auto_on();
	fill_screen(black);
}
