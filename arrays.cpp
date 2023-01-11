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

char** allocation2D(int bSizeX, int bSizeY) {
	char** tab = (char**)malloc(sizeof(char*) * (bSizeY + 2));

	for (int i = 0; i < bSizeY + 2; i++) {
		tab[i] = (char*)malloc(sizeof(char) * (bSizeX + 2));
	}
	return tab;
}

void free2D(char** tab, int bSizeX, int bSizeY) {
	for (int i = 0; i < bSizeY + 2; i++) {
		free(tab[i]);
	}
	free(tab);
}

void printArray(char** tab, int bSizeX, int bSizeY, int bX, int bY, int x, int y) {
	for (int i = 1; i <= bSizeY; i++) {
		for (int j = 1; j <= bSizeX; j++) {
			gotoxy(bX + (i - 1) * 2, bY - 1 + j);
			if (tab[i][j] == char(197)) {
				textbackground(DARKGRAY);
				textcolor(BLACK);
			}
			else if (tab[i][j] == 'B') {
				textbackground(BLACK);
				textcolor(BLACK);
			}
			else {
				textbackground(WHITE);
				textcolor(WHITE);
			}
			putch(tab[i][j]);
		}
	}
	gotoxy(x, y);
}

void cleanArray(char** tab, int bSizeX, int bSizeY) {
	for (int i = 0; i < bSizeY + 2; i++) {
		for (int j = 0; j < bSizeX + 2; j++) {
			if (i == 0 || j == 0 || i == bSizeY + 1 || j == bSizeX + 1)
				tab[i][j] = 'X';
			else
				tab[i][j] = char(197);
		}
	}
}