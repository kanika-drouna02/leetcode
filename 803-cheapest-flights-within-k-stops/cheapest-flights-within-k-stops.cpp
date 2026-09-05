class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int>dis(n+1,INT_MAX);
        dis[src]=0;

        for(int i=0;i<=k;i++){
            vector<int>temp=dis;

            for(auto &f: flights){
                int u=f[0], v=f[1], w=f[2];
                if(dis[u] != INT_MAX && dis[u]+w<temp[v]) temp[v]=dis[u]+w;
            }
            dis=temp;
        }

        return (dis[dst]== INT_MAX ? -1 : dis[dst]);
    }
};