#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>


char** allocation2D(int bSizeX, int bSizeY);

void free2D(char** tab, int bSizeX, int bSizeY);

void printArray(char** tab, int bSizeX, int bSizeY, int bX, int bY, int x, int y);

void cleanArray(char** tab, int bSizeX, int bSizeY);