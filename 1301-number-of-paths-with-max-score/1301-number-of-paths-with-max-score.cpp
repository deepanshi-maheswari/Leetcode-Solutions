class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();

        vector<vector<int>> score(n, vector<int>(n, -1));
        vector<vector<int>> ways(n, vector<int>(n, 0));

        // Base case
        score[0][0] = 0;
        ways[0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'X')
                    continue;

                // Skip starting cell (E)
                if (i == 0 && j == 0)
                    continue;

                int bestScore = -1;
                long long totalWays = 0;

                // Top
                if (i > 0 && ways[i - 1][j] > 0) {
                    if (score[i - 1][j] > bestScore) {
                        bestScore = score[i - 1][j];
                        totalWays = ways[i - 1][j];
                    } else if (score[i - 1][j] == bestScore) {
                        totalWays = (totalWays + ways[i - 1][j]) % MOD;
                    }
                }

                // Left
                if (j > 0 && ways[i][j - 1] > 0) {
                    if (score[i][j - 1] > bestScore) {
                        bestScore = score[i][j - 1];
                        totalWays = ways[i][j - 1];
                    } else if (score[i][j - 1] == bestScore) {
                        totalWays = (totalWays + ways[i][j - 1]) % MOD;
                    }
                }

                // Diagonal
                if (i > 0 && j > 0 && ways[i - 1][j - 1] > 0) {
                    if (score[i - 1][j - 1] > bestScore) {
                        bestScore = score[i - 1][j - 1];
                        totalWays = ways[i - 1][j - 1];
                    } else if (score[i - 1][j - 1] == bestScore) {
                        totalWays = (totalWays + ways[i - 1][j - 1]) % MOD;
                    }
                }

                if (bestScore == -1)
                    continue;

                int val = 0;
                if (board[i][j] >= '1' && board[i][j] <= '9')
                    val = board[i][j] - '0';

                score[i][j] = bestScore + val;
                ways[i][j] = totalWays % MOD;
            }
        }

        if (ways[n - 1][n - 1] == 0)
            return {0, 0};

        return {score[n - 1][n - 1], ways[n - 1][n - 1]};        
    }
};