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

bool groupBreaths(char** tab, int tabX, int tabY, char color) {
	char top = tab[tabX][tabY + 1];
	char bottom = tab[tabX][tabY - 1];
	char right = tab[tabX + 1][tabY];
	char left = tab[tabX - 1][tabY];
	char opColor;
	char P = char(197);
	char border = 'X';
	if (color == 'W') opColor = 'B';
	else opColor = 'W';
	bool a = false, b = false, c = false, d = false;

	if (top == P || bottom == P || right == P || left == P)
		return true;
	else if ((top == opColor || top == border || top == 'w' || top == 'b') && (bottom == opColor || bottom == border || bottom == 'w' || bottom == 'b') && (right == opColor || right == border || right == 'w' || right == 'b') && (left == opColor || left == border || left == 'w' || left == 'b')) {
		if (color == 'B') tab[tabX][tabY] = 'b';
		if (color == 'W') tab[tabX][tabY] = 'w';
		return false;
	}
	else {
		if (color == 'B') tab[tabX][tabY] = 'b';
		if (color == 'W') tab[tabX][tabY] = 'w';
		if (top == color) a = groupBreaths(tab, tabX, tabY + 1, color);
		if (bottom == color) b = groupBreaths(tab, tabX, tabY - 1, color);
		if (right == color) c = groupBreaths(tab, tabX + 1, tabY, color);
		if (left == color) d = groupBreaths(tab, tabX - 1, tabY, color);
		if (a == true || b == true || c == true || d == true) return true;
		else return false;
	}
}

void repairingGroup(char** tab, int tabX, int tabY, char color, int bSizeX, int bSizeY) {
	for (int i = 1; i <= bSizeY; i++) {
		for (int j = 1; j <= bSizeX; j++) {
			if (tab[i][j] == 'b') tab[i][j] = 'B';
			else if (tab[i][j] == 'w') tab[i][j] = 'W';
		}
	}
}

void deletingGroup(char** tab, int tabX, int tabY, char color, int bSizeX, int bSizeY, int& pointsB, int& pointsW) {
	for (int i = 1; i <= bSizeY; i++) {
		for (int j = 1; j <= bSizeX; j++) {
			if (tab[i][j] == 'b') {
				tab[i][j] = char(197);
				pointsW++;
			}
			else if (tab[i][j] == 'w') {
				tab[i][j] = char(197);
				pointsB++;
			}
		}
	}
}

void killingGroup(char** tab, int tabX, int tabY, int bSizeX, int bSizeY, int& pointsB, int& pointsW) {
	char top = tab[tabX][tabY + 1];
	char bottom = tab[tabX][tabY - 1];
	char right = tab[tabX + 1][tabY];
	char left = tab[tabX - 1][tabY];
	char center = tab[tabX][tabY];
	if ((top == 'B' || top == 'W') && top != center) {
		if (groupBreaths(tab, tabX, tabY + 1, top) == false)
			deletingGroup(tab, tabX, tabY + 1, top, bSizeX, bSizeY, pointsB, pointsW);
		else
			repairingGroup(tab, tabX, tabY + 1, top, bSizeX, bSizeY);
	}
	if ((bottom == 'B' || bottom == 'W') && bottom != center) {
		if (groupBreaths(tab, tabX, tabY - 1, bottom) == false)
			deletingGroup(tab, tabX, tabY - 1, bottom, bSizeX, bSizeY, pointsB, pointsW);
		else
			repairingGroup(tab, tabX, tabY - 1, bottom, bSizeX, bSizeY);
	}
	if ((right == 'B' || right == 'W') && right != center) {
		if (groupBreaths(tab, tabX + 1, tabY, right) == false)
			deletingGroup(tab, tabX + 1, tabY, right, bSizeX, bSizeY, pointsB, pointsW);
		else
			repairingGroup(tab, tabX + 1, tabY, right, bSizeX, bSizeY);
	}
	if ((left == 'B' || left == 'W') && left != center) {
		if (groupBreaths(tab, tabX - 1, tabY, left) == false)
			deletingGroup(tab, tabX - 1, tabY, left, bSizeX, bSizeY, pointsB, pointsW);
		else
			repairingGroup(tab, tabX - 1, tabY, left, bSizeX, bSizeY);
	}

}

void placingStones(char** tab, int tabX, int tabY, int bSizeX, int bSizeY, int& pointsB, int& pointsW, bool handicap, int& handicapStones, char& turn) {
	if (handicap == true) {
		tab[tabX][tabY] = 'B';
		handicapStones++;
	}
	else {
		if (turn == 'B') {
			tab[tabX][tabY] = 'B';
			turn = 'W';
		}
		else {
			tab[tabX][tabY] = 'W';
			turn = 'B';
		}
		killingGroup(tab, tabX, tabY, bSizeX, bSizeY, pointsB, pointsW);
	}
}

bool suicidalMove(char** tab, int tabX, int tabY, char placedColor, int bSizeX, int bSizeY) {
	char top = tab[tabX][tabY + 1];
	char bottom = tab[tabX][tabY - 1];
	char right = tab[tabX + 1][tabY];
	char left = tab[tabX - 1][tabY];
	char opColor;
	bool a = true, b = true, c = true, d = true;
	if (placedColor == 'W') opColor = 'B';
	else opColor = 'W';
	if (top == placedColor || top == char(197) || bottom == placedColor || bottom == char(197) || right == placedColor || right == char(197) || left == placedColor || left == char(197)) {
		return false;
	}
	tab[tabX][tabY] = placedColor;
	if (top == opColor) {
		a = groupBreaths(tab, tabX, tabY + 1, opColor);
		repairingGroup(tab, tabX, tabY + 1, opColor, bSizeX, bSizeY);
	}
	if (bottom == opColor) {
		b = groupBreaths(tab, tabX, tabY - 1, opColor);
		repairingGroup(tab, tabX, tabY - 1, opColor, bSizeX, bSizeY);
	}
	if (right == opColor) {
		c = groupBreaths(tab, tabX + 1, tabY, opColor);
		repairingGroup(tab, tabX + 1, tabY, opColor, bSizeX, bSizeY);
	}
	if (left == opColor) {
		d = groupBreaths(tab, tabX - 1, tabY, opColor);
		repairingGroup(tab, tabX - 1, tabY, opColor, bSizeX, bSizeY);
	}
	tab[tabX][tabY] = char(197);
	if (a == false || b == false || c == false || d == false)
		return false;
	return true;
}