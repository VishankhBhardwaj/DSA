
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            vector<int>ans(1,INT_MIN);
            for(int i=0;i<nums.size();i++){
                if(ans.back()==nums[i]){
                    continue;
                }
                else{
                    ans.push_back(nums[i]);
                }
            }
            for(int i=1;i<ans.size();i++){
                nums[i-1]=ans[i];
            }
            return ans.size()-1;
        }
    };