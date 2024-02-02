#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

// Example 1:
// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1

// Example 2:
// Input: n = 2
// Output: false

using namespace std;

//! 2/2 还是挺简单的，hashmap这题的左右就是用来检查是否存在循环，其他操作见以下详细代码 
//! 2/2 Still quite simple, hashmap the question of the left and right is used to check whether there is a loop, other operations see the following detailed code 

bool isHappy(int n)
{
    int current_sum = 0;
    int target = n;
    unordered_map<int, bool> map;
    do
    {
        while(target > 0)
        {
            current_sum += (target % 10) * (target % 10);
            target /= 10;
        }
        // cout << current_sum << endl;
        if(current_sum > 0 && map[current_sum] == false)
        {
            map[current_sum] = true;
        }
        else
        {
            return false; // exist loop so false
        }
        target = current_sum;
        current_sum = 0;
    } while (target != 1);
    
    return true;
}

int main()
{
    int n1 = 19;
    int n2 = 2;
    // cout << isHappy(n1) << endl;
    cout << isHappy(n2) << endl;
}