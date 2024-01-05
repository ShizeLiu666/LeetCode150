#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Input: prices = [7,1,5,3,6,4]
// Output: 5

int maxProfit(vector<int>& prices)
{
    int min_price = 1e9; // investment price
    int max_profit = 0; // fitness / grades

    for(int i = 0; i < prices.size(); i++)
    {
        int current_price = prices[i];
        int current_profit = current_price - min_price;

        if(current_price < min_price)
        {
            min_price = current_price;
        }
        else if(current_price - min_price > max_profit)
        {
            max_profit = current_profit;
        }
    }

    return max_profit;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;
}