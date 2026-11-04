class Solution {
public:
    void dfs(int node, unordered_map<int, list<int>>& adj, unordered_map<int, bool>& visited){
        visited[node] = 1;

        for(auto neigh: adj[node]){
            if(!visited[neigh]){
                dfs(neigh, adj, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, list<int>> adj;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                }
            }
        }

        unordered_map<int, bool> visited;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                cnt++;
                dfs(i, adj, visited);
            }
        }

        return cnt;   
    }
};