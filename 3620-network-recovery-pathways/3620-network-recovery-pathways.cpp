class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> graph(n);
        vector<int> indegree(n, 0);

        int left = INT_MAX, right = INT_MIN;
        //int ans = -1;

        for(vector<int>& e: edges){
            int u = e[0] , v = e[1], w = e[2];
            if(online[u] && online[v]){
                graph[u].push_back({v, w});
                indegree[v]++;
                right = max(right, w);
                left = min(left, w);
            }
        }

        if (left == INT_MAX) return -1;

        auto canReach = [&](int mid) -> bool {

            // Topological order
            queue<int> q;
            vector<int> deg = indegree;

            for (int i = 0; i < n; i++) {
                if (deg[i] == 0)
                    q.push(i);
            }

            vector<int> topo;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                topo.push_back(u);

                for (auto &[v, w] : graph[u]) {
                    if (--deg[v] == 0)
                        q.push(v);
                }
            }

            const long long INF = 4e18;
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF) continue;

                for (auto &[v, w] : graph[u]) {
                    if (w < mid) continue;

                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                    }
                }
            }

            return dist[n - 1] <= k;
        };

        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canReach(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans; 
    }
};