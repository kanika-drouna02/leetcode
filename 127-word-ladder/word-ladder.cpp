class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.size() != endWord.size()) return 0;
        if( beginWord==endWord) return 1;
        int fg=0;
        set<string>st;
        for(auto s:wordList){
            st.insert(s);
            if(s==endWord) fg=1;
        }
        if(fg!=1) return 0;
        if(beginWord.size()==1) return 2;


        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()){
            string s=q.front().first;
            int t=q.front().second;
            q.pop();
            if(s==endWord) return t;
            for(int i=0;i<s.size();i++){
                string temp=s;
                for(char c='a'; c<='z'; c++){
                    temp[i]=c;
                    if(st.count(temp)){
                        q.push({temp,t+1});
                        st.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};