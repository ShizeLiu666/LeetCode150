#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Example 1:

// Input: s = "III"
// Output: 3
// Explanation: III = 3.
// Example 2:

// Input: s = "LVIII"
// Output: 58
// Explanation: L = 50, V= 5, III = 3.
// Example 3:

// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

int romanToInt(string s)
{
    unordered_map<char, int> value = 
    {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},{'C', 100}, {'D', 500}, {'M', 1000}
    };

    int ans = 0;

    for(int i = 0; i < s.size(); i++)
    {
        if(i != s.size() && value[s[i]] < value[s[i + 1]])
        {
            ans -= value[s[i]];
        }
        else
        {
            ans += value[s[i]];
        }
    }
    
    return ans;
}

int main()
{
    string s1 = "III"; 
    string s2 = "IX"; 
    string s3 = "LVIII"; 
    string s4 = "MCMXCIV"; 

    cout << romanToInt(s1) << endl;
    cout << romanToInt(s2) << endl;
    cout << romanToInt(s3) << endl;
    cout << romanToInt(s4) << endl;
}