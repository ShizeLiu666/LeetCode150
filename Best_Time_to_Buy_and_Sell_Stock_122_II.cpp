#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Input: prices = [7,1,5,3,6,4]
// Output: 5

// ! Greedy algorithm
int maxProfit(vector<int>& prices)
{
    int profit = 0;

    for(int i = 0; i < prices.size() - 1; i++)
    {
        int buying_price = prices[i];
        int sending_price = prices[i + 1];
        profit += max(0, sending_price - buying_price);
    }

    return profit;
}

int main()
{
    vector<int> prices = {7,1,5,3,6,4};
    cout << maxProfit(prices) << endl;
}