class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int sum1=0, ch1=0, sum2=0, ch2=0; 

        for(int i=0; i<n/2; i++){
            if(num[i]=='?')
            ch1++;
            else sum1+=(num[i] - '0');

            if(num[i+n/2]=='?')
            ch2++;
            else sum2+=(num[i+n/2] - '0');
        }

        if((ch1 + ch2) % 2 != 0) {
            return true;
        }
        if (2 * sum1 + 9 * ch1 == 2 * sum2 + 9 * ch2) {
            return false; // Bob wins
        }
        return true;
    }
};