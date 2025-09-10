// class Solution {
//     public:
//         void sortColors(vector<int>& nums) {
//             int n = nums.size();
//             for (int i = 0; i < n - 1; i++) {
//                 bool swapped = false;
//                 for (int j = 0; j < n - i - 1; j++) {
//                     if (nums[j] > nums[j + 1]) {
//                         swap(nums[j], nums[j + 1]);
//                         swapped = true;
//                     }
//                 }
//                 // If no elements were swapped, the array is already sorted
//                 if (!swapped) break;
            
//             }
//         }
//     };


//BETTER APPROACH

class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int low=0;int mid=0;int high=nums.size()-1;
            while(mid<=high){
                if(nums[mid]==0){
                    swap(nums[low],nums[mid]);
                    low++;
                    mid++;
                }
                else if(nums[mid]==1){
                    mid++;
                }
                else{
                    swap(nums[mid],nums[high]);
                    high--;
                }
            }
        }
    };