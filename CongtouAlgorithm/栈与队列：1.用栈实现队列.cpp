#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> in_stack;
    stack<int> out_stack;
    MyQueue() {

    }

    void push(int x) {
        in_stack.push(x);
    }

    int pop() {
        in2out();
        int result = out_stack.top();
        out_stack.pop();
        return result;
    }

    int peek() {
        in2out();
        return out_stack.top();
    }

    bool empty() {
        if (in_stack.empty() && out_stack.empty()) return true;
        return false;
    }

    void in2out()
    {
        if (out_stack.empty())
        {
            while (!in_stack.empty())
            {
                out_stack.push(in_stack.top());
                in_stack.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */