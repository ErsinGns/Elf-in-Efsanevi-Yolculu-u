#include <stdio.h>
#include <ctype.h>

// char txt[] = "deneme.txt";
char txt[] = "input.txt";

enum
{
    Game,
    Blue,
    Red,
    Green,
    Possible
};

int main(int argc, char const *argv[])
{
    int n[] = {14, 12, 13};
    int renk_miktar[5] = {0};
    int number = 0;
    int digit = 1;
    int sum = 0;
    int k = 1;

    char c;
    FILE *f = fopen(txt, "r");

    while ((c = fgetc(f)) != EOF)
    {

        if (isdigit(c))
        {
            number *= digit;
            number += c - '0';
            digit *= 10;
        }
        else
        {
            digit = 1;
        }

        if (c == ':')
        {
            renk_miktar[Game] = number;
            number = 0;
        }
        else if (c == 'b')
        {
            renk_miktar[Blue] += number;
            number = 0;
        }
        else if (c == 'd')
        {
            renk_miktar[Red] += number;
            number = 0;
        }
        else if (c == 'g')
        {
            renk_miktar[Green] += number;
            number = 0;
        }
        int flak = 1;

        if (c == ';' || c == '\n')
        {
            for (int i = 1; i < 4; i++)
            {
                if ((renk_miktar[i] > n[i - 1]))
                {
                    flak = 0;
                }
                renk_miktar[i] = 0;
            }

            if (k)
            {
                if (flak)
                    renk_miktar[Possible] = 1;
                else
                {
                    renk_miktar[Possible] = 0;
                    k = 0;
                }
            }
        }

        if (c == '\n')
        {
            k = 1;
            if (renk_miktar[4])
            {
                sum += renk_miktar[Game];
            }
        }
    }

    printf("sum = %d\n", sum);

    return 0;
}
