class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int sum = 0;

        for(int i = 1; i <= n; i++){
            int product = i * (('z' - s[i - 1]) + 1);
            sum += product;
        }

        return sum;
    }
};