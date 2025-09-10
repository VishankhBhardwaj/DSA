#include <bits/stdc++.h> 
void insertSort(stack<int>&stack,int element){
	if(stack.empty()||(!stack.empty()&&stack.top()<element)){
		stack.push(element);
		return;
	}
	int num=stack.top();
	stack.pop();
	insertSort(stack,element);
	stack.push(num);
}
void sortStack(stack<int> &stack)
{
	// Write your code here
	if(stack.empty()){
		return ;
	}
	int num=stack.top();
	stack.pop();
	sortStack(stack);
	insertSort(stack,num);
}