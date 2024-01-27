#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Example 1:
// Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// Output: 3
// Explanation:
// Start at station 3 (index 3) and fill up with 4 unit of gas. Your tank = 0 + 4 = 4
// Travel to station 4. Your tank = 4 - 1 + 5 = 8
// Travel to station 0. Your tank = 8 - 2 + 1 = 7
// Travel to station 1. Your tank = 7 - 3 + 2 = 6
// Travel to station 2. Your tank = 6 - 4 + 3 = 5
// Travel to station 3. The cost is 5. Your gas is just enough to travel back to station 3.
// Therefore, return 3 as the starting index.

// method: greedy
int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
{
    int current_sum = 0;
    int total_sum = 0; // total sum of remaining gas, if < 0 means that it is unavailable complete circuit
    int start = 0; // record starting index

    for(int i = 0; i < gas.size(); i++)
    {
        current_sum += gas[i] - cost[i];
        total_sum += gas[i] - cost[i];
        if(current_sum < 0)
        {
            start = i + 1;
            current_sum = 0;
        }
    }
    if(total_sum < 0) return -1;
    return start;
}

int main()
{
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    cout << canCompleteCircuit(gas, cost) << endl;
}