#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>


void cleanConsole();

void writeCaption(int cX, int cY, int x, int y, int bX, int bY, char turn, int pointsB, int pointsW);

void writeMenu(int x, int y);

void writeCaptionHandicap(int cX, int cY, int x, int y, int bX, int bY, char turn, int pointsB, int pointsW);

void writeBoard(int pX, int pY, int rX, int rY);