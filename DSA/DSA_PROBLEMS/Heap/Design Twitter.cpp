/*
Design Twitter

Intutition : Merge K sorted lists from greatest to smallest

O(10logK + O(K))

*/

typedef vector<int> vec;
struct compare
{
    bool operator()(const vec& a, const vec& b)
    {
        return a[0]<b[0];
    }
};
class Twitter {
public:
    unordered_map<int,set<int>> followeesMap;
    unordered_map<int,vector<pair<int,int>>> tweetsMap;
    int time;
    Twitter() {
        time=0; //allTweets = { followee 1 => {{1,12},{2,13}}, followee 2 => {{3,90},{4,098}}   };
    }
    
    void recentTenTweets(vector<int> &res,vector<vector<pair<int,int>>>& allTweets)
    {
        int k = allTweets.size();
          priority_queue<vec, vector<vec>, compare> heap;
        
        for(int i=0;i<k;++i)
        {
            int index = allTweets[i].size()-1;
            if(index>=0)
                heap.push({allTweets[i][index].first,allTweets[i][index].second,i,index});
         }
       while(!heap.empty() and res.size()<10)
        {
            vec temp = heap.top();
            heap.pop();
            int time = temp[0];
            int tweet_id = temp[1];
            int vec_idx = temp[2];
            int curr_idx = temp[3];
            int next_idx = curr_idx-1;
            res.push_back(tweet_id);
            if(next_idx>=0)
                {
                     heap.push({allTweets[vec_idx][next_idx].first,allTweets[vec_idx][next_idx].second,vec_idx,next_idx});
                }
        }
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweetsMap[userId].push_back({time,tweetId});
        time+=1;
    }
    
    vector<int> getNewsFeed(int userId) {
       vector<int> res;
        vector<vector<pair<int,int>>> allTweets;
       for(auto& followee: followeesMap[userId])
       {
           allTweets.push_back(tweetsMap[followee]);
       }
       allTweets.push_back(tweetsMap[userId]);
       recentTenTweets(res, allTweets);
       return res;
    }
    
    void follow(int followerId, int followeeId) {
        followeesMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followeesMap[followerId].count(followeeId))
            followeesMap[followerId].erase(followeeId);
    }
    
    
    
};

