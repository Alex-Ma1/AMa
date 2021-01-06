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
    int residual_a = 0;
    int residual_b = 0;
    int residual_c = 0;
    int residual_d = 0;
    int num_div_a = 0;
    int num_div_b = 0;
    int num_div_c = 0;
    int num_div_d = 0;

    //Calculate the number of times coins divide into change
    if (change >= quarters) {
         num_div_a = change / quarters;
         residual_a = change % quarters;
    } if (residual_a >= dimes) {
         num_div_b = residual_a / dimes;
         residual_b = residual_a % dimes;
    } if (residual_b >= nickels) {
         num_div_c = residual_b / nickels;
         residual_c = residual_b % nickels;
    } {
         num_div_d = residual_c / pennies;
         residual_d = residual_c % pennies;
    }

    return total = num_div_a + num_div_b + num_div_c + num_div_d;

}