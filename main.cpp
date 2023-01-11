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

int main() {

	int captionX = 10, captionY = 5;
	int bX = 50, bY = 5;
	int bSizeX = 0, bSizeY = 0;
	int x = bX, y = bY;
	int zn = 0, zero = 0;					
	int tabX = 0, tabY = 0;
	int pointsW = 0, pointsB = 0;
	int handicapStones = 0;
	char P = char(197); 
	char turn = 'B';
	bool handicap = true;
	

	settitle("Szymon Budziak, 193234");
	_setcursortype(_NOCURSOR);
	menu(zn, captionX, captionY, bSizeX, bSizeY, x, y, bX, bY);
	char** tab = allocation2D(bSizeX, bSizeY);
	char** tabBack = allocation2D(bSizeX, bSizeY);
	char** tabFront = allocation2D(bSizeX, bSizeY);
	cleanArray(tab, bSizeX, bSizeY);
	cleanArray(tabBack, bSizeX, bSizeY);
	cleanArray(tabFront, bSizeX, bSizeY);

	while (zn != 'q') {

		cleanConsole();
		if (handicap == true) writeCaptionHandicap(captionX, captionY, x, y, bX, bY, turn, pointsB, pointsW);
		else writeCaption(captionX, captionY, x, y, bX, bY, turn, pointsB, pointsW);

		writeBoard(bX, bY, bSizeX, bSizeY);
		printArray(tab, bSizeX, bSizeY, bX, bY, x, y);
		positionStart(x, y);

		zn = getch();

		tabCoordinates(x, y, bX, bY, tabX, tabY);
		exitingHandicap(zn, handicap, handicapStones, turn);

		if (zn == 'i' && tab[tabX][tabY] == P && suicidalMove(tab, tabX, tabY, turn, bSizeX, bSizeY) == false) {
			if (koRule(tab, tabBack, tabFront, tabX, tabY, turn, bSizeX, bSizeY, pointsW, pointsB) == true) {
				placingStones(tab, tabX, tabY, bSizeX, bSizeY, pointsB, pointsW, handicap, handicapStones, turn);
			}
		}
		else if (zn == 'n') {
			menu(zn, captionX, captionY, bSizeX, bSizeY, x, y, bX, bY);
			cleanArray(tab, bSizeX, bSizeY);
			scoreReset(pointsW, pointsB);
			newGameHandicapReset(handicap, handicapStones, turn);
		}
		else controls(x, y, zero, zn, bX, bY, bSizeX, bSizeY);
	}

	free2D(tab, bSizeX, bSizeY);
	free2D(tabBack, bSizeX, bSizeY);
	free2D(tabFront, bSizeX, bSizeY);

	_setcursortype(_NORMALCURSOR);
	return 0;
}
