#include <bits/stdc++.h>
void solve(stack<int>&s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int a=s.top();
    s.pop();
    solve(s,x);
    s.push(a);
} 
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack,x);
    return myStack;
}
