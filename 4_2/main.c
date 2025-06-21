#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define ilk 10
// 5
//  10
#define iki 25
// 8
//  25

#define size 198

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
    int miktar[size][2] = {0};
    int k = 0;
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
            int count = 0;

            for (int i = 0; i < ilk; i++)
            {
                for (int j = 0; j < iki; j++)
                {
                    if (ilk_list[i] == iki_list[j])
                    {
                        count++;
                    }
                }
            }
            miktar[k++][0] = count;
            // printf("%d \n", count);
            number = 1;
            forst = 1;
        }
    }
    for (int i = 0; i < k; i++)
    {
        miktar[i][1] = 1;
    }

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < miktar[i][0]; j++)
        {

            miktar[1 + i + j][1] += 1 * miktar[i][1];
            /* for(int i = 0; i < k; i++){
             printf("%d ", miktar[i][1]);
         }
         printf("\n");*/
        }
        //   printf("\n");
    }
    for (int i = 0; i < k; i++)
    {
        find += miktar[i][1];
    }

    printf("point %d ", find);

    return 0;
}
