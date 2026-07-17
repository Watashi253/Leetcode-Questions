class Solution {
public:
bool check(int ind, int cnt, string &s){

    if(cnt<0) return false;
    if(ind >= s.size()){
        return cnt==0;
    }

    char c=s[ind];
    if(c=='('){
        return check(ind+1, cnt+1, s);
    }
    else if(c==')'){
        return check(ind+1, cnt-1, s);
    }

    return check(ind+1, cnt+1, s) || check(ind+1, cnt-1, s) || check(ind+1, cnt, s);
}
    bool checkValidString(string s) {
        int n=s.size();
        int minopen=0, maxopen=0;

        for(char c: s){
            if(c=='(') {
                maxopen++;
                minopen++;
            }
            else if(c==')'){
                maxopen--;
                minopen--;
            }
            else{
                maxopen++;
                minopen--;
            }
            if (maxopen < 0) return false;
            if (minopen < 0) minopen = 0;
        }
        return minopen==0;
    }
};