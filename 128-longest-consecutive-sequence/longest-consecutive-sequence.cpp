class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(),nums.end()) ;
        int longest=0;
        for(int num:s){
            if(!s.count(num-1)){
                int cur=num;
                int l=1;
                while(s.count(cur+1)){
                    cur++;
                    l++;
                }
                longest=max(longest,l);
            }
        }
        return longest;
    }
};