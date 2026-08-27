class Solution {
public:
    int romanToInt(string s) {
        int c=0, n=s.size();
        char next=NULL;
        for(int i=0; i<n; i++){
            char ch=s[i];
            if(ch=='I'){
                if(i!=n && (s[i+1]=='V' || s[i+1]=='X')) c-=1;
                else c+=1;
            } 
            else if(ch=='V') c+=5;
            else if(ch=='X'){
                if(i!=n && (s[i+1]=='L' || s[i+1]=='C')) c-=10;
                else c+=10;
            } 
            else if(ch=='L') c+=50;
            else if(ch=='C'){
                if(i!=n && (s[i+1]=='D' || s[i+1]=='M')) c-=100;
                else c+=100;
            } 
            else if(ch=='D') c+=500;
            else if(ch=='M') c+=1000;
        }

        return c;
    }
};