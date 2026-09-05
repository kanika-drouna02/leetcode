class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto &t:times) adj[t[0]].push_back({t[1],t[2]});


        vector<int>dis(n+1, INT_MAX);
        dis[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>>pq;
        pq.push({0,k});

        while(!pq.empty()){
            auto [d,u] = pq.top();
            pq.pop();

            if(d>dis[u]) continue;

            for(auto& [v,w]:adj[u]){
                if(d+w<dis[v]){
                    dis[v]=d+w;
                    pq.push({dis[v],v});
                }
            }
        }
        int mx=0;

        for(int i=1;i<=n;i++){
            if(dis[i]==INT_MAX) return -1;
            mx=max(mx,dis[i]);
        }
        return mx;

    }
};