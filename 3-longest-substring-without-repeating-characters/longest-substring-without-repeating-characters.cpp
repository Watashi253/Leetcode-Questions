class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> hash;
        int left=0, right=0;
        int mx=0;
        while(right<s.size()){
            if(hash.find(s[right])!=hash.end()){//char found in hash
            left=max(left, hash[s[right]] + 1);
            }
            mx=max(mx,right-left+1);
            hash[s[right]]=right;
            right++;
        }
        return mx;
    }
};