#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int binarySearch(vector<int>&nums,int target,int s,int e){
                int mid=(s+e)/2;
                if(s>e) return s;
                    if(nums[mid]==target){
                        return mid;
                    }
                    if(nums[mid]>target){
                        return binarySearch(nums,target,s,mid-1);
                    }
                    else{
                        return binarySearch(nums,target,mid+1,e);
                    }
                return mid;
            }
        int searchInsert(vector<int>& nums, int target) {
             return binarySearch(nums,target,0,nums.size()-1);
        }
    };