#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 142

char matrix[SIZE][SIZE];
int main(int argc, char const *argv[])
{
    FILE *f = fopen("input.txt", "r");

    char c;

    int x = 1, y = 1;
    while ((c = fgetc(f)) != EOF) // buraya düz bir şekilde yazıp aşağıda matrix şeklinde ulaşmayı dene
    {
        matrix[x][y++] = c;

        if (c == '\n')
        {
            x++;
            y = 1;
        }
    }

    int number = 0;
    int bas = 1;
    int flak = 0;
    int sum = 0;
    for (int i = 1; i < SIZE - 1; i++)
    {
        for (int j = 1; j < SIZE - 1; j++)
        {
            char k = matrix[i][j];
            if (isdigit(k))
            {
                for (int x = i - 1; x < i + 2; x++)
                {
                    for (int y = j - 1; y < j + 2; y++)
                    {
                        char ka = matrix[x][y];
                        if (ka != '.' && ka != '\n' && !isdigit(ka) && ka != 0)
                        {
                            flak = 1;
                        }
                    }
                }
                number *= bas;
                number += (k - '0');
                bas = 10;
            }
            else if (!isdigit(k))
            {
                if (flak)
                {
                    sum += number;
                    flak = 0;
                }
                number = 0;
                bas = 1;
            }
        }
    }
    printf("sum = %d \n", sum);

    return 0;
}
