#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>

void passingArray(char** tab, int bSizeX, int bSizeY, char** tab2);

bool equalArrays(char** tab, int bSizeX, int bSizeY, char** tab2);

bool koRule(char** tab, char** tabBack, char** tabFront, int tabX, int tabY, char stoneColor, int bSizeX, int bSizeY, int pointsW, int pointsB);