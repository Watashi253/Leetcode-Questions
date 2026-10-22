class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> cities(n);

        for(int i=0; i<roads.size(); i++){
            cities[roads[i][0]]++;
            cities[roads[i][1]]++;
        }

        sort(cities.begin(), cities.end());

        long long sum=0;

        for(int i=0; i<n; i++){
            sum+=(long long)(i+1)*cities[i];
        }

        return sum;
    }
};