class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum = 0;
        int digitMul = 1;
        int num = n;

        while(n){
            int d = n % 10;
            n /= 10;

            digitSum += d;
            digitMul *= d;
        }

        int sum = digitSum + digitMul;

        return (num % sum == 0) ? true : false;
    }
};