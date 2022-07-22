#include <stdio.h>

int maxProfit(int* prices, int pricesSize);

int main(void)
{
    int prices[] = {7,1,5,3,6,4};
    int size = sizeof(prices)/sizeof(prices[0]);
    printf("%i\n", maxProfit(prices, size));
}


int maxProfit(int* prices, int pricesSize)
{
    // assigning cheapest buy to the first element
    int min_buy = prices[0];
    int profit = 0;
    // check buying price from the second element
    for (int i = 1; i < pricesSize; i++)
    {
        // if the current value is bigger than the best buy so far, check the profit
        if (prices[i] > min_buy)
        {
            // if stored profit is smaller than the one for this transaction, this is the new best
            int pr = prices[i]-min_buy;
            if (profit <= pr)
                profit = pr;
        }
        // if the current value is smaller than the best buy so far, this is the new best buy
        else
            min_buy = prices[i];
    }
    if (profit > 0)
        return profit;
    else
        return 0;
}
