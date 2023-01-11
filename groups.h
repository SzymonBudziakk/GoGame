#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>


bool groupBreaths(char** tab, int tabX, int tabY, char color);

void repairingGroup(char** tab, int tabX, int tabY, char color, int bSizeX, int bSizeY);

void deletingGroup(char** tab, int tabX, int tabY, char color, int bSizeX, int bSizeY, int& pointsB, int& pointsW);

void killingGroup(char** tab, int tabX, int tabY, int bSizeX, int bSizeY, int& pointsB, int& pointsW);

void placingStones(char** tab, int tabX, int tabY, int bSizeX, int bSizeY, int& pointsB, int& pointsW, bool handicap, int& handicapStones, char& turn);

bool suicidalMove(char** tab, int tabX, int tabY, char placedColor, int bSizeX, int bSizeY);