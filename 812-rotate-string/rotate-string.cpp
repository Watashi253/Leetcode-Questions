class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        string ch=s+s;
        return ch.contains(goal);
    }
};