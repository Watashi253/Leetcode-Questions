class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int sum=0;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                vector<int> freq(26,0);
                int mn=1e9, mx=0;

                for(int k=i; k<=j; k++){
                    freq[s[k]-'a']++;
                }
                
                for(int k=0; k<freq.size(); k++){
                    if(freq[k]<mn && freq[k]!=0) mn=freq[k];
                    if(freq[k]>mx) mx=freq[k];
                }

                sum+=mx-mn;
            }
        }
        
        return sum;
    }
};