
#include "lib/graphics.h"

//C
BOX plateau [6][6];
struct BOX{
	int lisere;
	TYPE typeP;
	COUL coulP;
};
typedef struct BOX BOX;
enum COUL{
	BLANC,NOIR
};
typedef enum COUL COUL;

enum TYPE{
	VIDE,LICORNE,PALADIN
};
typedef enum TYPE TYPE;
struct NUMBOX{
	int l;
	int c;
};
//C
void init_plateau();

void init_plateau(){
	plateau[0][0].lisere=1;plateau[0][4].lisere=1;plateau[1][1].lisere=1;plateau[1][3].lisere=1;plateau[2][2].lisere=1;plateau[2][4].lisere=1;plateau[3][1].lisere=1;plateau[3][5].lisere=1;plateau[4][0].lisere=1;plateau[4][2].lisere=1;plateau[4][4].lisere=1;plateau[5][3].lisere=1;
	plateau[0][1].lisere=2;plateau[0][2].lisere=2;plateau[0][5].lisere=2;plateau[1][5].lisere=2;plateau[2][0].lisere=2;plateau[2][3].lisere=2;plateau[3][0].lisere=2;plateau[3][3].lisere=2;plateau[4][5].lisere=2;plateau[5][1].lisere=2;plateau[5][2].lisere=2;plateau[5][5].lisere=2;
	plateau[0][3].lisere=3;plateau[1][0].lisere=3;plateau[1][2].lisere=3;plateau[1][4].lisere=3;plateau[2][1].lisere=3;plateau[2][5].lisere=3;plateau[3][2].lisere=3;plateau[3][4].lisere=3;plateau[4][1].lisere=3;plateau[4][3].lisere=3;plateau[5][0].lisere=3;plateau[5][4].lisere=3;
}

void init_piece1_debug();

void init_piece1_debug(){
	plateau[0][1].typeP=PALADIN;plateau[0][1].coulP=BLANC;
	plateau[0][2].typeP=PALADIN;plateau[0][2].coulP=BLANC;
	plateau[1][1].typeP=PALADIN;plateau[1][1].coulP=BLANC;
	plateau[1][3].typeP=PALADIN;plateau[1][3].coulP=BLANC;
	plateau[1][4].typeP=PALADIN;plateau[1][4].coulP=BLANC;
	plateau[0][3].typeP=LICORNE;plateau[0][3].coulP=BLANC;
	plateau[4][0].typeP=PALADIN;plateau[4][0].coulP=NOIR;
	plateau[4][2].typeP=PALADIN;plateau[4][2].coulP=NOIR;
	plateau[4][5].typeP=PALADIN;plateau[4][5].coulP=NOIR;
	plateau[5][2].typeP=PALADIN;plateau[5][2].coulP=NOIR;
	plateau[5][4].typeP=PALADIN;plateau[5][4].coulP=NOIR;
	plateau[4][1].typeP=LICORNE;plateau[4][1].coulP=NOIR;
}

void init_piece2_debug();

void init_piece2_debug(){
	plateau[0][0].typeP=PALADIN;plateau[0][0].coulP=BLANC;
	plateau[1][0].typeP=PALADIN;plateau[1][0].coulP=BLANC;
	plateau[2][0].typeP=PALADIN;plateau[2][0].coulP=BLANC;
	plateau[3][0].typeP=PALADIN;plateau[3][0].coulP=BLANC;
	plateau[4][0].typeP=PALADIN;plateau[4][0].coulP=BLANC;
	plateau[5][0].typeP=LICORNE;plateau[5][0].coulP=BLANC;
	plateau[0][5].typeP=PALADIN;plateau[0][5].coulP=NOIR;
	plateau[1][5].typeP=PALADIN;plateau[1][5].coulP=NOIR;
	plateau[3][5].typeP=PALADIN;plateau[3][5].coulP=NOIR;
	plateau[4][5].typeP=PALADIN;plateau[4][5].coulP=NOIR;
	plateau[5][5].typeP=PALADIN;plateau[5][5].coulP=NOIR;
	plateau[2][5].typeP=LICORNE;plateau[2][5].coulP=NOIR;
}

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

void affiche_licorne (POINT bg, COUL coulP);

void affiche_licorne (POINT bg, COUL coulP){
	int i,j;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (plateau[i][j].typeP == LICORNE) {
				//affiche le paladin
				if (plateau[i][j].coulP == NOIR) {
					//noir
				}else if (plateau[i][j].coulP == BLANC){
					//blanc
				}
			}
		}
	}
}

void affiche_paladin (POINT bg, COUL coulP);

void affiche_paladin (POINT bg, COUL coulP){
	int i,j;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			if (plateau[i][j].typeP == PALADIN) {
				//affiche le paladin
				if (plateau[i][j].coulP == NOIR) {
					//noir
				}else if (plateau[i][j].coulP == BLANC){
					//blanc
				}
			}
		}
	}
}

void affiche_lisere (POINT bg, int nbLisere);

void affiche_lisere (POINT bg, int nbLisere){
	int i,j;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 6; j++) {
			switch (plateau[i][j].lisere) {
				case 1:
				//1 lesere
				break;
				case 2:
				//2 nbLisere
				break;
				case 3:
				//3 lisere
				break;
			}
		}
	}
}

void affiche_plateau(int ig);

void affiche_plateau(int ig){

}

int main() {
	COUL Joueur;
	int view;

	do {
		printf("Changement de vue [1/2]\n");
		scanf(" %d",&view)
	} while(view < 0 && view > 2);


}
