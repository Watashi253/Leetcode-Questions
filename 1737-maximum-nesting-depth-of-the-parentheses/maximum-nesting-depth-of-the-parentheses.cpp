class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int c=0, mx=0;
        for(char ch: s){
            if(ch=='('){
                st.push('(');
                c++;
            }
            else if(ch==')'){
                if(!st.empty() && st.top()=='('){
                    st.pop();
                    c--;
                }
            }
            mx=max(mx, c);
        }

        return mx;
    }
};