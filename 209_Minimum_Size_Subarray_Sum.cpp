#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Example 1:
// Input: target = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: The subarray [4,3] has the minimal length under the problem constraint.

// Example 2:
// Input: target = 4, nums = [1,4,4]
// Output: 1

// Example 3:
// Input: target = 11, nums = [1,1,1,1,1,1,1,1]
// Output: 0

int minSubArrayLen(int target, vector<int>& nums)
{
    int sum = 0;
    int p1 = 0; // p1 = start pointer, p2 = end pointer
    int minimal_length = INT32_MAX; 

    for(int p2 = 0; p2 < nums.size(); p2++)
    {
        sum += nums[p2];
        // if(sum >= target)
        // {
            while(sum >= target)
            {
                int current_length = p2 - p1 + 1;
                minimal_length = min(minimal_length, current_length);
                sum -= nums[p1++];
            }
        // }
        // cout << p1 << " " << p2 << endl;
    }
    return (minimal_length == INT32_MAX) ? 0 : minimal_length;
}

int main()
{
    int target1 = 7;
    vector<int> nums1 = {2,3,1,2,4,3};
    cout << minSubArrayLen(target1, nums1) << endl;

    int target2 = 4;
    vector<int> nums2 = {1,4,4};
    cout << minSubArrayLen(target2, nums2) << endl;

    int target3 = 11;
    vector<int> nums3 = {1,1,1,1,1,1,1,1};
    cout << minSubArrayLen(target3, nums3) << endl;

    int target4 = 15;
    vector<int> nums4 = {1,2,3,4,5};
    cout << minSubArrayLen(target4, nums4) << endl;
}