class Solution {
public:
    int maxProduct(int n) {
        int d1 = n % 10;
        n /= 10;
        int d2 = n % 10;
        n /= 10;

        if(d2 > d1) swap(d1, d2);

        while(n > 0){
            int a = n % 10;
            n /= 10;

            if(a > d1){
                d2 = d1;
                d1 = a;
            }
            else if(a > d2){
                d2 = a;
            }
        }

        return d1 * d2;
    }
};