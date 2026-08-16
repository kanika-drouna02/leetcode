class Solution {
public:

    int countSmall(vector<vector<int>>& nums, int val){
        int n=nums.size(), m=nums[0].size();
        int count=0;
        for(int i=0;i<n;i++)
        count += upper_bound(nums[i].begin(), nums[i].end(), val) - nums[i].begin();
        return count;
    }

    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n= matrix.size();
        int m=matrix[0].size();
        int l=matrix[0][0], r=matrix[n-1][m-1];
        int ans=-1;
        while(r>=l){
            int mid= l+(r-l)/2;
            int count = countSmall(matrix,mid);
            if(count<k) l=mid+1;
            else {
                ans = mid;
                r=mid-1;
            }
        }
        return ans;
    }
};