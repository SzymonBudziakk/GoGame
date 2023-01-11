#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include"conio2.h"
#include"menus.h"
#include"handicap.h"
#include"controls.h"
#include"arrays.h"
#include"groups.h"
#include"koRule.h"

void exitingHandicap(char zn, bool& handicap, int handicapStones, char& turn) {
	if (zn == 'h') {
		handicap = false;
		if (handicapStones >= 2)
			turn = 'W';
	}
}

void newGameHandicapReset(bool& handicap, int& handicapStones, char& turn) {
	handicap = true;
	handicapStones = 0;
	turn = 'B';
}