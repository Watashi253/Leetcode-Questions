class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();

        int cost=0, k=0, len=0;
        for(int i=0; i<n; i++){
            cost+=abs(s[i]-t[i]);
            while(cost>maxCost){
                cost-=abs(s[k]-t[k]);
                k++;
            }
            len=max(len, i-k+1);
        }

        return len;
    }
};