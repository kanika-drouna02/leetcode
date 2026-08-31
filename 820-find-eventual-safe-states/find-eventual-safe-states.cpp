class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>adjRev[graph.size()];
        int n=graph.size();
        vector<int> in(n,0);
        for(int i=0;i<graph.size();i++){
            for(auto it:graph[i]){
                adjRev[it].push_back(i);
                in[i]++;
            }
        }
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<n;i++){
            if(in[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i:adjRev[node]){
                in[i]--;
                if(in[i]==0) q.push(i);
            }
        }

        sort(ans.begin(),ans.end());
        return ans;

    }
};