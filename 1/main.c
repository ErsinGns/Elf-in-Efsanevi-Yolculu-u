// https://adventofcode.com/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
    FILE *file = fopen("input.txt", "r");
    char c;
    int first = 0, end = 0;
    int flag = 1;
    int sum = 0;

    while ((c = fgetc(file)) != EOF)
    {
        if (c == '\n')
        {
            sum += first * 10 + end;

            first = end = 0;
            flag = 1;
        }
        else if (isdigit(c))
        {
            if (flag)
            {
                flag = 0;
                first = c - '0';
            }
            end = c - '0';
        }
    }

    printf("sum = %d\n", sum);

    return 0;
}
