class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};


        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int h=pq.top().first;
            pq.pop();

            if(r==n-1 && c==m-1) return h;

            if(h>dis[r][c]) continue;

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m  ){
                    int dif=abs(heights[r][c] - heights[nr][nc]);
                    int f=max(dif,h);
                    if(f<dis[nr][nc]){
                        dis[nr][nc]=f;
                        pq.push({f,{nr,nc}});
                    }
                }
            }
        }
        return 0;
    }
};