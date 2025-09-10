
#include <bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void bubbleSort(vector<int>& arr) {
            int n = arr.size();
            for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < n - i - 1; ++j) {
                    if (arr[j] < arr[j + 1]) { // descending order
                        swap(arr[j], arr[j + 1]);
                    }
                }
            }
        }
    
        int thirdMax(vector<int>& nums) {
            bubbleSort(nums);
            int count = 1; // We already have the max at index 0
    
            for (int i = 1; i < nums.size(); ++i) {
                if (nums[i] != nums[i - 1]) {
                    count++;
                    if (count == 3) {
                        return nums[i];
                    }
                }
            }
    
            // If less than 3 distinct values, return the max
            return nums[0];
        }
    };
    