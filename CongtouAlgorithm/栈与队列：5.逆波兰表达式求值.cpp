#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result;
        stack<int> numStack;
        for (auto item : tokens)
        {
	        if (item == "+" || item == "-" || item == "*" || item == "/")
	        {
                int num1 = numStack.top();
                numStack.pop();
                int num2 = numStack.top();
                numStack.pop();
                if (item == "+")
                {
                    numStack.push(num2 + num1);
                }
                else if (item == "-")
                {
                    numStack.push(num2 - num1);
                }
                else if (item == "*")
                {
                    numStack.push(num2 * num1);
                }
                else
                {
                    numStack.push(num2 / num1);
                }
	        }
            else
            {
                numStack.push(stoi(item));
            }
        }
        return numStack.top();
    }
};
