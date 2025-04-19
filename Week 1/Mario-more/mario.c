#include <cs50.h>
#include <stdio.h>

int n;

void print_row(int bricks);

int main(void)
{
    // prompt user for the amount of bricks no more than 8 no less than 1
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    // print the height of that pyramid
    // print row of bricks
    for (int i = 0; i < n; i++)
    {
        print_row(i + 1);
    }
}

void print_row(int bricks)
{
    int spaces = n - bricks;
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }

    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }

    printf("  ");

    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }

    printf("\n");
}
