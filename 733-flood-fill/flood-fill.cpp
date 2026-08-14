class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        queue<pair<pair<int,int>,int>>q;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        if(image[sr][sc]==color) return image;

        int cc=image[sr][sc];

        q.push({{sr,sc},cc});
        image[sr][sc]=color;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            int r= q.front().first.first;
            int c= q.front().first.second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m  && image[nr][nc]==cc){
                    q.push({{nr,nc},cc});
                    image[nr][nc]=color;
                }
            }
        }
        return image;
        
    }
};