#include <string>
#include <stack>
#include<iostream>
using namespace std;
class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        for(int i=0;i<s.length();i++){
            char ch= s[i];

            //if open bracket then push
            //if close then check and pop
            if(ch=='(' || ch=='{' ||ch=='['){
                st.push(ch);
            }
            else{
                if(!st.empty()){
                    char top=st.top();
                    if( (ch==')' &&top=='(' )||
                     (ch==']' &&top=='[' )||
                     ( ch=='}' &&top=='{' )){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
                    
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};