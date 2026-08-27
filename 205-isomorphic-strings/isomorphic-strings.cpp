class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        int n = s.length();
        unordered_map<char, char> map_s;
        unordered_map<char, char> map_t;

        for(int i=0; i<n; i++){
            char c1 = s[i];
            char c2 = t[i];

            if (map_s.count(c1) && map_s[c1] != c2) return false;
            if (map_t.count(c2) && map_t[c2] != c1) return false;

            map_s[c1] = c2;
            map_t[c2] = c1;
        }

        return true;
    }
};