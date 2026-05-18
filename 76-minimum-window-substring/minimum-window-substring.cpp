class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> freq;
        for(int i=0;i<t.length();i++){
            freq[t[i]]++;
        }
        int l=0,c=0;
        int minlen=INT_MAX,sind=-1;
        for(int r=0;r<s.length();r++){
            if(freq[s[r]]>0) c++;
            freq[s[r]]--;
            while(c==t.length()){//all elements present
            if(minlen>r-l+1){
                minlen=r-l+1;
                sind=l;
            }
            freq[s[l]]++;
            if(freq[s[l]]>0)c--;
            l++;
            }
        }
        if(sind==-1) return "";
        return s.substr(sind,minlen);
    }
};