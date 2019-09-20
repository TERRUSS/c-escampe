
#include "lib/graphics.h"
#include "couleur_console.h"

#define couleur_texte(coul) printf("\033[%dm",coul)
#define couleur_fond(coul)	printf("\033[%dm",coul+10)
#define PALADIN "P"
#define LICORNE "L"
#define VOID " "

char board [5][5];

typedef PLAYER{
	char name;
	char color;
	t_position paladin_1;
	t_position paladin_2;
	t_position paladin_3;
	t_position paladin_4;
	t_position licorne;
	int life_point = 1;
}t_player;

typedef POSITION{
	int x;
	int y;
}t_position;
//H
void init(t_player player);
int choice (t_player* player_1,t_player* player_2);
void board_view();

//O
void draw_board();


int main() {
	//O
	init_graphics(700, 700); /* (largeur, hauteur) */
	affiche_auto_off();
	draw_board();
	affiche_all(); //render

	//H
	t_player player_1;
	t_player player_2;

	//H
	printf("Joueur 1 Veuillez ecrir votre Pseudo:\n", );
	scanf(" %c",&player_1.name );
	printf("Joueur 2 Veuillez ecrir votre Pseudo:\n", );
	scanf(" %c",&player_2.name );

	choice(&player_1,&player_2);

	if (player_1.color == "WHITE") {
		init (player_2);
	}else{
		init (player_1);
	}

	//O
	wait_escape();
	return(0);
}

//O
void draw_board() {
	// draw_board_grid();
	// draw_board_circles();
	// print_markers();
}

//H
int choice (t_player* player_1,t_player* player_2){
	choice = srand (time (NULL));

	if (choice % 2 = 0) {
		player_1->color="WHITE";
		player_2->color="BLACK";
	}else{
		player_2->color="WHITE";
		player_1->color="BLACK";
	}
}

//H
void init(t_player player){
	printf("")

}

//H
void board_view(){
	int i,j;
  char x;
  printf("\n");
  printf("  ");
  for (i = 0; i < 6; i++) {
    x = 'A' + i;
    printf("|");
    couleur_texte(CYAN);
    printf(" %c ", x);
    couleur_texte(RESET);
  }
  printf("|");
  printf("\n");
  for (i = 0; i < 6; i++) {
    printf("-----------------------------------\n");
    couleur_texte(CYAN);
    printf("%i ",i+1);
    couleur_texte(RESET);
    for (j = 0; j < 6; j++) {
        printf("|");
        printf(" ");
        couleur_texte(JAUNE);
        switch (board[i][j]) {
          case LICORNE:
          break;
          case PALADIN:
          break;
          default:
          field[i][j]=SPACE;
          break;
        }
        printf("%c",board[i][j]);
        couleur_texte(RESET);
        printf(" ");
    }
    printf("|");
    printf("\n");
  }
  printf("-----------------------------------\n");
}
