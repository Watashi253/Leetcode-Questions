class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        vector<int> hash(n,0);
        for(int i=0; i<n; i++){
            int diff=abs(s[i]-t[i]);
            hash[i]=diff;
        }

        int cost=0, k=0, len=0;
        for(int i=0; i<n; i++){
            cost+=hash[i];
            if(cost<=maxCost){
                len=max(len, i-k+1);
            }
            while(cost>maxCost){
                cost-=hash[k];
                k++;
            }
        }

        return len;
    }
};