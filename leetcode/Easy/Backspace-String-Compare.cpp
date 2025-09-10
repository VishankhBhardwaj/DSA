class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st;
        stack<char>st2;
        int i=0;
        while(i<s.size()){
            if(s[i]!='#') st.push(s[i]);
            else if(!st.empty()){
                st.pop();
            }
            i++;
        }
        i=0;
        while(i<t.size()){
            if(t[i]!='#') st2.push(t[i]);
            else if(!st2.empty()) st2.pop();
            i++;
        }
        if(st.size()!=st2.size()) return false;
        else{
            while(!st.empty()){
                if(st.top()!=st2.top()) return false;
                st.pop();
                st2.pop();
            }
        }
        return true;
    }
};