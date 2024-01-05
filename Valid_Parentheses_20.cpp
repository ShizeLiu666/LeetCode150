#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string str)
{
    stack<char> stack;
    for(int i = 0; i < str.length(); i++)
    {
        char cha = str[i];
        if(cha == '(' || cha == '['  || cha == '{' )
        {
            stack.push(cha);
        }
        else
        {
            if(stack.empty())
            {
                return false;
            }

            char top = stack.top();
            stack.pop();

            if((cha == ')' && top != '(') || (cha == ']' && top != '[') || (cha == '}' && top != '{'))
            {
                return false;
            }
        }
    }

    return stack.empty();
}

int main()
{
    cout << isValid("(]") << endl;
    cout << isValid("[]") << endl;
    cout << isValid("]") << endl;
}