#include "DrawTool.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *Token = NULL;
  char DrawCommand[1000] = {};
  char Marker[20]={};

  int row;
  int col;
  int Distance = 0;
  int MyMapsize = 0;

  char TwoDArray[MAXMAPSIZE][MAXMAPSIZE];
  char UserInput[MAXMAPSIZE];
  char UserInput2[MAXMAPSIZE];

  InitializeMap(TwoDArray, &MyMapsize);
  PrintInstructions();
  PrintMap(TwoDArray, MyMapsize);

  printf("Enter draw command (enter Q to quit)\n");
  fgets(UserInput, 19, stdin);
  Token = strtok(UserInput, "(),");
  strcpy(DrawCommand, Token);
  DrawCommand[0] = toupper(DrawCommand[0]);
  while (DrawCommand[0] != 'Q')
  {
      Token = strtok(NULL, "(),");
      row = atoi(Token);

      Token = strtok(NULL, "(),");
      col = atoi(Token);

      Token = strtok(NULL, "(),");
      Distance = atoi(Token);

      Token = strtok(NULL, "(),");
      strcpy(Marker, Token);

      if (Marker[0] == '\n')
      {
        Marker[0] = 'X';
      }
      if ((row < 0 || MyMapsize < row) || (col < 0 || MyMapsize < col) ||(Distance < 0 || MyMapsize < Distance))
      {
        printf("The Draw Command is out of range");
      }
      if (DrawCommand[0] == 'P')
      {
        TwoDArray[row][col] = Marker[0];
        PrintMap(TwoDArray, MyMapsize);
      }
      else
      {
		printf("Thats not a valid command!");
        DrawLine(TwoDArray, row, col, DrawCommand[0], Distance, Marker[0]);
        PrintMap(TwoDArray, MyMapsize);
      }
      printf("Enter draw command (enter Q to quit)\n");
      fgets(UserInput2, 20, stdin);
      Token = strtok(UserInput2, "(),");
      strcpy(DrawCommand, Token);
      DrawCommand[0] = toupper(*Token);
  }
}
