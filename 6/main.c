#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 4

int main(int argc, char const *argv[])
{
    FILE *f = fopen("input.txt", "r");
    char c;
    int time[SIZE];
    int mil[SIZE];
    int number = 0;
    int bas = 1;
    int t = 0;

    while ((c = fgetc(f)) != EOF)
    {
        if (isdigit(c))
        {
            number *= bas;
            number += (c - '0');
            bas = 10;
        }

        if (!isdigit(c))
        {
            if (number != 0)
            {
                if (t < 3)
                {
                    time[t] = number;
                }
                else
                {
                    mil[t - SIZE] = number;
                }
                t++;
            }
            bas = 1;
            number = 0;
        }
    }

    int k = 0;
    int crose = 0;
    int mikter = 0;
    int carpım = 1;
    for (int i = 0; i < SIZE; i++)
    {
        k = time[i];
        for (int j = 0; j < time[i]; j++)
        {
            crose = (k - j) * j;
            if (crose > mil[i])
            {
                mikter++;
            }
        }
        printf("miktar = %d \n", mikter);
        carpım *= mikter;
        mikter = 0;
    }

    printf("sonuc = %d", carpım);

    return 0;
}
