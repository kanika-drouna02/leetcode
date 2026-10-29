class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();

        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));

        priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> pq;

        dis[0][0]=grid[0][0];

        pq.push({grid[0][0],{0,0}});

        int dr[4]={1,-1,0,0};
        int dc[4]={0,0,1,-1};


        while(!pq.empty()){
            int d=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            if(r==n-1 && c==n-1) return d;
            if(d> dis[r][c]) continue;

            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr<0 || nc<0 || nr>=n || nc>=n) continue;
                int nd=max(d,grid[nr][nc]);
                if(nd<dis[nr][nc]){
                    dis[nr][nc]=nd;
                    pq.push({nd,{nr,nc}});
                }
            }
            
        }
        return -1;
    }
};