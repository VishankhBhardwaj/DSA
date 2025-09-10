class Solution {
public:
static bool comparator(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comparator);
        int removeCount=0;
        int end=INT_MIN;
        for(int i=0;i<n;i++){
            if(intervals[i][0]<end){
                removeCount++;
            }else{
                end=intervals[i][1];
            }
        }
        return removeCount;
    }
};