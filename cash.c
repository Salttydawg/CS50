#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt the user for change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Calculate how many quarters you should give customer
    int quarters = calculate_quarters(cents);
    cents -= quarters * 25;

    // Calculate how many dimes you should give the customer
    int dimes = calculate_dimes(cents);
    cents -= dimes * 10;

    // Calculate how many nickels you should give customer
    int nickels = calculate_nickels(cents);
    cents -= nickels * 5;

    // Calculate how many pennies you should give customer
    int pennies = calculate_pennies(cents);
    cents -= pennies * 1;

    // Sum of the number of quarters, dimes, nickels, and pennies used
    int total_coins = quarters + dimes + nickels + pennies;

    // Print that sum
    printf("%i\n", total_coins);
}

int calculate_quarters(int cents)
{
    return cents / 25;
}

int calculate_dimes(int cents)
{
    return cents / 10;
}

int calculate_nickels(int cents)
{
    return cents / 5;
}

int calculate_pennies(int cents)
{
    return cents;
}
