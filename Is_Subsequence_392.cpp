#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Example 1:
// Input: s = "abc", t = "ahbgdc"
// Output: true

// Example 2:
// Input: s = "axc", t = "ahbgdc"
// Output: false

bool isSubsequence(string s, string t)
{
    int p1 = 0;
    for(int i = 0; i < t.length(); i++)
    {
        if(t[i] == s[p1])
        {
            p1++;
        }
    }
    return p1 == s.length();
}

int main()
{
    string test11 = "abc";
    string test12 = "ahbgdc";
    string test21 = "axc";
    string test22 = "ahbgdc";
    string test31 = "c";
    string test32 = "g";
    string test41 = "abc";
    string test42 = "";
    string test51 = "abc";
    string test52 = "acb";
    string test61 = "ab";
    string test62 = "baab";
    cout << isSubsequence(test11, test12) << endl;
    cout << isSubsequence(test21, test22) << endl;
    cout << isSubsequence(test31, test32) << endl;
    cout << isSubsequence(test41, test42) << endl;
    cout << isSubsequence(test51, test52) << endl;
    cout << isSubsequence(test61, test62) << endl;
}