#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool canJump(vector<int>& nums)
{
    int jump_count = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(i > jump_count) 
        {
            return false;
        }
        jump_count = max(jump_count, i + nums[i]);
    }
    return true;
}

int main()
{
    vector<int> nums = {3,2,1,0,4};
    cout << canJump(nums) << endl;
}