class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int i=0;
        int n=arr.size();
        while(i<arr.size()-1){
            if(arr[i]>arr[i+1]) break;
            i++;
        }
        if(i==arr.size()-1) return 0;
        int j=arr.size()-1;
        while(j>0){
            if(arr[j]<arr[j-1]) break;
            j--;
        }
        int res = min(n - i - 1, j);
        int l=0;
        while(l<=i && j<arr.size()){
            if(arr[l]<=arr[j]){
                res = min(res, j - l - 1);
                l++;
            } 
            else j++;
        }
        return res;
    }
};