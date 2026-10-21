class Solution {
public:
    int smallestValue(int n) {
        while(true){
        int num=n, sum=0;

        for(int i=2; i*i<=num; i++){
        while(num%i==0){
            num=num/i;
            sum+=i;
        }
        }

        if(num!=1) sum+=num;
        if (sum == n) break;
        n=sum;
        }
        return n;
    }
};