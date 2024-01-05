#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int p1 = 2;
    if(nums.size() > 2)
    {
        for(int p2 = 2; p2 < nums.size(); p2++)
        {
            if(nums[p2] > nums[p1 - 2])
            {
                nums[p1++] = nums[p2];
            }
        }
    }
    else
    {
        p1 = nums.size();
    }
    return p1; // no need + 1 here because the p1 we started from 2 this time
}

int main()
{
    // vector<int> nums = {0,0,1,1,1,1,2,3,3};
    vector<int> nums = {1};
    int length = removeDuplicates(nums);
    
    cout << "The length of array after removing duplicates is: " << length << endl;
    cout << "The modified array is: ";

    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}