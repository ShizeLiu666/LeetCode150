#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Example 1:
// Input: ransomNote = "a", magazine = "b"
// Output: false

// Example 2:
// Input: ransomNote = "aa", magazine = "ab"
// Output: false

// Example 3:
// Input: ransomNote = "aa", magazine = "aab"
// Output: true

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> map;
    for(int i = 0; i < magazine.length(); i++)
    {
        map[magazine[i]] += 1;
    }

    for(int i = 0; i < ransomNote.length(); i++)
    {
        if(map[ransomNote[i]] == 0)
        {
            return false;
        }
        else
        {
            map[ransomNote[i]]--;
        }
    }
    return true;            
}

int main()
{
    string ransomNote1 = "a";
    string magazine1 = "b";
    cout << canConstruct(ransomNote1, magazine1) << endl;

    string ransomNote2 = "aa";
    string magazine2 = "ab";
    cout << canConstruct(ransomNote2, magazine2) << endl;

    string ransomNote3 = "aa";
    string magazine3 = "aab";
    cout << canConstruct(ransomNote3, magazine3) << endl;
}