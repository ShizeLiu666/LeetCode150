#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Example 1:
// Input: nums = [1,2,3,1], k = 3
// Output: true

// Example 2:
// Input: nums = [1,0,1,1], k = 1
// Output: true

// Example 3:
// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false

//! 2/2 比想象中的难，因为需要考虑拿最好的结果去和k做比较，所以得遍历完数组
//! 2/2 It's harder than think, because need to consider the best result to compare with k, so you have to traverse the array.
bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    unordered_map<int, int>map; // key: elements in nums, value: corresponding index
    nums.insert(nums.begin(), 0); // ! 因为防止index 0, to prevent index = 0
    int final_answer = INT32_MAX;

    for(int i = 1; i < nums.size(); i++)
    {
        if(map[nums[i]] == 0)
        {
            map[nums[i]] = i; 
        }
        else
        {
            final_answer = min((abs(map[nums[i]] - i)), final_answer);//! 对比整个nums里所有元素，包括拿最好的结果和k比较, Compare all the elements in the entire nums, including comparing the best result with k
            // final_answer = (abs(map[nums[i]] - i) <= k) ? true : false;
            map[nums[i]] = i; //! 神来之笔，这样可以保证所有元素都被检查，防止这个测试错误 vector<int> nums2 = {1,0,1,1}; int k2 = 1;
        }
    }
    return final_answer <= k;
}

int main()
{
    vector<int> nums1 = {1,2,3,1};
    int k1 = 3;
    vector<int> nums2 = {1,0,1,1};
    int k2 = 1;
    vector<int> nums3 = {1,2,3,1,2,3};
    int k3 = 2;
    vector<int> nums4 = {4,1,2,3,1,5};
    int k4 = 3;
    vector<int> nums5 = {0,1,2,3,4,0,0,7,8,9,10,11,12,0};
    int k5 = 1;

    cout << containsNearbyDuplicate(nums1, k1) << endl;
    cout << containsNearbyDuplicate(nums2, k2) << endl;
    cout << containsNearbyDuplicate(nums3, k3) << endl;
    cout << containsNearbyDuplicate(nums4, k4) << endl;
    cout << containsNearbyDuplicate(nums5, k5) << endl;
}