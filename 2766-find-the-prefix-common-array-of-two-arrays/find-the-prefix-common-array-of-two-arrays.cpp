class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int> C(n), hash(n+1,0);
        int c=0;
        for(int i=0;i<n;i++){
            hash[A[i]]++;
            if(hash[A[i]]==2)c++;
            hash[B[i]]++;
            if(hash[B[i]]==2)c++;
            C[i]=c;
        }
    return C;
    }
};