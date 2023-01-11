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

void sizeChoice(int zn, int& bSizeX, int& bSizeY) {
	if (zn == 'j') {
		bSizeX = 9;
		bSizeY = 9;
	}
	else if (zn == 'k') {
		bSizeX = 13;
		bSizeY = 13;
	}
	else if (zn == 'l') {
		bSizeX = 19;
		bSizeY = 19;
	}
}

void positionStart(int x, int y) {
	gotoxy(x, y);
	textbackground(GREEN);
	textcolor(GREEN);
	putch('%');
}

void menu(int& zn, int captionX, int captionY, int& bSizeX, int& bSizeY, int& x, int& y, int bX, int bY) {
	do {
		cleanConsole();
		writeMenu(captionX, captionY);
		zn = getch();
		sizeChoice(zn, bSizeX, bSizeY);
	} while (zn != 'j' && zn != 'k' && zn != 'l');
	x = bX;
	y = bY;
}

void controls(int& x, int& y, int zero, int& zn, int bX, int bY, int bSizeX, int bSizeY) {
	zero = 0;
	if (zn == 0) {
		zero = 1;
		zn = getch();
		if (zn == 0x48 && y > bY) y--;
		else if (zn == 0x50 && y < bY + bSizeY - 1) y++;
		else if (zn == 0x4b && x > bX) x -= 2;
		else if (zn == 0x4d && x < bX + 2 * bSizeX - 2) x += 2;
	}
}

void scoreReset(int& pointsW, int& pointsB) {
	pointsW = 0;
	pointsB = 0;
}

void tabCoordinates(int x, int y, int bX, int bY, int& tabX, int& tabY) {
	tabX = (x - bX) / 2 + 1;
	tabY = y - bY + 1;
}