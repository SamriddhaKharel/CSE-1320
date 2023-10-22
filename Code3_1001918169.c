//Samriddha Kharel 1001918169

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void bingocard(int bingo[5][5]);
void printcard(int bingo[5][5]);
int Number();
int cardcheck(int bingo[5][5],int a,char c);
int Checkrow(int bingo[5][5]);
int Checkcol(int bingo[5][5]);
int rdiag(int bingo[5][5]);
int ldiag(int bingo[5][5]);

int main(void)
{
    int bingo [5][5];
    bingocard(bingo);
    int win = 0;

    while (!Checkrow(bingo) && !Checkcol(bingo) && win != 1)
    {
        char c;
        printf("\n");
        printcard(bingo);
        int x = Number();
        printf("Do you have it? (Y/N)");
        scanf("%s",&c);
        int y = cardcheck(bingo,x,c);
        
        if(c == 'Y' || y == 1 )
        {
        
        if (Checkrow(bingo) == 1 && Checkcol(bingo) == 1)
        {
            printf("\n");
            printcard(bingo);
            printf("You filled out a row and column - BINGO!!!");
            win =1;
        }    
        else if (Checkrow(bingo) == 1)
        {
            printf("\n");
            printcard(bingo);
            printf("You filled out a row - BINGO!!!");
            win =1;
        }
        else if (Checkcol(bingo) == 1)
        {
            printf("\n");
            printcard(bingo);
            printf("You filled out a column - BINGO!!!");
            win =1;
        }
        else if (rdiag(bingo) == 1)
        {
            printf("\n");
            printcard(bingo);
            printf("You filled out a right diagonal - BINGO!!!");
            win =1;
        }
        else if (ldiag(bingo) == 1)
        {
            printf("\n");
            printcard(bingo);
            printf("You filled out a left diagonal - BINGO!!!");
            win =1;
        }
        else if(c != 'Y' || y == 0)
        {
            printf("\nThat value is not on your BINGO card - are you trying to cheat??\n");
        }
        
            
        }
    
    }
    return 0;

}

void bingocard(int bingo[5][5])
{
    srand(time(0));
    for (int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            int i =0;
            if(col == 0)
            {
                bingo[row][col]=rand() % (15) + 1;
                while  (i < row)
                {
                    if (bingo[row][col] == bingo[i][col])
                    {
                        bingo[i][col] = rand() % 15 + 1;
                        i = 0;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            else if(col == 1)
            {
                bingo[row][col]=rand() % (15) + 16;
                while  (i < row)
                {
                    if (bingo[row][col] == bingo[i][col])
                    {
                        bingo[i][col] = rand() % 15 + 16;
                        i = 0;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            else if(col == 2)
            {
                bingo[row][col]=rand() % (15) + 31;
                if (bingo[row][col] == bingo[2][2])
                    {
                        bingo[2][2] = 0;
                    } 
                while  (i < row)
                {
                    if (bingo[row][col] == bingo[i][col])
                    {
                        bingo[i][col] = rand() % 15 + 31;
                        i = 0;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            else if(col == 3)
            {
                bingo[row][col]=rand() % (15) + 46;
                while  (i < row)
                {
                    if (bingo[row][col] == bingo[i][col])
                    {
                        bingo[i][col] = rand() % 15 + 46;
                        i = 0;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            else
            {
                bingo[row][col]= rand() % (15) + 61;
                while  (i < row)
                {
                    if (bingo[row][col] == bingo[i][col])
                    {
                        bingo[i][col] = rand() % 15 + 61;
                        i = 0;
                    }
                    else
                    {
                        i++;
                    }
                }
            }
            
        }
    }
}

void printcard(int bingo[5][5])
{
    char arr[]="B";
    char arr1[]="I";
    char arr2[]="N";
    char arr3[]="G";
    char arr4[]="O";
    char arr5[]="X";
    printf("%5.1s %7.2s %7.2s %7.2s %7.2s\n",arr,arr1,arr2,arr3,arr4);
    printf("-----------------------------------------\n");

    for(int row = 0; row < 5; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            printf("|%4d\t", bingo[row][col]);
            if(bingo[row][col] == 0)
            {
                printf("\b\b\b\b%s   ",arr5);
            }   
            
        }
        printf("|");
        printf("\n");
        printf("-----------------------------------------\n");
    }
}

int Number()
{
    int x;
    int array[75];
    for(int i = 0; i < 75; i++)
    {
        array[i] = rand() % 75 + 1;
        int j = 0;
        while (j < i)
        {
            if (array[i] == array[j])
            {
                array[i] = rand() % 75 + 1;
                j = 0;
            }
            else
            {
                j++;
            }
        }
    }    
    x = rand() % 75 + 1;
    if (array[x] == 0)
    {
        while (array[x] == 0)
        {
            x = rand() % 75 + 1;
        }
    }
    int result = array[x];
    array[x] = 0;

    if(result >= 1 && result <= 15)
    {
        printf("\nThe next number is B%d\n\n",result);
        return result;
    }
    else if(result >= 16 && result <= 30)
    {
        printf("\nThe next number is I%d\n\n",result);
        return result;
    }
    else if(result >= 31 && result <= 45)
    {
        printf("\nThe next number is N%d\n\n",result);
        return result;
    }
    else if(result >= 46 && result <= 60)
    {
        printf("\nThe next number is G%d\n\n",result);
            return result;
    }
    else
    {
        printf("\nThe next number is O%d\n\n",result);
        return result;
    }
}
int cardcheck(int bingo[5][5],int a,char c)
{
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
      
            if(bingo[i][j] == a && c == 'Y')
            {
                bingo[i][j] = 0;
                return true;
            }
        }
    }
    return false;
}

int Checkrow(int bingo[5][5])
{
    for(int row = 0; row < 5; row++)
    {
        int counter = 0;
        for(int col = 0; col < 5; col++)
        {
            if(bingo[row][col] == 0)
            {
                counter++;
            }
        }
        if(counter == 5)
        {
            return true;
        }
    }
    return false;
}
int Checkcol(int bingo[5][5])
{
    for(int col = 0; col < 5; col++)
    {
        int counter = 0;
        for(int row = 0; row < 5; row++)
        {
            if(bingo[row][col] == 0)
            {
                counter++;
            }
        }
        if(counter == 5)
        {
            return true;
        }
    }
    return false;
}

int ldiag(int bingo[5][5])
{
    for(int col = 0; col < 5; col++)
    {
        int counter = 0;
        for(int row = 0; row < 5; row++)
        {
            if(col == row)
            {
                counter++;
            }
        }
        if(counter == 5)
        {
            return true;
        }
    }
    return false;
}

int rdiag(int bingo[5][5])
{
    for(int col = 0; col < 5; col++)
    {
        int counter = 0;
        for(int row = 0; row < 5; row++)
        {
            if((col + row) == (5 - 1))
            {
                counter++;
            }
        }
        if(counter == 5)
        {
            return true;
        }
    }
    return false;
}