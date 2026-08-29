class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.size();
        string ans="";

        for(int i=0; i<n; i++){
            string w="";
            while(s[i]!=' ' && i<n){
                w+=s[i];
                i++;
            }
            if(w!="") ans=w+" "+ans;
        }
        ans.pop_back();
        return ans;
    }
};