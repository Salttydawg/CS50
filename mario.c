#include <cs50.h>
#include <stdio.h>

void print_row(int space, int bricks, int n);

int main(void)
{
    // Prompt user for height
    int n;
    do
    {
        n = get_int("What is the height of the pyramid? ");
    }
    while (n < 1 || n > 8);

    // Print a pyramid of that height
    for (int i = 0; i < n; i++)
    {
        // Print row of bricks
        print_row(n, i + 1, n);
    }
}

void print_row(int space, int bricks, int n)
{
    // Print spaces
    for (int j = 0; j < n - bricks; j++)
    {
        printf(" ");
    }

    // Print Bricks
    for (int column = 0; column < bricks; column++)
    {
        printf("#");
    }

    // Move to next line
    printf("\n");
}
