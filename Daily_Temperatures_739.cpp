#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// input: temperatures = [73,74,75,71,69,72,76,73]
// output: [1,1,4,2,1,1,0,0]

// input: temperatures = [30,40,50,60]
// output: [1,1,1,0]

vector<int> dailyTemperatures(vector<int>& temperatures)
{
    int size = temperatures.size();
    vector<int> result(size, 0);
    stack<int> stack; // build a stack and using the strategy of monotonic stack
    
    for(int i = size - 1; i >= 0; i--)
    {
        // cout << temperatures[i] << ',' << stack.top() << endl;
        while (!stack.empty() && temperatures[i] >= temperatures[stack.top()])
        {
            stack.pop();
        }
        if (!stack.empty())
        {
            result[i] = stack.top() - i;
        }
        stack.push(i);
    }

    // for(int i = 0; i < size; i++)
    // {
    //     cout << result[i] << endl;
    // }
    return result;
}

int main()
{
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    dailyTemperatures(temperatures);
}