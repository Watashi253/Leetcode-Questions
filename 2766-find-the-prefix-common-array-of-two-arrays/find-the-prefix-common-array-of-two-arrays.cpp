class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>C;
                    int c=0;
        unordered_map<int, int> hash;
        for(int i=0;i<n;i++){
            hash[A[i]]++;
            hash[B[i]]++;
            if(A[i]!=B[i]){
                if(hash[A[i]]==2) c++;
                if(hash[B[i]]==2) c++;
            }
            else c++;
            C.push_back(c);
        }
    return C;
    }
};