class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length()!=t.length()) 
        return false;

        vector<int> cnt(26,0);

        for(char ch: s){
            cnt[ch-'a']++;
        }
        for(char ch: t){

            if(cnt[ch-'a']==0) return false;

            cnt[ch-'a']--;

            if(cnt[ch-'a']<0) return false;
        }

        return true;
    }
};