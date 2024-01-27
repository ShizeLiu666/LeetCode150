#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int p1 = 0;
    for(int p2 = 1; p2 < nums.size(); p2++)
    {
        if(nums[p2] > nums[p1])
        {
            p1++;
            nums[p1] = nums[p2];
        }
    }
    return p1 + 1; // because the p1 we started from 0
}

int main()
{
    vector<int> nums = {1, 1, 2};
    int length = removeDuplicates(nums);
    
    cout << "The length of array after removing duplicates is: " << length << endl;
    cout << "The modified array is: ";

    for (int i = 0; i < length; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}