#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *numbers[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char str[100];
int idx;

int find_world_number(char c)
{
    int flak_string = 1;

    str[idx++] = c;
    str[idx] = '\0';

    for (int i = 0; i < 9; i++)
    {
        if (strcmp(str, numbers[i]) == 0)
        {
            str[0] = str[idx - 2];
            str[1] = str[idx - 1];
            idx = 2;

            return i + 1;
        }
        else if (strstr(numbers[i], str))
            flak_string = 0;
    }

    if (flak_string)
        if (idx > 2)
        {
            str[0] = str[idx - 2];
            str[1] = str[idx - 1];
            idx = 2;
        }

    return 0;
}

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
        else if (isalpha(c))
        {
            int temporary = find_world_number(c);
            if (temporary != 0)
            {
                if (flag)
                {
                    first = temporary;
                    flag = 0;
                }
                end = temporary;
            }
        }
        else
        {
            if (flag)
            {
                first = c - '0';
                flag = 0;
            }
            end = c - '0';
        }
    }

    printf("sum = %d\n", sum);

    return 0;
}
