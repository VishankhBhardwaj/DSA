class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        long long sum=0;
        int max=INT_MIN;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>max){
                max=sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return max;
    }
};