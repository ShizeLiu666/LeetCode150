#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Example 1:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1

int maxArea(vector<int>& height)
{
    int p1 = 0;
    int p2 = height.size() - 1;
    int bestArea = min(height[p1], height[p2]) * (p2 - p1);
    // cout << bestArea << endl;
    while(p1 < p2)
    {
        // if(min(height[p1], height[p2]) * (p2 - p1) > bestArea)
        // {
        //     bestArea = min(height[p1 + 1], height[p2]) * (p2 - p1);
        // }
        bestArea = max(min(height[p1], height[p2]) * (p2 - p1), bestArea);
        
        if(height[p1] < height[p2])
        {
            p1++;
        }
        else
        {
            p2--;
        }
        
    }
    return bestArea;
}

int main()
{
    vector<int> height1 = {1,8,6,2,5,4,8,3,7};
    vector<int> height2 = {1,1};
    cout << maxArea(height1) << endl;
    // cout << maxArea(height2) << endl;
}