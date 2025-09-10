#include <bits/stdc++.h> 
class TwoStack {
    int *arr;
    int topA;
    int topB;
    int size;
public:
    // Initialize TwoStack.
    TwoStack(int s) {
        size = s;
        topA = -1;
        topB = s;
        arr = new int[s];
    }
    
    // Push in stack 1.
    void push1(int num) {
        if (topB-topA>1) {
            topA++;
            arr[topA] = num;
        } 
    }

    // Push in stack 2.
    void push2(int num) {
        if (topB-topA>1) {
            topB--;
            arr[topB] = num;
        } 
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if (topA == -1) {
            // Underflow condition
            return -1;
        } else {
            int num = arr[topA];
            topA--;
            return num;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if (topB == size) {
            // Underflow condition
            return -1;
        } else {
            int num = arr[topB];
            topB++;
            return num;
        }
    }
};
