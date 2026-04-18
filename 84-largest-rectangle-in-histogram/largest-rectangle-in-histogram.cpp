class Solution {
public:
vector<int> pse(vector<int>& heights){
vector<int> ans(heights.size());
stack <int> st;
for(int i=0; i<heights.size();i++){
    while(!st.empty() && heights[st.top()]>=heights[i]){
        st.pop();
    }
    if(st.empty())
    ans[i]=0;
    else 
    ans[i]=st.top()+1;
    st.push(i);
}
return ans;
}
vector<int> nse(vector<int>& heights){
    int n=heights.size();
vector<int> ans(n);
stack <int> st;
for(int i=n-1; i>=0;i--){
    while(!st.empty() && heights[st.top()]>=heights[i]){
        st.pop();
    }
    if(st.empty())
    ans[i]=n;
    else 
    ans[i]=st.top();
    st.push(i);
}
return ans;
}
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev=pse(heights);
        vector<int> next=nse(heights);
        int mx=INT_MIN;
        for(int i=0; i<heights.size(); i++){
            int area=(next[i]-prev[i])*heights[i];
            mx=max(area,mx);
        }
        return mx;
    }
};