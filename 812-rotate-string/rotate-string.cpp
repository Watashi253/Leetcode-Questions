class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();

        for(int i=0; i<n; i++){
            string temp=s;
            reverse(temp.begin()+i, temp.end());
            reverse(temp.begin(), temp.begin()+i);
            reverse(temp.begin(), temp.end());

            if(temp==goal) return true;
        }

        return false;
    }
};