class Solution {
public:
    int lHist(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0);
        int maxArea = 0;
        int n = heights.size();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int el = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                maxArea = max(heights[el] * (nse - pse - 1), maxArea);
            }
            st.push(i);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> psum(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    psum[j] += 1;
                else
                    psum[j] = 0;
            }
            maxArea = max(maxArea, lHist(psum));
        }
        return maxArea;
    }
};