class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>lesser,greater,equal;
        for(auto num:nums){
            if(num<pivot) lesser.push_back(num);
            else if(num>pivot) greater.push_back(num);
            else equal.push_back(num);
        }
        vector<int> ans;
        ans.reserve(nums.size());
        ans.insert(ans.end(), lesser.begin(), lesser.end());
        ans.insert(ans.end(), equal.begin(), equal.end());
        ans.insert(ans.end(), greater.begin(), greater.end());
        return ans;
    }
};