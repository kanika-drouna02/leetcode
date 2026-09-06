class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        int n=variables.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int a=variables[i][0], b=variables[i][1], c=variables[i][2], m=variables[i][3];
            int n1=1;
            while(b--) n1=(n1*a)%10;
            n1=n1%10;

            int n2=1;
            while(c--) n2=(n2*n1)%m;
            n2=n2%m;

            if(n2==target) ans.push_back(i);
        }
        return ans;
    }
};