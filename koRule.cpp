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


void passingArray(char** tab, int bSizeX, int bSizeY, char** tab2) {
	for (int i = 0; i < bSizeY + 2; i++) {
		for (int j = 0; j < bSizeX + 2; j++) {
			tab2[i][j] = tab[i][j];
		}
	}
}

bool equalArrays(char** tab, int bSizeX, int bSizeY, char** tab2) {
	for (int i = 0; i < bSizeY + 2; i++) {
		for (int j = 0; j < bSizeX + 2; j++) {
			if (tab2[i][j] != tab[i][j])
				return false;
		}
	}
	return true;
}

bool koRule(char** tab, char** tabBack, char** tabFront, int tabX, int tabY, char stoneColor, int bSizeX, int bSizeY, int pointsW, int pointsB) {
	passingArray(tab, bSizeX, bSizeY, tabFront);
	tabFront[tabX][tabY] = stoneColor;
	killingGroup(tabFront, tabX, tabY, bSizeX, bSizeY, pointsB, pointsW);
	if (equalArrays(tabBack, bSizeX, bSizeY, tabFront) == true)
		return false;
	passingArray(tab, bSizeX, bSizeY, tabBack);
	return true;
}