#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Example 1:
// Input: s = "egg", t = "add"
// Output: true

// Example 2:
// Input: s = "foo", t = "bar"
// Output: false

// Example 3:
// Input: s = "paper", t = "title"
// Output: true

bool isIsomorphic(string s, string t)
{
    // map1 s => t
    unordered_map<char, char> map1;
    for(int i = 0; i < s.length(); i++)
    {
        char element = s[i];
        // element already in map
        if(map1.count(element) > 0)
        {
            if(map1[element] != t[i])
            {
                return false;
            }
        }
        else
        {
            map1[element] = t[i];
        }
    }

    // map2 t => s (反过来再查一次)
    unordered_map<char, char> map2;
    for(int i = 0; i < t.length(); i++)
    {
        char element = t[i];
        // element already in map
        if(map2.count(element) > 0)
        {
            if(map2[element] != s[i])
            {
                return false;
            }
        }
        else
        {
            map2[element] = s[i];
        }
    }
    return true;
}

int main()
{
    string s1 = "egg", t1 = "add";
    cout << isIsomorphic(s1, t1) << endl;
    string s2 = "foo", t2 = "bar";
    cout << isIsomorphic(s2, t2) << endl;
    string s3 = "paper", t3 = "title";
    cout << isIsomorphic(s3, t3) << endl;
    string s4 = "badc", t4 = "baba";
    cout << isIsomorphic(s4, t4) << endl;
}