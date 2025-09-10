class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
    }
};
// class Solution {
//     public:
//         void reverseString(vector<char>& s) {
//             stack<char>st;
//             for(int i=0;i<s.size();i++){
//                 st.push(s[i]);
//             }
//             int i=0;
//             while(!st.empty()){
//                 char val=st.top();
//                 st.pop();
//                 s[i++]=val;
//             }
//         }
//     };