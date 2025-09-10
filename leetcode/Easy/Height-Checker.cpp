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
        int heightChecker(vector<int>& heights) {
            vector<int>ans=bubbleSort(heights);
            int k=0;
            for(int i=0;i<heights.size();i++){
                if(heights[i]!=ans[i]){
                    k++;
                }
            }
            return k;
        }
    };