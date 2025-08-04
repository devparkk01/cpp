/*
https://leetcode.com/problems/design-twitter/
*/


struct Tweet {
    int timestamp, tweet_id; 
};

class Compare{
    public:
    bool operator()(Tweet &a, Tweet &b) {
        return a.timestamp > b.timestamp; 
    }
};

class Twitter {
public:
    unordered_map<int, unordered_set<int>> followeeTable; 
    unordered_map<int, list<Tweet>> tweetTable; 
    int timestamp;

    Twitter() {
        timestamp = 0 ; 
    }
    
    void postTweet(int userId, int tweetId) {
        tweetTable[userId].push_front(Tweet{timestamp++, tweetId});
        if ( tweetTable[userId].size() > 10) {
            tweetTable[userId].pop_back(); // do not store more that 10 tweets for any user. 
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet, vector<Tweet>, Compare> minHeap ; // basically a max heap
        auto followees  = followeeTable[userId]; // list of followees
        vector<int> feed; feed.reserve(10); 

        // add user's tweets to the feed 
        auto selfTweets = tweetTable[userId];
        
        for(auto tweet : selfTweets){
            if (minHeap.size() < 10) {
                minHeap.push(tweet);
            } else {
                if ( tweet.timestamp > minHeap.top().timestamp) {
                    minHeap.pop(); 
                    minHeap.push(tweet);
                }
            }
        }
        // add all the followees tweets to the feed
        for(auto followee: followees) {
            auto followeeTweets = tweetTable[followee];
            for(auto tweet : followeeTweets ) {
                if (minHeap.size() < 10) {
                    minHeap.push(tweet);
                } else {
                    if ( tweet.timestamp > minHeap.top().timestamp) {
                        minHeap.pop(); 
                        minHeap.push(tweet);
                    }
                }
            }
        }

        int i = 0 ; 
        while(i < 10 && minHeap.size() > 0 ) {
            feed.push_back(minHeap.top().tweet_id);
            minHeap.pop();
            i++;
        }


        reverse(feed.begin(), feed.end()); 
        return feed;
        
    }
    
    void follow(int followerId, int followeeId) {
        followeeTable[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followeeTable[followerId].erase(followeeId);
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