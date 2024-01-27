#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int majorityElement(vector<int>& nums)
{
    unordered_map<int, int> counts;
    int majority = 0, count = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        counts[nums.at(i)]++;
        if(counts[nums.at(i)] > count)
        {
            majority = nums.at(i); // key
            count = counts[nums.at(i)]; // value
        }
    }
    return majority;
}

int main()
{
    vector<int> nums = {2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl;
}