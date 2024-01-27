#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Example 1:

// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.
// Example 2:

// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.
// Example 3:

// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.

int lengthOfLastWord(string s)
{
    int len = s.size();
    int counter = 0;

    while(s[len - 1] == ' ')
    {
        len--;
    }

    while(len > 0 && s[len - 1] != ' ')
    {
        len--;
        counter++;
    }

    return counter;
}

int main()
{
    string s1 = "Hello World";
    string s2 = "   fly me   to   the moon  ";
    string s3 = "luffy is still joyboy";
    string s4 = "a ";
    cout << lengthOfLastWord(s1) << endl;
    cout << lengthOfLastWord(s2) << endl;
    cout << lengthOfLastWord(s3) << endl;
    cout << lengthOfLastWord(s4) << endl;
}