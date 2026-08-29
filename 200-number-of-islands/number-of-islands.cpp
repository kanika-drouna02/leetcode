class Solution {

private:
void bfs(int r, int c, vector<vector<int>>&vis, vector<vector<char>>&grid){
    int n=grid.size(), m=grid[0].size();
    vis[r][c]=1;
    queue<pair<int,int>>q;
    q.push({r,c});

    int dr[]={-1,0,1,0};
    int dc[]={0,1,0,-1};
    while(!q.empty()){
        int row=q.front().first;
        int col=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]=='1'){
                q.push({nr,nc});
                vis[nr][nc]=1;
            }
        }
    }
}


public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size(), cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};