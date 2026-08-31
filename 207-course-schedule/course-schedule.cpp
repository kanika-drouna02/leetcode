class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        vector<int>in(numCourses);

        for (auto& pre : prerequisites) {
            int a = pre[0], b = pre[1];
            adj[b].push_back(a);
            in[a]++;
        }

        queue<int>q;
        vector<int>topo;

        for(int i=0;i<numCourses;i++){
            if(in[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);

            for(auto it:adj[node]){
                in[it]--;
                if(in[it]==0) q.push(it);
            }
        }
        if((int)topo.size()==numCourses) return true;
        return false;
    }
};