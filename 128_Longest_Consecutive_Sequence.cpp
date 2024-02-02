#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Example 1:
// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

// Example 2:
// ! 要考虑重复元素情况 To consider the case of duplicate elements
// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

//! 2.2 抖机灵法，没怎么用到hashmap，力扣官方答案也没很大说服力

int longestConsecutive(vector<int>& nums)
{
    if(nums.size() == 0) return 0;
    unordered_map<int, int>map;
    vector<int>temp;
    for(int i = 0; i < nums.size(); i++)
    {
        if(map[nums[i]] == 0)
        {
            map[nums[i]]++;
            temp.push_back(nums[i]);
        }
    }
    if(temp.size() == 1) return 1;
    sort(temp.begin(), temp.end());
    int result = 1;
    int counter = 1;

    for(int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";
    }

    for(int i = 1; i < temp.size(); i++)
    {
        if(abs(temp[i] - temp[i - 1]) == 1)
        {
            counter++;
        }
        else
        {
            counter = 1;
        }
        result = max(counter, result);
    }

    cout << endl;
    return result;
}

int main()
{
    // vector<int> nums1 = {100,4,200,1,3,2};
    // cout << longestConsecutive(nums1) << endl;
    // vector<int> nums2 = {0,3,7,2,5,8,4,6,0,1};
    // cout << longestConsecutive(nums2) << endl;
    vector<int> nums3 = {9,1,4,7,3,-1,0,5,8,-1,6};
    cout << longestConsecutive(nums3) << endl;
}
