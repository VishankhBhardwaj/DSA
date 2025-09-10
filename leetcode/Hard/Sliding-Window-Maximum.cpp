// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         vector<int> v;
//         for (int i = 0; i <= nums.size() - k; i++) {
//             int maxi = INT_MIN;
//             for (int j = i; j < i + k; j++) {
//                 maxi = max(maxi, nums[j]);
//             }
//             v.push_back(maxi);
//         }
//         return v;
//     }
// };

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()==i-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1){
                v.push_back(nums[dq.front()]);
            }
        }
        return v;
    }
};