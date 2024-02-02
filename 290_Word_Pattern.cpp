#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

bool wordPattern(string pattern, string s)
{
    vector<string> string_vector;
    string temp = "";
    s += " ";

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != ' ')
        {
            temp += s[i];
        }
        else
        {
            string_vector.push_back(temp);
            temp = "";
        }
    }

    if (pattern.size() != string_vector.size())
    {
        return false;
    }

    unordered_map<char, string> map1;
    for(int i = 0; i < pattern.size(); i++)
    {
        char key = pattern[i];
        // find the string corresponding to the key
        if(map1.find(key) != map1.end() && map1[key] != string_vector[i])
        {
            return false;
        }
        else
        {
            map1[key] = string_vector[i];
        }
    }

    unordered_map<string, char> map2;
    for(int i = 0; i < string_vector.size(); i++)
    {
        string key = string_vector[i];
        if(map2.find(key) != map2.end() && map2[key] != pattern[i])
        {
            return false;
        }
        else
        {
            map2[key] = pattern[i];
        }
    }

    return true;        
}

int main()
{
    string pattern1 = "abba", s1 = "dog cat cat dog";
    cout << wordPattern(pattern1, s1) << endl;

    string pattern2 = "abba", s2 = "dog cat cat fish";
    cout << wordPattern(pattern2, s2) << endl;

    string pattern3 = "aaaa", s3 = "dog cat cat dog";
    cout << wordPattern(pattern3, s3) << endl;

    string pattern4 = "abba", s4 = "dog dog dog dog";
    cout << wordPattern(pattern4, s4) << endl;

    string pattern5 = "jquery", s5 = "jquery";
    cout << wordPattern(pattern5, s5) << endl;
}