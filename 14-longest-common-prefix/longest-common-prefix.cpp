class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre=strs[0];

        for(int i=1; i<strs.size(); i++){
            int c=0;
            for(int j=0; j<strs[i].length(); j++){
                if(j< pre.length() && pre[j]!=strs[i][j]){
                    pre=pre.substr(0,j);
                    c=1;
                    break;
                }
            }
            if(c==0 && strs[i].length()<pre.length()){
                pre=strs[i];
            }
        }
        return pre;
    }
};