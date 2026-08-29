class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.size();
        string ans="";

        for(int i=n-1; i>=0; i--){
            
            if(s[i]==' ') continue;

            int right = i;

                while(i>=0 && s[i]!=' ')
                i--;

            ans+=s.substr(i+1, right - i);
            ans += " ";
        }
            
        if(!ans.empty()) ans.pop_back();
        
        return ans;
    }
};