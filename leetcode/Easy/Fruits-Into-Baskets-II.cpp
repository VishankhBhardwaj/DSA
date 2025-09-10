class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int l=0;
        int r=0;
        int cnt=0;
        while(l<fruits.size()){
            if(r==baskets.size()){
                r=0;
                l++;
                cnt++;
            }
            else if(fruits[l]<=baskets[r]){
                baskets[r]=-1;
                l++;
                r=0;
            }
            else{
                r++;
            }
        }
        return cnt;
    }
};