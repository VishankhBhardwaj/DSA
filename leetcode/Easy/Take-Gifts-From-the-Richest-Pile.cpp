class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        priority_queue<long long> pq(gifts.begin(), gifts.end());
        while (k > 0) {
            long long top = pq.top();
            pq.pop();
            pq.push((long long)floor(sqrt(top)));
            k--;
        }
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};