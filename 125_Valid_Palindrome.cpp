#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

// Input: s = "aabb"

bool isPalindrome(string s)
{
    if(s.length() == 1) return true;

    // change all characters to lower case and keep all valid characters
    string new_string;
    for (char ch: s)
    {
        if (isalnum(ch))
        {
            new_string += tolower(ch);
        }
    }

    int p1 = 0, p2 = new_string.length() - 1;
    // cout << new_string[p1] << " " << new_string[p2] << endl;
    while(p1 < p2)
    {
        if(new_string[p1++] != new_string[p2--])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";
    string s4 = ",.";
    cout << isPalindrome(s1) << endl;
    cout << isPalindrome(s2) << endl;
}
