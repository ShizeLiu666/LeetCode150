#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

//! 2/2 太简单了，没啥好说的一题，不管怎么异位，字母出现的次数肯定是一样的
//! 2/2 It's too easy, it's not much of a question, the letters must appear the same number of times, no matter how anomalous they are.

bool isAnagram(string s, string t)
{
    unordered_map<char, int> map;
    if(s.length() != t.length()) return false;
    for(int i = 0; i < s.length(); i++)
    {
        map[s[i]]++;
    }
    for(int i = 0; i < t.length(); i++)
    {
        map[t[i]]--;
        if(map[t[i]] < 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s1 = "anagram", t1 = "nagaram";
    string s2 = "rat", t2 = "car";
    // string s3 = "anagram", t3 = "nagaram";

    cout << isAnagram(s1, t1) << endl;
    cout << isAnagram(s2, t2) << endl;
    // cout << isAnagram(s3, t3) << endl;
}