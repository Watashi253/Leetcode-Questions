class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int> st;
 for (auto x : arr1) {
            string s = to_string(x);
            for (int i = 1; i <= s.length(); i++) {
                int pref = stoi(s.substr(0, i));
                st.insert(pref);
            }
        }
        int ans = 0;
        for (auto y : arr2) {
            string s = to_string(y);
            for (int i = 1; i <= s.length(); i++) {
                int pref = stoi(s.substr(0, i));
                if (st.find(pref) != st.end()) {
                    ans = max(ans, i);
                }
            }
        }
        return ans;
    }
};