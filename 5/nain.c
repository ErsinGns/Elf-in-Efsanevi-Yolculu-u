#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define seed_len 20
// 4
#define MIN(x, y) (x < y ? x : y)
#define MAX(x, y) (x > y ? x : y)

int main(int argc, char const *argv[])
{
    FILE *f = fopen("input.txt", "r");
    char c;
    int n = 0;
    long long int numbers[3] = {-1, -1, -1};
    int bas = 1;
    long long int number = 0;
    long long int seeds[seed_len];
    long long int yedek_seeds[seed_len];

    int k = 0;
    while ((c = fgetc(f)) != EOF)
    {
        if (c == ':')
        {
            printf("----------\n");
            n++;
            for (int i = 0; i < seed_len; i++)
            {
                yedek_seeds[i] = seeds[i];
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
                    yedek_seeds[k++] = number;
                }

                number = 0;
                bas = 1;
            }
        }

        else
        {
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
            for (int i = 0; i < seed_len; i++)
            {
                // printf("*---%d ---", seeds[i]);

                if (seeds[i] >= numbers[1] && seeds[i] < numbers[1] + numbers[2] && yedek_seeds[i] == seeds[i])
                {
                    seeds[i] = seeds[i] - numbers[1] + numbers[0];
                }

                for (int i = 0; i < seed_len; i++)
                {
                    printf("%lld ", seeds[i]);
                }

                //     for(int i = 0; i < 3; i++){
                //  printf(" %d",numbers[i]);
                //   }
                printf("\n");
                printf("**********\n");
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
    int min = seeds[1];
    for (int i = 0; i < seed_len; i++)
    {
        if (min > seeds[i])
        {
            min = seeds[i];
        }
    }
    printf("min = %d", min);

    return 0;
}
