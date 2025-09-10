class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int>timeline(1001,0);
        for(auto trip:trips){
            timeline[trip[1]]+=trip[0];
            timeline[trip[2]]-=trip[0];
        }
        int passengers = 0;
        for(int i=0;i<1000;i++){
            passengers+=timeline[i];
            if(passengers>capacity) return false;
        }
        return true;
    }
};