class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>C;
        unordered_map<int, int> hash;
        for(int i=0;i<n;i++){
            hash[A[i]]++;
            hash[B[i]]++;
            int c=0;
            for(int j=0; j<hash.size();j++){
                if(hash[j]==2) c++;
            }
            C.push_back(c);
        }
    return C;
    }
};