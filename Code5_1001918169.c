/* Coding Assignment 5 */
// Samriddha Kharel 1001918169
/* Add necessary includes */
#include <stdbool.h>
#include <string.h>
#include "Gamelib.h"
int main(void)
{
	char Phrase[MAX_INPUT] = {};
	char DashedPhrase[MAX_INPUT] = {};
	char UpperPhrase[MAX_INPUT] = {};
	int Strikes = 0;
	int i;
	int nstrike;


	/* Call StartGame and pass in Phrase */
	StartGame(Phrase);
	/* Call DashIt and pass in Phrase and DashedPhrase */
	DashIt(Phrase,DashedPhrase);
	/* uppercase Phrase */
	for(int i =0;i<sizeof(Phrase);i++)
    {
        UpperPhrase[i] = toupper(Phrase[i]);
    }

	printf("\nHere's the phrase you need to guess\n");

	do
	{
		/* if !(call GuessALetter and pass Phrase, DashedPhrase and UpperPhrase) */
		if(!GuessALetter(Phrase,DashedPhrase,UpperPhrase))
		{
			Strikes++;
			printf("\nStrike %d", Strikes);
		}
    }
	/* while (call strchr() with DashedPhrase with -) AND strike counter is less than strikes define */
	while (strchr(DashedPhrase,'-') && Strikes < STRIKES);
	{

        if (Strikes < STRIKES)
        {
            printf("\n\nYou figured it out!!\n\nThe phrase was \n\n%s", Phrase);
            printf("\n\nYOU WIN!!!!\n");
        }
        else
        {
            printf("\n\n");
            printf("%d STRIKES - YOU'RE OUT!!\n\n", STRIKES);
            printf("Game over\n\n");
        }
    }
		return 0;

}

