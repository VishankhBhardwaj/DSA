class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size(); i=i+2){
            swap(nums[i],nums[i+1]);
        }
        return nums;
        //Another Approach
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for(int num:nums){
        //     pq.push(num);
        // }
        // vector<int> arr;
        // while(!pq.empty()){
        //     int alice=pq.top();
        //     pq.pop();
        //     int bob=pq.top();
        //     pq.pop();
        //     arr.push_back(bob);
        //     arr.push_back(alice);
        // }
        // return arr;
    }
};