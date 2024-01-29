#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.

// Example 2:
// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.

// Example 3:
// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] > 0) break;

        // Check for duplicate occurrences of element i; 对i元素进行查重
        if(i > 0 && nums[i] == nums[i - 1]) continue; // ! 如果当前的元素《之前已经处理过了》

        int p1 = i + 1; // left pointer to the i + 1 element;
        int p2 = nums.size() - 1; // right pointer to the end element

        while(p1 < p2)
        {
            if(nums[i] + nums[p1] + nums[p2] > 0) p2--;
            else if(nums[i] + nums[p1] + nums[p2] < 0) p1++;
            else // if(nums[i] + nums[p1] + nums[p2] == 0)
            {
                // found result
                vector<int> temp = {nums[i], nums[p1], nums[p2]};
                result.push_back(temp);

                // Check for duplicate occurrences of element left and right; 对left and right pointer元素进行查重
                while(p1 < p2 && nums[p1] == nums[p1 + 1]) p1++; // ! 如果指针的元素《之后还会出现》
                while(p1 < p2 && nums[p2] == nums[p2 - 1]) p2--;

                p1++;
                p2--;
            }
        }

    }

    // for (size_t i = 0; i < result.size(); ++i)
    // {
    //     for (size_t j = 0; j < result[i].size(); ++j)
    //     {
    //         cout << result[i][j] << " ";
    //     }
    //     cout << std::endl;
    // }

    return result;
}

int main()
{
    // vector<int> nums1 = {-1,0,1,2,-1,-4};
    // vector<vector<int>> result1 = threeSum(nums1);
    vector<int> nums2 = {0, 0, 0};
    vector<vector<int>> result1 = threeSum(nums2);
}