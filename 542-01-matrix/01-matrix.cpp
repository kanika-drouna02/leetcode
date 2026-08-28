class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=0;
                }
            }
        }

        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==-1 && mat[nr][nc]==1){
                    q.push({nr,nc});
                    vis[nr][nc]=vis[r][c]+1;
                }
            }
        }
        return vis;
    }
};