#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// nums = [1,2,3,4,5,6,7], k = 3
// [5,6,7,1,2,3,4]

void rotate(vector<int>& nums, int k)
{
    int size = nums.size();
    vector<int> new_vec(size);
    for (int i = 0; i < size; ++i)
    {
        new_vec[(i + k) % size] = nums[i];
    }
    nums.assign(new_vec.begin(), new_vec.end());
}

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    rotate(nums, 3);
}