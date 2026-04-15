class Twitter {
public:
    map<int, set<int>> following;
    priority_queue<pair<int, pair<int, int>>> tweets;
    map<int, int> tweetCounter;
    int maxCount = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        this->tweets.push(make_pair(maxCount++, make_pair(tweetId, userId)));
    }
    
    vector<int> getNewsFeed(int userId) {
        set<int> users;
        if (this->following.find(userId) != this->following.end())
            users = this->following[userId];
        users.insert(userId);
        priority_queue<pair<int, pair<int, int>>> popped = this->tweets;
        vector<int> res;
        int k = 10;
        while(k && !popped.empty()) {
            pair<int, int> tweet = popped.top().second;
            popped.pop();
            if (users.count(tweet.second) > 0) {
                res.push_back(tweet.first);
                k--;
            }
        }
        // sort(res.begin(), res.end());
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        if (this->following.find(followerId) != this->following.end()) {
            this->following[followerId].insert(followeeId);
        } else {
            set<int> fol;
            fol.insert(followeeId);
            this->following[followerId] = fol;
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        this->following[followerId].erase(followeeId);
    }
};
