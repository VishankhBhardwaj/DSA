class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        for(auto ch:s){
            if(!st.empty() && ch==']' && st.top()=='[') st.pop();
            else st.push(ch);
        }
        int n=st.size()/2;
        return (n+1)/2;
    }
};