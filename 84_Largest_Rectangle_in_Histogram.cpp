#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

int largestRectangleArea(vector<int>& heights)
{
    int result = 0;
    stack<int> stack; // build a stack and using the strategy of monotonic stack
    // add a zero to the end and beginning to original heights
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    stack.push(0); //  also add a zero to the stack

    for(int i = 1; i < heights.size(); i++)
    {
        // case 1. science this problem involves a monotonically decreasing stack, it is directly pushed onto the stack
        if(heights[i] > heights[stack.top()])
        {
            stack.push(i);
        }
        // case 2.
        else if(heights[i] == heights[stack.top()])
        {
            stack.pop();
            stack.push(i);
        }
        // case 3. need to calculate the result
        else
        {
            while(!stack.empty() && heights[i] < heights[stack.top()])
            {
                int mid = stack.top();
                stack.pop();
                if(!stack.empty())
                {
                    int left = stack.top(); 
                    int right = i;
                    int weight = right - left - 1;
                    int height = heights[mid];
                    result = max(result, weight * height);
                }
            }
            stack.push(i);
        }
    }

    return result;    
}

int main()
{
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights) << endl;
}