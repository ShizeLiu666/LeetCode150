#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Example 1:

// Input: strs = ["flower","flow","flight"]
// Output: "fl"
// Example 2:

// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

int minStringLength(const std::vector<std::string>& strs) {
    int minLength = std::numeric_limits<int>::max();

    for (const auto& str : strs) {
        if (str.length() < minLength) {
            minLength = str.length();
        }
    }

    return minLength;
}


string longestCommonPrefix(vector<string>& strs)
{
    string result = "";
    int min_len = minStringLength(strs);
    int j = 0;
    for(int i = 0; i < min_len; i++)
    {
        for(j = 0; j < strs.size() - 1; j++)
        {
            if(strs[j][i] != strs[j + 1][i])
            {
                return result;
            }
        }
        result += strs[j][i];
    }
    return result;
}

int main()
{
    vector<string> strs1 = {"flower", "flow", "flight"};
    vector<string> strs2 = {"dog", "racecar", "car"};
    vector<string> strs3 = {"a", "ab"};
    cout << longestCommonPrefix(strs1) << endl;
    cout << longestCommonPrefix(strs2) << endl;
    cout << longestCommonPrefix(strs3) << endl;
}