class Solution {
public:
    bool dfs(int node, int target, unordered_map<int, bool>& visited, unordered_map<int, list<int>>& adj){
        if(node == target) return true;

        visited[node] = true;

        for(auto neighbour: adj[node]){
            if(!visited[neighbour]){
                if(dfs(neighbour, target, visited, adj)){
                    return true;
                }
            }
        }

        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int, list<int>> adj;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            unordered_map<int, bool> visited;

            if(dfs(u, v, visited, adj)){
                return {u, v};
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }


        return {};
    }
};