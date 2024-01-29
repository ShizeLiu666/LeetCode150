#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]

vector<int> twoSum(vector<int>& nums, int target)
{
    // hash map:
    // key => elements in nums
    // value => index of element

    unordered_map<int, int> hashtable;
    // vector<int> result;

    for(int i = 0; i < nums.size(); i++)
    {
        // this element has been added
        if(hashtable.find(target - nums[i]) != hashtable.end())
        {
            // result.push_back(hashtable[target - nums[i]]);
            // result.push_back(i);
            // cout << hashtable[target - nums[i]] << " " << i << " " << endl;
            return {hashtable[target - nums[i]], i}; 
        }
        hashtable[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> nums1 = {2,7,11,15};
    int target1 = 9;
    vector<int> output1 = twoSum(nums1, target1);
    
    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    vector<int> output2 = twoSum(nums2, target2);

    vector<int> nums3 = {3,3};
    int target3 = 6;
    vector<int> output3 = twoSum(nums3, target3);
}