class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int k) {
        vector<vector<int>>adj(n,vector<int>(n,1e4));
        for(auto &t: edges){
            adj[t[0]][t[1]]=t[2];
            adj[t[1]][t[0]]=t[2];
        }
        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }
        for(int node=0;node<n;node++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(adj[i][j] > adj[i][node]+adj[node][j]) adj[i][j]=adj[i][node]+adj[node][j];
                
        int b=INT_MAX, ans=-1;
        for(int i=0;i<n;i++){
            int a=0;
            for(int j=0;j<n;j++){
                if(adj[i][j]<=k) a++;
            }
            if(a<=b){
                b=a;
                ans=i;
            }
        }

        return ans;

    }
};