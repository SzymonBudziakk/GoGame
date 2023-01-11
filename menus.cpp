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

void cleanConsole() {
	textbackground(DARKGRAY);
	textcolor(BLACK);
	clrscr();
}

void writeCaption(int cX, int cY, int x, int y, int bX, int bY, char turn, int pointsB, int pointsW) {
	gotoxy(cX, cY);
	cputs("Szymon Budziak 193234");
	gotoxy(cX, cY + 1);
	cputs("a b c d e g j k");
	gotoxy(cX, cY + 2);
	cputs("q        - wyjscie");
	gotoxy(cX, cY + 3);
	cputs("strzalki - poruszanie sie");
	gotoxy(cX, cY + 4);
	cputs("n        - nowa gra");
	gotoxy(cX, cY + 5);
	char txt[32];
	x = (x + 2 - bX) / 2;
	y += 1 - bY;
	sprintf(txt, "x = [%i] y = [%i]", x, y);
	cputs(txt);
	gotoxy(cX, cY + 6);
	char txt2[32];
	sprintf(txt2, "czarne = [%i] biale = [%i]", pointsB, pointsW);
	cputs(txt2);
	gotoxy(cX, cY + 7);
	cputs("tura - ");
	if (turn == 'B') {
		textbackground(BLACK);
		textcolor(BLACK);
	}
	else {
		textbackground(WHITE);
		textcolor(WHITE);
	}
	cputs("XX");
	textbackground(DARKGRAY);
	textcolor(BLACK);
}

void writeMenu(int x, int y) {
	gotoxy(x, y);
	cputs("Szymon Budziak 193234");
	gotoxy(x, y + 1);
	cputs("Wybierz rozmiar planszy:");
	gotoxy(x, y + 2);
	cputs("j   -   9x9");
	gotoxy(x, y + 3);
	cputs("k   -   13x13");
	gotoxy(x, y + 4);
	cputs("l   -   19x19");
}

void writeCaptionHandicap(int cX, int cY, int x, int y, int bX, int bY, char turn, int pointsB, int pointsW) {
	gotoxy(cX, cY);
	cputs("Szymon Budziak 193234");
	gotoxy(cX, cY + 1);
	cputs("HANDICAP MODE");
	gotoxy(cX, cY + 2);
	cputs("h        - zakoncz handicap");
	gotoxy(cX, cY + 3);
	cputs("strzalki - poruszanie sie");
	gotoxy(cX, cY + 4);
	cputs("q        - wyjscie");
	gotoxy(cX, cY + 5);
	char txt[32];
	x = (x + 2 - bX) / 2;
	y += 1 - bY;
	sprintf(txt, "x = [%i] y = [%i]", x, y);
	cputs(txt);
	gotoxy(cX, cY + 6);
	char txt2[32];
	sprintf(txt2, "czarne = [%i] biale = [%i]", pointsB, pointsW);
	cputs(txt2);
	gotoxy(cX, cY + 7);
	cputs("tura - ");
	if (turn == 'B') {
		textbackground(BLACK);
		textcolor(BLACK);
	}
	else {
		textbackground(WHITE);
		textcolor(WHITE);
	}
	cputs("XX");
	textbackground(DARKGRAY);
	textcolor(BLACK);
}

void writeBoard(int pX, int pY, int rX, int rY) {
	for (int i = pX; i < pX + 2 * rX; i += 2) {
		for (int j = pY; j < pY + rY; j++) {
			gotoxy(i, j);
			putch(197);
			gotoxy(i + 1, j);
			putch(196);
			if (j == pY) {
				gotoxy(i, j - 1);
				putch(196);
				gotoxy(i + 1, j - 1);
				putch(196);
			}
			if (j + 1 == pY + rY) {
				gotoxy(i, j + 1);
				putch(196);
				gotoxy(i + 1, j + 1);
				putch(196);
			}
			if (i == pX) {
				gotoxy(i - 1, j);
				putch(196);
				gotoxy(i - 2, j);
				putch(179);
			}
			if (i + 2 == pX + 2 * rX) {
				gotoxy(i + 2, j);
				putch(179);
			}
		}
	}
	gotoxy(pX - 1, pY - 1);
	putch(196);
	gotoxy(pX - 1, pY + rY);
	putch(196);
}