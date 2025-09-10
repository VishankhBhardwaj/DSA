#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> getConcatenation(vector<int>& nums) {
            vector<int>ans(nums.size()*2);
            int n=nums.size()-1;
            for(int i=0;i<nums.size();i++){
                 ans[i]=nums[i];
                 ans[++n]=nums[i];
            }
            return ans;
        }
    };