#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

void sortColors(vector<int>& nums)
{
    int p1 = 0; // pointer to '0'
    int p2 = nums.size() - 1; // pointer to '2'

    vector<int> new_vec(nums.size(), 1);

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0)
        {
            new_vec[p1++] = 0;
        }
        else if(nums[i] == 2)
        {
            new_vec[p2--] = 2;
        }
    }

    nums.assign(new_vec.begin(), new_vec.end());
}

int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    sortColors(nums);
}