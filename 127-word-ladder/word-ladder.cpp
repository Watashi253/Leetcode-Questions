class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> w;
        for (auto word : wordList) {
            w.insert(word);
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        int ans = 0;
        while (!q.empty()) {
            auto it = q.front();
            auto word = it.first;
            int dis = it.second;
            q.pop();

            for (int i = 0; i < word.size(); i++) {
                string pattern = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    pattern[i] = c;
                    if (w.count(pattern)) {
                        if (pattern == endWord)
                        return dis + 1;
                        
                        q.push({pattern, dis + 1});
                        w.erase(pattern);
                    }
                }
            }
        }
        return ans;
    }
};