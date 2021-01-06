#include <stdio.h>
#include <math.h>
#include <cs50.h>

int change_owed(void);
int coins(void);
int a;
int total;

//Print amount owed in cents, and number of coins required to repay customer
int main(void)
{
    int coint_count = coins();
    printf("Total amount owed in cents: %i\n", a);
    printf("Total coins needed to repay customer: %i\n", total);
}

//Get the amount owed by customer, dollars converted to cents
int change_owed(void)
{
    float x;
    do
    {
        x = get_float("How much does the customer owe (in $US)?: ");
    }
    while (x <= 0);
    return a = round(x*100);
}

//Return number of coins needed to repay amount owed
int coins(void)
{
    int change = change_owed();
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    int residual = 0;
    int num_div = 0;

    //Calculate the number of times coins divide into change
    if (change >= quarters) {
         num_div = num_div + change / quarters;
         residual = change % quarters;
    }
    if (residual >= dimes) {
         num_div = num_div + residual / dimes;
         residual = residual % dimes;
    }
    if (residual >= nickels) {
         num_div = num_div + residual / nickels;
         residual = residual % nickels;
    }
    if (residual >= pennies) {
         num_div = num_div + residual;
    }

    return num_div;
}