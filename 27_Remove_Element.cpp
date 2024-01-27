#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int n = nums.size();
    int p1 = 0;
    // nums = [3,2,2,3], val = 3
    for(int p2 = 0; p2 < n; p2++)
    {
        if(nums[p2] != val)
        {
            nums[p1++] = nums[p2];
        }
    }

    // for(int p2 = 0; p2 < n; p2++)
    // {
    //     cout << nums[p2] << ' ' << endl;
    // }

    return p1;
}

int main()
{
    vector<int> nums = {3,2,2,3};
    int val = 3;
    cout << removeElement(nums, val) << endl;
}