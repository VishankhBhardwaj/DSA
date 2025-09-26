class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(auto num:operations){
            if(num == "C") st.pop();
            else if(num == "D"){
                st.push(2*st.top());
            }else if(num == "+"){
                int a=st.top(); st.pop();
                int b=st.top();
                st.push(a); 
                st.push(a+b);
            }else{
                st.push(stoi(num));
            }
        }
        if(st.empty()) return 0;
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};