#include <cs50.h>
#include <stdio.h>

int main(void) // Linear Search Code
{
    int numbers [] = {20, 500, 10, 100, 1, 50};

    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] ==n)
        {
            printf("found\n");
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}
