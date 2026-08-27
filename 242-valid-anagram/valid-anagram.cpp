class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.length()!=t.length()) 
        return false;

        unordered_map<char, int> cnt;

        for(char ch: s){
            cnt[ch]++;
        }
        for(char ch: t){

            if(!cnt.count(ch)) return false;

            cnt[ch]--;

            if(cnt[ch]<0) return false;
        }

        return true;
    }
};