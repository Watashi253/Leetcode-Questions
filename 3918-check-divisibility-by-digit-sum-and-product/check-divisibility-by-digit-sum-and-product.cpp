class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0, product=1, num=n;

        while(num!=0){
            sum+=num%10;
            product*=num%10;
            num/=10;
        }

        if(n%(sum+product)==0){
            return true;
        }

        return false;
    }
};