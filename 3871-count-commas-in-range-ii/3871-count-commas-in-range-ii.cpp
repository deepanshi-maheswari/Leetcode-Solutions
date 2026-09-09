class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        long long a = n - 999;
        if(a > 0){
            ans += a;

            a = n - 999999;
            if(a > 0){
                ans += a;

                a = n - 999999999;
                if(a > 0){
                    ans += a;

                    a = n - 999999999999;
                    if(a > 0){
                        ans += a;

                        a = n - 999999999999999;
                        if(a > 0){
                            ans += a;
                        }
                    }
                }
            }
        } 

        return ans;
    }
};