class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        st.push(asteroids[0]);
        for (int i = 1; i < n; i++) {
            int mx = 1;
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                int abs1 = abs(asteroids[i]); // 8
                int abs2 = abs(st.top());     // 8
                if (abs1 > abs2) {; // top explodes
                    st.pop();
                } else if (abs1 < abs2) {
                    mx = 0; // curr explodes
                    break;
                } else {
                    st.pop(); // both explode
                    mx = 0;
                    break;
                }
            }
            if (mx==1) {
                st.push(asteroids[i]); //
            }
        }
        vector<int> ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
};