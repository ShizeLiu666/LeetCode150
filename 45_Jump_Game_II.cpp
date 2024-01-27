#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Input: nums = [2,3,1,1,4]
// Output: 2

int jump(vector<int>& nums)
{
    int max_jump = 0;
    int counter = 0;
    int end = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        if(max_jump >= i)
        {
            max_jump = max(max_jump, i + nums[i]);
            if(i == end)
            {
                end = max_jump;
                counter++;
            }
        }
    }
    return counter;   
}

int main()
{
    vector<int> nums = {1, 2};
    cout << jump(nums) << endl;
}