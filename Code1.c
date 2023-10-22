#include <stdio.h>

//Name: Samriddha Kharel  ID: 1001918169

int main(void)
{
    int i_start, i_end,j_start,j_end,k_start,k_end;

    printf("Enter i's starting value ");
    scanf("%d",&i_start);
    printf("Enter i's ending  value ");
    scanf("%d",&i_end);

    printf("Enter j's starting value ");
    scanf("%d",&j_start);
    printf("Enter j's ending  value ");
    scanf("%d",&j_end);

    printf("Enter k's starting value ");
    scanf("%d",&k_start);
    printf("Enter k's ending  value ");
    scanf("%d",&k_end);


    for(int x = i_start; x < i_end; x++)
    {
        printf("\n");
        for(int y = j_start; y < j_end; y++)
        {
            printf("\n");
       	    for(int z = k_start; z < k_end; z++)
            printf("*");
        }
    }
    printf("\n");
    return 0;
}
