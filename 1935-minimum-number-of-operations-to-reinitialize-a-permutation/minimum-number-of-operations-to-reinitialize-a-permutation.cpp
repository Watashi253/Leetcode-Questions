class Solution {
public:
    int reinitializePermutation(int n) {

        vector<int> nums(n,0);
        for(int i=0; i<n; i++){
            nums[i]=i;
        }
        
        vector<int> arr(n,0), perm=nums;
        int c=0;

        while(arr!=perm){
            c++;
            for(int i=0; i<n; i++){
            if(i%2==0){
                arr[i]=nums[i/2];
            }
            else{
                arr[i]=nums[n/2 +(i-1)/2];
            }
        }
        nums=arr;
        }

        return c;
    }
};