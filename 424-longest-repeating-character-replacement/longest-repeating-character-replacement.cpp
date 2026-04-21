class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0,len=0;
        int mx=0,maxf=0,c=0;
        vector <int> hash(26,0);
        while(r<s.size()){
            hash[s[r]-'A']++;
            maxf=max(hash[s[r]-'A'],maxf);
            len=r-l+1;
            c=len-maxf;
            if(c>k){
                hash[s[l]-'A']--;
                c--;
                l++;
            }
            mx=max(r-l+1,mx);
            r++;
        }
        return mx;
    }
};