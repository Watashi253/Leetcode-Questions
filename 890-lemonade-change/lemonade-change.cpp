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
                else if(ct10>0){
                    ct10--; 
                    ct5--;
                }
                else if(ct5>=3) ct5-=3;
                else return false;
            }
        }
        return true;
    }
};