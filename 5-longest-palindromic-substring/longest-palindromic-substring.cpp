class Solution {
public:

int palindrome(string s, int l, int r){
  while (l >= 0 && r < s.length() && s[l] == s[r]) {
            l--;
            r++;
        }
return r-l-1;
}
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0;
        int maxLen = 0;

        for(int i=0; i<s.size(); i++){
            int len1=palindrome(s, i, i);
            int len2=palindrome(s, i, i+1);

            int len=max(len1, len2);

            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2; 
            }
        }

        return s.substr(start, maxLen);
    }
};