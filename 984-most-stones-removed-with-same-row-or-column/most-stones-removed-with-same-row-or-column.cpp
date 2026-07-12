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

     unordered_map<int, int> row;
     unordered_map<int, int> col;

    for(int i = 0; i < n; i++) {
        int r=stones[i][0];
        int c=stones[i][1];

        if(row.count(r)){
            ds.unionbySize(row[r], i);
        }
        else {
            row[r]=i;
        }

        if(col.count(c)){
            ds.unionbySize(col[c], i);
        }
        else {
            col[c]=i;
        }
    } 

    int ct=0;
    for(int i=0; i<n; i++){
        if(ds.find(i)==i) ct++;
    }

    return n-ct;
    }
};