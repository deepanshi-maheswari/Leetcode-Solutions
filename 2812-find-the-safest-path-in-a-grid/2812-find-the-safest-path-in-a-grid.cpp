class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool canReach(vector<vector<int>>& dist, int safe){
        int n = dist.size();

        if(dist[0][0] < safe)
            return false;

        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(n,false));

        q.push({0,0});
        vis[0][0] = true;

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();

            if(r == n-1 && c == n-1)
                return true;

            for(auto &d : dir){
                int nr = r + d[0];
                int nc = c + d[1];

                if(nr>=0 && nr<n && nc>=0 && nc<n &&
                   !vis[nr][nc] &&
                   dist[nr][nc] >= safe){

                    vis[nr][nc] = true;
                    q.push({nr,nc});
                }
            }
        }

        return false;
    }
    
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        //int c = grid[0].size();

        if(grid[0][0]  || grid[n-1][n-1])
            return 0;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int , int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]){
                    q.push({i, j});
                    dist[i][j] = 0; //backtraking
                }
            }
        }

        while(!q.empty()){
            for(int i = q.size(); i > 0; i--){
                auto [r , c] = q.front();
                q.pop();

                for(auto& d: dir){
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if(nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == INT_MAX){
                        //md[nr][nc] = md[r][c] + 1;
                        dist[nr][nc] = dist[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }


        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout << md[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        int high = 0;
        for(auto &row : dist){
            for(int x : row){
                high = max(high, x);
            }
        }

        int low = 0;
        int ans = 0;

        while(low <= high){
            int mid = low + (high - low) / 2;

            if(canReach(dist, mid)){
                ans = mid;
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return ans;
    }
};