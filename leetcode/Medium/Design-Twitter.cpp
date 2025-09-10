class Twitter {
public:
    int timeStamps;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    Twitter() {  timeStamps = 0; }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamps++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        following[userId].insert(userId);
        for(int followeeId:following[userId]){
            for(auto&[time,id]:tweets[followeeId]){
                pq.push({time,id});
            }
        }
        vector<int>ans;
        int count=0;
        while(!pq.empty() && count<10){
            ans.push_back(pq.top().second);
            pq.pop();
            count++;
        }
        return ans;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */