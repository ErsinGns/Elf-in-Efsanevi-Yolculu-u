#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct numbers
{
    int num;
    char symbol;
    int symbol_place[2];
    struct numbers *next;
};
#define SIZE 142
char matrix[SIZE][SIZE];

int main(int argc, char const *argv[])
{
    struct numbers *head = NULL;
    struct numbers *note = NULL;

    FILE *f = fopen("input.txt", "r");

    if (!f)
    {
        printf("Error opening file.\n");
        return 1;
    }

    char c;
    int x = 1, y = 1;

    while ((c = fgetc(f)) != EOF)
    {
        matrix[x][y++] = c;

        if (c == '\n')
        {
            x++;
            y = 1;
        }
    }

    fclose(f);

    int number = 0;
    int bas = 1;
    int flak = 0;

    char car;
    int place[2];

    for (int i = 1; i < SIZE - 1; i++)
    {
        for (int j = 1; j < SIZE - 1; j++)
        {
            struct numbers *temp = NULL;
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
                            car = ka;
                            place[0] = x;
                            place[1] = y;
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

                    temp = (struct numbers *)malloc(sizeof(struct numbers));
                    temp->symbol = car;
                    temp->num = number;
                    temp->symbol_place[0] = place[0];
                    temp->symbol_place[1] = place[1];

                    if (!head)
                    {
                        head = temp;
                        note = temp;
                    }
                    else
                    {
                        note->next = temp;
                        note = temp;
                    }

                    flak = 0;
                }
                number = 0;
                bas = 1;
            }
        }
    }
    int sum = 0;

    struct numbers *current;
    while (head != NULL)
    {
        current = head->next;
        while (current != NULL)
        {
            if (current->symbol_place[0] == head->symbol_place[0] && current->symbol_place[1] == head->symbol_place[1])
                sum += current->num * head->num;

            current = current->next;
        }
        head = head->next;
    }
    printf("sum %d", sum);

    return 0;
}
