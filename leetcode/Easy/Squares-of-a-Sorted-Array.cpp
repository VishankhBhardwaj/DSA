#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> bubbleSort(vector<int> arr) {
            int n = arr.size();
            for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < n - i - 1; ++j) {
                    if (arr[j] > arr[j + 1]) {
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
            return arr;
        }
        vector<int> sortedSquares(vector<int>& nums) {
            int j=0;
            for(auto i:nums){
                nums[j++]=i*i;
            }
            return  bubbleSort(nums);
        }
    };