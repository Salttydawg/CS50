#include <cs50.h>
#include <stdio.h>

int fact;
int n;

//not printable because I am just using this for notes on recursion

int main(void)
{
     if(n == 1)
         return 1;

    else if (n % 2 == 0)
    {
        return 1 + collatz(n/2);
    }

    else
    {
        return 1 + collatz(3*n + 1);
    }

}
