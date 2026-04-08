class Twitter {
    int count;
    unordered_map<int, vector<vector<int>>> tweetmap;
    unordered_map<int,set<int>> followmap;
public:
    Twitter() {
        count = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetmap[userId].push_back({count++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0]<b[0]; // higher value has higher priority
        };
        priority_queue<vector<int>,vector<vector<int>>, decltype(compare)> maxh(compare);

        followmap[userId].insert(userId);
        for( int followee : followmap[userId]) {
            if ( tweetmap.count(followee)) {
                const vector<vector<int>>& tweets = tweetmap[followee];
                int index = tweets.size()-1;
                maxh.push({tweets[index][0],tweets[index][1], followee,index});
            }
        }

        while(!maxh.empty() && res.size() < 10) {
            vector<int> curr = maxh.top();
            maxh.pop();
            res.push_back(curr[1]);
            int index = curr[3];
            if ( index>0) {
                const vector<int> & tweet = tweetmap[curr[2]][index-1];
                maxh.push({tweet[0], tweet[1], curr[2], index-1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followmap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followmap[followerId].erase(followeeId);
    }
};
