#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>


void sizeChoice(int zn, int& bSizeX, int& bSizeY);

void positionStart(int x, int y);

void menu(int& zn, int captionX, int captionY, int& bSizeX, int& bSizeY, int& x, int& y, int bX, int bY);

void controls(int& x, int& y, int zero, int& zn, int bX, int bY, int bSizeX, int bSizeY);

void scoreReset(int& pointsW, int& pointsB);

void tabCoordinates(int x, int y, int bX, int bY, int& tabX, int& tabY);