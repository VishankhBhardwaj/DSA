#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; ++i) {
            for (int j = 0; j < n - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
    
        int maximumProduct(vector<int>& nums) {
            bubbleSort(nums);
            int pro=1;
            int pro2=1;
            int n=nums.size()-1;
            pro*=nums[n]*nums[n-1]*nums[n-2];
            pro2*=nums[n]*nums[0]*nums[1];
            return pro2>pro?pro2:pro;
        }
    };