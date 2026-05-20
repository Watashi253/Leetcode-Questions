class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>C;
                    int c=0;
        unordered_map<int, int> hash;
        for(int i=0;i<n;i++){
            hash[A[i]]++;
            if(hash[A[i]]==2)c++;
            hash[B[i]]++;
            if(hash[B[i]]==2)c++;
            C.push_back(c);
        }
    return C;
    }
};