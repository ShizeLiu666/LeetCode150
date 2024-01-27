#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.
// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.

// Method 1: Brute force
int strStr(string haystack, string needle)
{
    int haystack_len = haystack.length();
    int needle_len = needle.length();

    for(int i = 0; i < haystack_len - needle_len + 1; i++)
    {
        int p1 = i; // current element in haystack
        int p2 = 0; // pointer to each element of needle
        while(p2 < needle_len and haystack[p1] == needle[p2])
        {
            p2++;
            p1++;
        }
        if(p2 == needle_len) return i;
    }
    return -1;
}

// Method 2: KMP 
// vector<int> getPrefixTable(string needle)
// {
//     int len = needle.length();
//     vector<int> prefixTable(len);
    
//     int p1; // p1: 后缀末尾
//     int p2 = 0; // p2: 前缀末尾

//     for(p1 = 1; p1 < len; p1++)
//     {
//         // 前后缀不相同
//         while(needle[p1] != needle[p2] && p2 > 0)
//         {
//             p2 = prefixTable[p2 - 1];
//         }
//         // 前后缀相同
//         if(needle[p1] == needle[p2])
//         {
//             p2++;
//         }
//         //更新
//         prefixTable[p1] = p2;
//     }
    
//     return prefixTable;
// }

// int strStr(string haystack, string needle)
// {
//     vector<int> prefixTable = getPrefixTable(needle); // build prefix table

// }

int main()
{
    string haystack1 = "sadbutsad", needl1 = "sad";
    string haystack2 = "leetcode", needl2 = "leeto";
    string haystack3 = "aabaabaaf", needl3 = "aabaaf";

    cout << strStr(haystack1, needl1) << endl;
    cout << strStr(haystack2, needl2) << endl;
    cout << strStr(haystack3, needl3) << endl;
}