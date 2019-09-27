
#pragma once

enum COUL{
	NONE, BLANC,NOIR
};
typedef enum COUL COUL;

enum PLAY{
	PLAYABLE, UNPLAYABLE
};
typedef enum PLAY PLAY;

enum TYPE{
	VIDE,LICORNE,PALADIN
};
typedef enum TYPE TYPE;

struct NUMBOX{
	int l;
	int c;
};
typedef struct NUMBOX NUMBOX;

struct BOX{
	int lisere;
	TYPE typeP;
	COUL coulP;
	PLAY playP;
	int tmp_play;
};
typedef struct BOX BOX;
BOX plateau [6][6];
