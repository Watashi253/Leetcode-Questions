class Solution {
public:
static bool help(vector<int> a, vector<int> b){
return a.size()< b.size();
}
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> cities(n);

        for(int i=0; i<roads.size(); i++){
            cities[roads[i][0]].push_back(roads[i][1]);
            cities[roads[i][1]].push_back(roads[i][0]);
        }

        sort(cities.begin(), cities.end(), help);

        long long sum=0;

        for(int i=0; i<n; i++){
            sum+=(i+1)*cities[i].size();
        }

        return sum;
    }
};