class Solution {
public:
bool isPrime(int n){
    int c=0;
for(int i=1; i<n; i++){
    if(n%i==0)c++;
}
return c==1;
}
int prime(int n){
    int sum=0, num=n;
    for(int i=2; i<=n; i++){
        
        int c=0;
        while(num%i==0){
            num=num/i;
            c++;
        }
        sum+=c*i;
        
    }
    return sum;
}
    int smallestValue(int n) {
        int num=n;
        while(num!=0){
            if(num==prime(num)) break;
            num=prime(num);
        }

        return num;
    }
};