#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // used for sort function

using namespace std;

// Input: citations = [3,0,6,1,5]
// Output: 3

int hIndex(vector<int>& citations) {
    
    sort(citations.begin(), citations.end());
    vector<int> nums = citations;

    int counter = 0;
    for(int i = 0; i < nums.size(); i++)
    {
        if(citations[i] < counter)
        {
            
        }
    }
    
    return citations[4];
}

int main()
{
    vector<int> nums = {3, 0, 6, 1, 5};
    hIndex(nums);
}