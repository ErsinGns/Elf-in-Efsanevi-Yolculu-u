#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define seed_len 4
// 4
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

int main(int argc, char const *argv[])
{
    FILE *f = fopen("deneme.txt", "r");
    char c;
    int n = 0;
    long long int numbers[3] = {-1, -1, -1};
    int bas = 1;
    long long int number = 0;
    long long int seeds[seed_len];
    long long int *yedek_seeds;
    int flak = 0;
    int len = 0;
    int k = 0, l = 0;
    long long int *liste;

    while ((c = fgetc(f)) != EOF)
    {
        printf("aaaa");
        if (c == ':')
        {
            printf("----------\n");
            n++;
            if (n > 2)
                for (int i = 0; i < len; i++)
                {
                    yedek_seeds[i] = liste[i];
                }
        }
        if (n == 1)
        {
            if (isdigit(c))
            {
                number *= bas;
                number += c - '0';
                bas = 10;
            }
            else
            {
                if (bas == 10)
                {
                    seeds[k] = number;
                }

                number = 0;
                bas = 1;
            }
        }

        else
        {
            printf("aaaaaa");
            k = 0;
            if (n == 2 && !flak)
            {
                flak = 1;
                for (int i = 1; i < seed_len; i += 2)
                {
                    len += seeds[i];
                }
                liste = calloc(len, sizeof(long long int));

                yedek_seeds = calloc(len, sizeof(long long int));
                for (int i = 0; i < len; i++)
                {
                    printf("%lld  %lld ", liste[i], yedek_seeds[i]);
                }
                for (int i = 0; i < seed_len; i += 2)
                {
                    for (int j = seeds[i]; j < seeds[i] + seeds[i + 1]; j++)
                    {
                        // printf("a");
                        // *(liste + k ++) = j;
                        //  *(yedek_seeds + l++) = j;
                    }
                }

                for (int i = 0; i < len; i++)
                {
                    printf("%lld ", *(liste + i));
                }
                printf("************ %d\n", len);
            }
            if (isdigit(c))
            {
                // putchar(c);
                number *= bas;
                number += c - '0';
                bas = 10;
            }

            else
            {
                if (bas == 10)
                    for (int i = 0; i < 3; i++)
                    {
                        if (numbers[i] == -1)
                        {
                            numbers[i] = number;
                            break;
                        }
                    }
                bas = 1;
                number = 0;
            }
        }

        if (c == '\n' && numbers[2] != -1)
        {
            for (int i = 0; i < len; i++)
            {
                // printf("*---%d ---", seeds[i]);

                if (liste[i] >= numbers[1] && liste[i] < numbers[1] + numbers[2] && yedek_seeds[i] == liste[i])
                {
                    liste[i] = liste[i] - numbers[1] + numbers[0];
                }

                for (int i = 0; i < seed_len; i++)
                {
                    // printf("%lld ", seeds[i]);
                }

                for (int i = 0; i < 3; i++)
                {
                    printf(" %lld", numbers[i]);
                }
                printf("\n");

                // printf("**********\n");
            }
        }
        if (c == '\n' && numbers[2] != -1)
        {
            for (int i = 0; i < 3; i++)
            {
                numbers[i] = -1;
            }
        }
    }
    int min = liste[1];
    for (int i = 0; i < len; i++)
    {
        if (min > liste[i])
        {
            min = liste[i];
        }
    }
    printf("min = %d", min);

    return 0;
}