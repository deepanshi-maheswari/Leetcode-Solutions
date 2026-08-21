class Solution {
public:
    
    long long gcd(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    
    long long lcm(long long a, long long b){
        return a / gcd(a, b) * b;
    }
    
    long long countWays(long long x, vector<int>& coins){
        int n = coins.size();
        long long ans = 0;

        for(int mask = 1; mask < (1 << n); mask++){
            long long LCM = 1;
            int bits = 0;
            bool valid = true;

            for(int i = 0; i < n; i++){
                if (mask & (1 << i)) {
                    bits++;

                    LCM = lcm(LCM, coins[i]);

                    // LCM > x means no multiple <= x
                    if (LCM > x) {
                        valid = false;
                        break;
                    }
                }
            }

            if(!valid)
                continue;
            if (bits % 2 == 1)
                ans += x / LCM;
            else
                ans -= x / LCM;
        }

        return ans;
    }
    
    long long findKthSmallest(vector<int>& coins, int k) {
        long long low = 1;
        long long high = 1LL * (*min_element(coins.begin(), coins.end())) * k;

        while(low < high){
            long long mid = low + (high - low) / 2;

            if(countWays(mid, coins) >= k)
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};