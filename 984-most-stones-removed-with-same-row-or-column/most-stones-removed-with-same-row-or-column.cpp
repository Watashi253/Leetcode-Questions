class DisjointSet {
public:
    vector<int> par, size;
    DisjointSet( int n ){
        par.resize(n);
        size.resize(n,1);
        for(int i=0; i<n; i++){
            par[i]=i;
        }
    }
    int find(int node){
        if(par[node]==node){
            return node;
        }
        return par[node]=find(par[node]);
    }
    void unionbySize(int u, int v){
        int rootU=find(u);
        int rootV=find(v);
        if(rootU==rootV)return;

        if (size[rootU] < size[rootV]) {
            par[rootU] = rootV;
            size[rootV] += size[rootU];
        } else {
            par[rootV] = rootU;
            size[rootU] += size[rootV];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
     int n=stones.size();
     DisjointSet ds(n);

     for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    ds.unionbySize(i, j);
                }
            }
        } 

    int ct=0;
    for(int i=0; i<n; i++){
        if(ds.find(i)==i) ct++;
    }

    return n-ct;
    }
};