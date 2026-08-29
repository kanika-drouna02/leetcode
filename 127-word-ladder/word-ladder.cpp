class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(), wordList.end());
        if (!st.count(endWord)) return 0;

        queue<pair<string,int>> q;
        q.push({beginWord, 1});

        while (!q.empty()) {
            auto [s, t] = q.front();
            q.pop();
            if (s == endWord) return t;

            for (int i = 0; i < (int)s.size(); i++) {
                string tmp = s;             
                for (char c = 'a'; c <= 'z'; c++) {
                    tmp[i] = c;
                    if (st.count(tmp)) {
                        q.push({tmp, t + 1});
                        st.erase(tmp);       
                    }
                }
            }
        }
        return 0; 
    }
};