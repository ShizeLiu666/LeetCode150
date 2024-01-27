#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

string reverseWords(string s)
{
    // remove all invalid spaces
    int p1 = 0, p2 = s.length() - 1; // p1 to first character, p2 to last character
    while(s[p1] == ' ' || s[p2] == ' ')
    {
        if(s[p1] == ' ')
        {
            p1++;
        }
        else
        {
            p2--;
        }
    }
    
    // intialize a new string
    vector<string> result_vec;
    int p3 = p1;
    while(p1 <= p2)
    {
        string temp = "";
        while(s[p1] != ' ' && p1 <= p2)
        {
            temp += s[p1++];
        }
        // cout << temp << endl;
        result_vec.push_back(temp);

        while(s[p1] == ' ' && p1 <= p2)
        {
            p1++;
        }      
        p3 = p1;
    }

    string result = "";

    for(int i = result_vec.size() - 1; i >= 0; i--)
    {
        // cout << result_vec[i] << " " << result_vec[i].length() << endl;
        result += (i == 0) ? result_vec[i]: result_vec[i] + " ";
    }
    cout << result.length() << endl;
    return result;
}

int main()
{
   string s1 = "the sky is blue";
   string s2 = "  hello world  ";
   string s3 = "a good   example";
   string s4 = "   fffff ff gg ee";
   cout << reverseWords(s1) << endl;
   cout << reverseWords(s2) << endl;
   cout << reverseWords(s3) << endl;
   cout << reverseWords(s4) << endl;
}