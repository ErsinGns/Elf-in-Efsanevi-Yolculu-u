#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    FILE *f = fopen("input.txt", "r");
    char c;
    unsigned long long int time;
    unsigned long long int mil;
    long long unsigned int number = 0;
    int bas = 1;
    int k = -1;

    while ((c = fgetc(f)) != EOF)
    {
        if (c == ':')
        {
            time = number;
            number = 0;
            bas = 1;
            k++;
        }
        else if (isdigit(c))
        {
            number *= bas;
            number += c - '0';
            bas = 10;
        }
        else if (c == '\n' && k)
        {
            mil = number;
            number = 0;
            bas = 0;
        }
    }
    printf("timee = %lld mil = %lld", time, mil);

    unsigned long long int z = time;
    long long int corse = 0;
    long long int miktar = 0;
    for (int i = 0; i < time; i++)
    {
        corse = (z - i) * i;
        if (corse > mil)
        {
            miktar++;
        }
    }

    printf("\nmiktar = %lld", miktar);

    return 0;
}
