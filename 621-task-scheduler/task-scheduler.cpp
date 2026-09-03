class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26);
        for(auto ch:tasks){
            freq[ch-'A']++;
        }
        int mx=0,cnt=0;

        for(int f:freq) mx=max(mx,f);
        for(int f:freq) if(f==mx) cnt++;

        int slots=(mx-1)*(n+1)+cnt;
        return max((int)tasks.size(),slots);

    }
};