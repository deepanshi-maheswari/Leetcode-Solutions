class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n = classroom.size();
        int m = classroom[0].size();

        vector<pair<int, int>> litter;
        int sr = -1, sc = -1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(classroom[i][j] == 'S'){
                    sr = i;
                    sc = j;
                }
                else if(classroom[i][j] == 'L'){
                    litter.push_back({i, j});
                }
            }
        }

        int k = litter.size();

        if(k == 0)
            return 0;

        vector<vector<int>> id(n, vector<int>(m, -1));

        for(int i = 0; i < k; i++){
            id[litter[i].first][litter[i].second] = i;
        }

        int fullMask = (1 << k) - 1;

        queue<array<int, 4>> q;
        q.push({sr, sc, energy, 0});

        vector<vector<vector<vector<bool>>>> visited(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(energy + 1, vector<bool>(1 << k, false))));

        visited[sr][sc][energy][0] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while(!q.empty()){
            int sz = q.size();

            while(sz--){
                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                if(mask == fullMask)
                    return moves;

                if(currEnergy == 0)
                    continue;

                for(int i = 0; i < 4; i++){
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                        continue;

                    if(classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy = currEnergy - 1;
                    int newMask = mask;

                    if (classroom[nr][nc] == 'L') {
                        newMask |= (1 << id[nr][nc]);
                    }

                    // If we reach machine, refill energy
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    if (!visited[nr][nc][newEnergy][newMask]) {

                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            } 

            moves++;           
        }

        return -1;
    }
};