// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
//     public:
//         vector<int> searchRange(vector<int>& nums, int target) {
//             int occ=0;
//             vector<int> ans(2, -1);
//             for(int i=0;i<nums.size();i++){
//                 if(nums[i]==target && occ==0){
//                     ans[0]=i;
//                     occ++;
//                 }
//                 else if(nums[i]==target && occ==1){
//                     ans[1]=i;
//                 }
//             }
//             if(ans[1]==-1){
//                 ans[1]=ans[0];
//             }
//             return ans;
//         }
//     };
class Solution {
public:
int findFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                high = mid - 1; // go left to find earlier occurrence
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                ans = mid;
                low = mid + 1; // go right to find later occurrence
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};