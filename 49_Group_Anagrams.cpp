#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Example 1:
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

// Example 2:
// Input: strs = [""]
// Output: [[""]]

// Example 3:
// Input: strs = ["a"]
// Output: [["a"]]

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    // key -> string from sts
    // value -> key -> each character from string
    //              -> character counter 
    unordered_map<string, unordered_map<char, int>> big_map;
    vector<string> anagrams; // 异位词
    vector<vector<string>> result;

    // 先把大表给建出来 build the whole map firstly
    for(int i = 0; i < strs.size(); i++)
    {
        for(int j = 0; j < strs[i].length(); j++)
        {
            big_map[strs[i]][i]++;
        }
    }
    cout << big_map.size() << endl;
    // start to check anagram
    // while(!strs.empty())
    // {
    //     string str = strs[0];
    //     anagrams.push_back(strs[i]);
    //     for(int i = 1; i < strs.size(); i++)
    //     {
    //         bool check = true;
    //         for(int j = 0; j < strs[i].length(); j++)
    //         {
    //             if(big_map[str][j] != big_map[strs[i]][j])
    //             {
    //                check = false; 
    //             }
    //         }
    //         if(check)
    //         {
    //             anagrams.push_back(strs[i]);
    //         }
    //     }
    //     strs = strs.remove(strs.begin(), strs.end(), str);
    // }
    return result;
}

int main()
{
    vector<string>strs1 = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>>output1 = groupAnagrams(strs1);
    vector<string>strs2 = {""};
    vector<vector<string>>output2 = groupAnagrams(strs2);
    vector<string>strs3 = {"a"};
    vector<vector<string>>output2 = groupAnagrams(strs3);
}