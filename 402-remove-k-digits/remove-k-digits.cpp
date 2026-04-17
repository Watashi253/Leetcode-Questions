class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        string res = "";
        for (int i = 0; i < n; i++) {
            while (!st.empty() && num[i] < st.top() && k != 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        int i = 0;
        while (i < res.size() && res[i] == '0')
            i++;
        res = res.substr(i);
        
       return res.empty() ? "0" : res;
    }
};