// DrawTool.h
//Samriddha Kharel 1001918169

#ifndef _DRAWTOOL_H
#define _DRAWTOOL_H

#include <stdio.h>

#define MAXMAPSIZE 20

void InitializeMap(char [][MAXMAPSIZE]);
void DrawLine(char [][MAXMAPSIZE], int, int, char, int, char);
void PrintMap(char [][MAXMAPSIZE]);

#endif
