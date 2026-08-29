class Solution {
    unordered_map<string,int>mpp;
    vector<vector<string>>ans;
    string b;


private:
    void dfs(string word, vector<string>&seq){
        if(word==b){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());
            return;
        }
        int steps=mpp[word];
        int sz=word.size();
        for(int i=0;i<sz;i++){
            char o=word[i];
            for(char c='a';c<='z';c++){
                word[i]=c;
                if(mpp.find(word)!=mpp.end() && mpp[word]+1 == steps){
                    seq.push_back(word);
                    dfs(word,seq);
                    seq.pop_back();
                }
            }
            word[i]=o;
        }

    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        queue<string>q;
        b=beginWord;
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        q.push(beginWord);
        mpp[beginWord]=1;
        int sz=beginWord.size();

        while(!q.empty()){
            string word=q.front();
            int steps=mpp[word];
            q.pop();
            for(int i=0;i<sz;i++){
                char o=word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)){
                        q.push(word);
                        st.erase(word);
                        mpp[word]= steps+1;
                    }
                }
                word[i]=o;
            }
        }
        if(mpp.find(endWord)!=mpp.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);
        }
        return ans;
    }
};