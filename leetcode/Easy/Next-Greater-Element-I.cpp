class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>map;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--){
            int num=nums2[i];
            while(!st.empty() && st.top()<=num){
                st.pop();
            }
            map[num]=st.empty()?-1:st.top();
            st.push(num);
        }
        vector<int>res;
        for(auto i:nums1){
            res.push_back(map[i]);
        }
        return res;
    }
};