#include <stdio.h>
#include <ctype.h>

// char txt[] = "deneme.txt";
char txt[] = "input.txt";
int posible[100];

int main(int argc, char const *argv[])
{
    int n[] = {14, 12, 13};
    int renk_miktar[5] = {0};
    int copy[3] = {0};
    char c;
    int number = 0;
    int basamak = 1;
    int sum = 0;
    int tur = 0;
    int k = 1;
    FILE *f = fopen(txt, "r");
    int cros = 1, cros_sum = 0;

    while ((c = fgetc(f)) != EOF)
    {
        if (isdigit(c))
        {
            number *= basamak;
            number += (c - '0');
            basamak *= 10;
        }
        else
        {
            basamak = 1;
        }

        if (c == ':')
        {
            renk_miktar[0] = number;
            number = 0;
        }
        else if (c == 'b')
        {
            renk_miktar[1] += number;
            number = 0;
        }
        else if (c == 'd')
        {
            renk_miktar[2] += number;
            number = 0;
        }
        else if (c == 'g')
        {
            renk_miktar[3] += number;
            number = 0;
        }
        int flak = 1;

        if (c == ';' || c == '\n')
        {
            for (int i = 1; i < 4; i++)
            {
                if (renk_miktar[i] > copy[i - 1])
                {
                    copy[i - 1] = renk_miktar[i];
                }

                if ((renk_miktar[i] > n[i - 1]))
                {
                    flak = 0;
                }
                renk_miktar[i] = 0;
            }
            if (flak && k)
            {

                renk_miktar[4] = 1;
            }
            if (!flak)
            {

                renk_miktar[4] = 0;
                k = 0;
            }
        }

        if (c == '\n')
        {
            for (int i = 0; i < 3; i++)
            {

                cros *= copy[i];
            }
            cros_sum += cros;

            for (int i = 0; i < 3; i++)
            {
                copy[i] = 0;
            }
            cros = 1;

            k = 1;
        }
    }
    printf("sum = %d\n", cros_sum);

    return 0;
}
