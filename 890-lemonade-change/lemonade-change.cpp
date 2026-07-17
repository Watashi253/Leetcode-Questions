class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int ct5=0, ct10=0, ct20=0; 
        int n=bills.size();

        for(int i=0; i<n; i++){
            if(bills[i]==5) ct5++;
            else if(bills[i]==10){
                if(ct5==0) return false;
                else {
                    ct5--;
                    ct10++;
                }
            }
            else if(bills[i]==20){
                if(ct5==0) return false;
                int rem=15;
                if(ct10>0){
                    ct10--;
                    rem-=10;
                }
                while(rem>0 && ct5>0){
                    rem-=5;
                    ct5--;
                }
                if(rem>0) return false;
            }
        }
        return true;
    }
};