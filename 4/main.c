#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ilk 10
// 5
#define iki 25
// 8

int main(int argc, char const *argv[])
{
    FILE *f = fopen("input.txt", "r");

    char c;
    int flak_nokta = 0, flak_cizgi = 0;
    int bas = 1, num = 0;

    int i = 0, j = 0;
    int ilk_list[ilk], iki_list[iki];
    int find = 0;
    int number = 1;
    int forst = 1;

    while ((c = getc(f)) != EOF)
    {
        if (flak_cizgi)
        {
            if (c == ' ' || c == '\n')
            {
                if (num != 0)
                {
                    iki_list[j++] = num;
                }
                bas = 1;
                num = 0;
            }
            if (isdigit(c))
            {
                num *= bas;
                num += (c - '0');
                bas = 10;
            }
        }
        else if (flak_nokta)
        {
            if (c == ' ')
            {
                if (num != 0)
                {
                    ilk_list[i++] = num;
                }
                bas = 1;
                num = 0;
            }

            if (isdigit(c))
            {
                num *= bas;
                num += (c - '0');
                bas = 10;
            }
        }

        if (c == ':')
            flak_nokta = 1;

        else if (c == '|')
            flak_cizgi = 1;

        else if (c == '\n')
        {
            flak_cizgi = 0;
            flak_nokta = 0;
            i = 0;
            j = 0;

            for (int i = 0; i < ilk; i++)
            {
                for (int j = 0; j < iki; j++)
                {
                    if (ilk_list[i] == iki_list[j])
                    {
                        find += number;
                        if (!forst)
                            number *= 2;
                        else
                            forst = 0;
                    }
                }
            }
            number = 1;
            forst = 1;
        }
    }
    printf("point %d ", find);

    return 0;
}
