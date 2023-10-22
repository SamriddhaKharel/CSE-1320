//Samriddha Kharel 1001918169
#include <stdio.h>
#define BITS 8
void ConvertDecimalToBinary(int a, char bucket[])
{
    int x = 1;
    int array[BITS];
    bucket[BITS] = 0;
    array[0] = a;
    for(int i = 1; i < BITS; i++)
    {
        array[i] = array[i-1] / 2;
    }
    for (int i = 0; i < BITS; i++)
    {
        if(array[x-1] % 2 == 0)
        {
            bucket[BITS-x] = '0';
        }
        else
        {
            bucket[BITS-x] = '1';
        }
        x++;
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main()
{
    int FirstNum,SecondNum,Output;
    char array[5] = {'&','|','^','<','>'};
    char Operator[5];
    char FirstBucket[BITS+1]= {};
    char SecondBucket[BITS+1]= {};
    char ResultBucket[BITS+1]= {};


    printf("Bitwise Calculator\n\nEnter two base 10 values with a bitwise operator to see the decimal result\nand the binary result.The format is\n\nFirstNumber BitwiseOperator SecondNumber\n\nFor example, enter the expression\n\n2 & 3\n\nThis calculator can used with &, |, ^, << and >>\n\nPlease note that the spaces between numbers and operator is essential\nand the two entered values must be between 0 and 255\n\n");

    printf("Enter expression ");

    scanf("%d %s %d",&FirstNum, &Operator[0], &SecondNum);


    while(((FirstNum <= 0)||(SecondNum<= 0))||((FirstNum >= 255)|| (SecondNum >= 255)))
    {
        printf("\n\nThe entered expression contains out of range values.\nPlease reenter the expression using values between 0 and 255.\n\n");
        scanf("%d %s %d",&FirstNum, &Operator[0], &SecondNum);
    }

    if(array[0] == Operator[0])
    {
        printf("\nIn base 10... ");
        Output= FirstNum & SecondNum;
        printf("\n\n%d & %d = %d\n\n",FirstNum,SecondNum, Output);
        printf("In %d-bit base 2...\n",BITS);

        ConvertDecimalToBinary(FirstNum, FirstBucket);
        ConvertDecimalToBinary(SecondNum,SecondBucket);
        ConvertDecimalToBinary(Output,ResultBucket);

        printf("\n  %s\n",FirstBucket);
        printf("%s\n",Operator);
        printf("  %s\n",SecondBucket);
        printf("  ========\n");
        printf("  %s\n",ResultBucket);
    }
    else if(array[1] == Operator[0])
    {
        printf("\nIn base 10... ");
        Output= FirstNum | SecondNum;
        printf("\n\n%d | %d = %d\n\n",FirstNum,SecondNum, Output);
        printf("In %d-bit base 2...\n",BITS);

        ConvertDecimalToBinary(FirstNum, FirstBucket);
        ConvertDecimalToBinary(SecondNum,SecondBucket);
        ConvertDecimalToBinary(Output,ResultBucket);

        printf("\n  %s\n",FirstBucket);
        printf("%s\n",Operator);
        printf("  %s\n",SecondBucket);
        printf("  ========\n");
        printf("  %s\n",ResultBucket);
    }
    else if(array[2] == Operator[0])
    {
        printf("\nIn base 10... ");
        Output= FirstNum ^ SecondNum;
        printf("\n\n%d ^ %d = %d\n\n",FirstNum,SecondNum, Output);
        printf("In %d-bit base 2...\n",BITS);

        ConvertDecimalToBinary(FirstNum, FirstBucket);
        ConvertDecimalToBinary(SecondNum,SecondBucket);
        ConvertDecimalToBinary(Output,ResultBucket);

        printf("\n  %s\n",FirstBucket);
        printf("%s\n",Operator);
        printf("  %s\n",SecondBucket);
        printf("  ========\n");
        printf("  %s\n",ResultBucket);
    }
    else if(array[3] == Operator[0])
    {
        printf("\nIn base 10...");
        Output= FirstNum << SecondNum;
        printf("\n\n%d << %d = %d\n\n\n",FirstNum,SecondNum, Output);
        printf("In %d-bit base 2...\n",BITS);

        ConvertDecimalToBinary(FirstNum, FirstBucket);
        ConvertDecimalToBinary(SecondNum,SecondBucket);
        ConvertDecimalToBinary(Output,ResultBucket);

        printf("\n%s << %d\n\n",FirstBucket,SecondNum);
        printf("%s\n",ResultBucket);
    }
    else if(array[4] == Operator[0])
    {
        printf("\nIn base 10... ");
        Output= FirstNum >> SecondNum;
        printf("\n\n%d >> %d = %d\n\n\n",FirstNum,SecondNum, Output);
        printf("In %d-bit base 2...\n",BITS);

        ConvertDecimalToBinary(FirstNum, FirstBucket);
        ConvertDecimalToBinary(SecondNum,SecondBucket);
        ConvertDecimalToBinary(Output,ResultBucket);

        printf("\n%s >> %d\n\n",FirstBucket,SecondNum);
        printf("%s\n",ResultBucket);
    }
    else
    {
        printf("\n\nOperator %s is not supported by the calculator.\n\n",Operator);
    }

    return 0;
}
