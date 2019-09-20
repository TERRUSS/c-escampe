
#pragma once

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

struct BOX{
	int lisere;
	TYPE typeP;
	COUL coulP;
};
typedef struct BOX BOX;
BOX plateau [6][6];
