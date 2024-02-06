#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 2,6

// Notes:
// The path starts with a single slash '/'.
// Any two directories are separated by a single slash '/'.
// The path does not end with a trailing '/'.
// The path only contains the directories on the path from the root directory to the target file or directory (i.e., no period '.' or double period '..')

// Example 1:
// Input: path = "/home/"
// Output: "/home"
// Explanation: Note that there is no trailing slash after the last directory name.

// Example 2:
// Input: path = "/../"
// Output: "/"
// Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.

// Example 3:
// Input: path = "/home//foo/"
// Output: "/home/foo"
// Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.

// use chatgpt to get a function to split a string
// e.g. // /a/./b/../../c/ => [a, b, ., .., .., c]
vector<string> split(string &s, char delim) {
    vector<string> elems;
    stringstream ss(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        if (!item.empty()) {
            elems.push_back(item);
        }
    }
    return elems;
}

string simplifyPath(string path)
{
    stack<string> stack;
    vector<string> tokens = split(path, '/');

    for(int i = 0; i < tokens.size(); i++)
    {
        // 当前元素为路径入栈 (不为操作符‘.’和 ‘..’), 如果是‘.’则跳过; // If the current element is a path (not the operators '.' and '..'), push it to the stack. Skip if it's '.'
        if(tokens[i] != "." && tokens[i] != "..")
        {
            stack.push(tokens[i]);
        }
        // 如果是‘..’则返回上级目录既弹出栈顶元素; If the element is '..', move up to the parent directory, which means popping the top element of the stack
        else if(tokens[i] == ".." && !stack.empty())
        {
            stack.pop();
        }
    }

    if(stack.empty()) return "/";

    string result = "";
    while(!stack.empty())
    {
        result = "/" + stack.top() + result; // ! 反向累加; Accumulate the path in reverse order
        stack.pop();
    }

    return result;
}

int main()
{
    string path1 = "/home/";
    string path2 = "/../";
    string path3 = "/home//foo/";
    cout << simplifyPath(path1) << endl;
    cout << simplifyPath(path2) << endl;
    cout << simplifyPath(path3) << endl;
}