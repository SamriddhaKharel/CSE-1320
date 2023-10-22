// FileLib Template
//Samriddha Kharel 1001918169

#include <stdio.h>
#include <string.h>
#include "ListLib.h"

FILE *OpenFile(int argc, char *argv[])
{
	/* declare various variables needed */
	char filename[100]={};

	FILE *handle;


	/* if argc is 2, then use argv[1] as the input file name, else print the message seen in sample output */
	if (argc == 2)
	{
        strcpy(filename,argv[1]);
	}
	else
	{
        printf("Seen in sample output");
	}

	do
	{
		/* open file with "r" mode */
		handle =fopen(filename,"r");
		/* if file did not open */
		if (handle == NULL)
		{
			printf("Must be run with an input file name. \n");
            printf("Could not open input file named %s", argv[1]);
            /* print message seen in sample output */
            /* read in new filename */
            scanf("%s",filename);
            /* open the file "r" mode **/
            handle = fopen(filename,"r");

		}
	}
	while (handle == NULL);
	/* return the file handle */
	return handle;
}

void ReadFileIntoLinkedList(FILE *DCFile, NODE **LinkedListHead)
{
    //int i = 0;
    char *Token = NULL;
    char Letter2;
    char Letter[30] = {};
    char command[30] = {};
    char DrawCommand[20] = {};
    /* declare various variables needed */

    /* while fgets() reads the file */
    while(fgets(DrawCommand,sizeof(DrawCommand)-1, DCFile))
    {
        /* if line from file ends with \n, then replace \n with \0 */
        if (DrawCommand[strlen(DrawCommand)] == '\n')
        {
            DrawCommand[strlen(DrawCommand)] = '\0';
        }
        Token = strtok(DrawCommand,"|");
        strcpy(Letter, Token);

        Token = strtok(NULL," ");
        strcpy(command, Token);
        /* tokenize to get the Letter and the DrawCommand */

        /* Call AddDrawCommandToList with correct parameters */
        AddDrawCommandToList(Letter2, DrawCommand, LinkedListHead);
    }
}
