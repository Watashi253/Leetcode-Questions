class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        
        int n=word.size(), mx=0;
        unordered_map<string, int> hash;
        for(int i=0; i<=n-k; i+=k){
            string w=word.substr(i, k);
            hash[w]++;
            mx=max(mx, hash[w]);
        }

        int op=(n-(mx*k))/k;
        return op;
    }
};