#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Example 1:

// Input: nums = [1,2,3,4]
// Output: [24,12,8,6]
// Example 2:

// Input: nums = [-1,1,0,-3,3]
// Output: [0,0,9,0,0]

// Method1 : General
// vector<int> productExceptSelf(vector<int>& nums)
// {
//    vector<int> result_vec(nums.size(), 0);
//    int result = 1;
//    int counter = 0;

//     for(int i = 0; i < nums.size(); i++)
//     {
//         result *= (nums[i] == 0) ? 1 : nums[i];
//         counter += (nums[i] == 0) ? 1 : 0;
//     }
//     // cout << result << endl;
//     if(counter == 0)
//     {
//         for(int i = 0; i < nums.size(); i++)
//         {
//             result_vec[i] = result / nums[i];
//         }
//     }
//     else if(counter == 1)
//     {
//         for(int i = 0; i < nums.size(); i++)
//         {
//             result_vec[i] = (nums[i] == 0) ? result : 0;
//         }
//     }

//     // print the result for checking
//     for(int i = 0; i < nums.size(); i++)
//     {
//         cout << result_vec[i] << " ";
//     }
//     cout << endl;

//    return result_vec; 
// }

// Method2 : List of left and right products 左右乘积列表
vector<int> productExceptSelf(vector<int>& nums)
{
    // sum of prefix 前缀之积
    vector<int> prefix_product(nums.size(), 1);
    for(int i = 1; i < nums.size(); i++)
    {
        prefix_product[i] = prefix_product[i - 1] * nums[i - 1];
    }

    // sum of suffix 后缀之积
    // ! opt2. 优化2 => vector<int> suffix_product(nums.size(), 1);
    int optimizer = 1;
    for(int i = nums.size() - 1; i >= 0; i--)
    {
        
        prefix_product[i] *= optimizer;
        optimizer *= nums[i];
    }

    // calculate final result (prefix_product = result_vec) 
    //! opt1.优化1 => vector<int> result_vec; 
    // for(int i = 0; i < nums.size(); i++)
    // {
    //     prefix_product[i] *= suffix_product[i];
    // }

    // print the result for checking
    for(int i = 0; i < nums.size(); i++)
    {
        cout << prefix_product[i] << " ";
    }
    cout << endl;

   return prefix_product; 
}

int main()
{
    vector<int> nums1 = {1,2,3,4};
    vector<int> nums2 = {-1,1,0,-3,3};
    vector<int> nums3 = {0, 0};
    vector<int> nums4 = {2,4,1,3,5};
    vector<int> result1 = productExceptSelf(nums1);
    vector<int> result2 = productExceptSelf(nums2);
    vector<int> result3 = productExceptSelf(nums3);
    vector<int> result4 = productExceptSelf(nums4);
}
