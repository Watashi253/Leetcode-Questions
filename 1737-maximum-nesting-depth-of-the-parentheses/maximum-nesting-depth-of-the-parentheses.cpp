class Solution {
public:
    int maxDepth(string s) {
        int c=0, mx=0;
        for(char ch: s){
            if(ch=='('){
                c++;
            }
            else if(ch==')'){
                c--;
            }
            mx=max(mx, c);
        }

        return mx;
    }
};