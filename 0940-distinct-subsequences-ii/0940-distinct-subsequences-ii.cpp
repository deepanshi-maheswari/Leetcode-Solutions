class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;

        long long total = 0;
        vector<long long> dp(26, 0);

        for(char ch: s){
            int x = ch - 'a';

            long long newTotal = (2 * total + 1 - dp[x] + MOD) % MOD;

            dp[x] = total + 1;
            total = newTotal;
        }

        return total;
    }
};