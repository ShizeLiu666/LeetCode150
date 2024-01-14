#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// source of the idea: https://www.bilibili.com/video/BV16N411776L/?spm_id_from=333.337.search-card.all.click&vd_source=177d972c6cb6025c46f53987677a0d43

int trap(vector<int>& height)
{
    int size = height.size();
    if(size == 2) return 0;
    int ans = 0;
    stack<int> stack; // build a stack and using the strategy of monotonic stack
    for(int i = 0; i < size; i++)
    {
        // While the current stack is not empty and the height of the current element is greater than the height of the top element of the stack
        while(stack.empty() == false && height[i] > height[stack.top()])
        {
            int prev_index = stack.top(); // point to the height of the top element in the stack
            stack.pop();
            if(stack.empty() == true) break; 
            
            int left_index =  stack.top(); // point to the height of the element to the left of the top element in the stack
            int width_val = i - left_index - 1;
            int height_val = min(height[i], height[left_index]) - height[prev_index];
            ans += width_val * height_val;
        }
        stack.push(i);
    }
    return ans;
}

int main() 
{
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(nums) << endl;
}