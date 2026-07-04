class Solution {
public:
    vector<int> parent;

    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int a, int b){
        a = find(a);
        b = find(b);

        if(a != b)
            parent[a] = b;
    }

    int minScore(int n, vector<vector<int>>& roads) {

        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);

        // Build connected components
        for(auto &r : roads){
            Union(r[0], r[1]);
        }

        int root1 = find(1);
        int ans = INT_MAX;

        // Minimum edge in component containing city 1
        for(auto &r : roads){
            if(find(r[0]) == root1){
                ans = min(ans, r[2]);
            }
        }

        return ans;
    }
};