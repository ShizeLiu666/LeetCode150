#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Example 1:

// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
// Example 2:

// Input: numbers = [2,3,4], target = 6 / 7
// Output: [1,3] / [2,4]
// Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
// Example 3:

// Input: numbers = [-1,0], target = -1
// Output: [1,2]
// Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

vector<int> twoSum(vector<int>& numbers, int target)
{
    int p1 = 0, p2 = numbers.size() - 1;
    
    while(numbers[p1] + numbers[p2] != target)
    {
        if(target - numbers[p2] > numbers[p1])
        {
            p1++;
        }
        else
        {
            p2--;
        }
    }
    
    // cout << p1 + 1 << " " << p2 + 1 << " " << endl;

    vector<int> pointers = {p1 + 1, p2 + 1};
    return pointers;
}

int main()
{
    vector<int> numbers1 = {2,7,11,15};
    int target1 = 9;
    vector<int> numbers2 = {2,3,4};
    int target2 = 6;
    vector<int> numbers3 = {-1,0};
    int target3 = -1;
    vector<int> output1 = twoSum(numbers1, target1);
    vector<int> output2 = twoSum(numbers2, target2);
    vector<int> output3 = twoSum(numbers3, target3);
}