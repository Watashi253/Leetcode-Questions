class Solution {
public:
    int longestBalanced(string s) {
        int n = s.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int u = 0, f = 0;

            for (int j = i; j < n; j++) {
                int num = s[j] - 'a';

                if (freq[num] == 0)
                    u++;

                freq[num]++;
                f=max(f, freq[num]);

                int curr = j - i + 1;

                if(curr==f*u) c=max(c, curr);
            }
        }

        return c;
    }
};