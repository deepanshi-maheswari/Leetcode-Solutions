class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited,
             int& nodes, int& degreeSum) {

        visited[node] = true;
        nodes++;
        degreeSum += graph[node].size();

        for (int nei : graph[node]) {
            if (!visited[nei]) {
                dfs(nei, graph, visited, nodes, degreeSum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> graph(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                int nodes = 0;
                int degreeSum = 0;

                dfs(i, graph, visited, nodes, degreeSum);

                int edgeCount = degreeSum / 2;

                if (edgeCount == nodes * (nodes - 1) / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};