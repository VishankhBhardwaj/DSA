#include <stack>
#include <limits.h>

class SpecialStack {
public:
    stack<int> s;
    int mini;

    SpecialStack() {
        mini = INT_MAX; // Initialize mini to maximum possible value
    }

    void push(int data) {
        if (s.empty()) {
            s.push(data);
            mini = data;
        } else {
            if (data < mini) {
                s.push(2 * data - mini);
                mini = data;
            } else {
                s.push(data);
            }
        }
    }

    int pop() {
        if (s.empty()) {
            return -1; // Stack is empty
        }

        int curr = s.top();
        s.pop();

        if (curr < mini) { 
            int prevMin = mini;  
            mini = 2 * mini - curr; // Restore previous min
            return prevMin;
        } else {
            return curr;
        }
    }

    int top() {
        if (s.empty()) {
            return -1;
        }

        int curr = s.top();
        return (curr < mini) ? mini : curr;
    }

    int getMin() {
        return s.empty() ? -1 : mini;
    }
};
