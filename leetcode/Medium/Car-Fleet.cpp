class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        map<int,double>mpp;
        int n = position.size();
        for(int i=0;i<n;i++){
            double time=(double)(target-position[i])/speed[i];
            mpp[position[i]]=time;
        }
        double prevTime=0.0;
        int fleets=0;
        for(auto it=mpp.rbegin();it!=mpp.rend();it++){
            double time=it->second;
            if(time>prevTime){
                fleets++;
                prevTime=time;
            }
        }
        return fleets;
    }
};