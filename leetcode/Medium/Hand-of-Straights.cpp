class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        map<int,int>freq;
        for(auto card:hand){
            freq[card]++;
        }
        for(auto&[num,fre]:freq){
            minHeap.push(num);
        }
        while(!minHeap.empty()){
            int first = minHeap.top();
            if(freq[first]==0){
                minHeap.pop();
                continue;
            }
            int count = freq[first];
            for(int i=0;i<groupSize;i++){
                int curr = first+i;
                if(freq[curr]<count) return false;
                freq[curr]-=count;
            }
            minHeap.pop();
        }
        return true;
    }
};