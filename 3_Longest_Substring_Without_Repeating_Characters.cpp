#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

int lengthOfLongestSubstring(string s)
{
    if(s.size() == 0) return 0;
    
    unordered_set<char> queue; // build a queue
    int counter = 0, p1 = 0; // p1 = the left margin of the string
    for(int p2 = 0; p2 < s.size(); p2++)
    {
        // if current char is already in the queue
        // !保证当前p2指向元素的唯一性 ensure the uniqueness of the element currently pointed to by p2
        while(queue.find(s[p2]) != queue.end())
        {
            queue.erase(s[p1]); // remove the left element from queue
            p1++;
        }
        counter = max(counter, p2 - p1 + 1);
        queue.insert(s[p2]);
    }
    return counter;
    
}

int main()
{
    string s1 = "abcabcbb";
    cout << lengthOfLongestSubstring(s1) << endl;

    string s2 = "bbbbb";
    cout << lengthOfLongestSubstring(s2) << endl;

    string s3 = "pwwkew";
    cout << lengthOfLongestSubstring(s3) << endl;
}