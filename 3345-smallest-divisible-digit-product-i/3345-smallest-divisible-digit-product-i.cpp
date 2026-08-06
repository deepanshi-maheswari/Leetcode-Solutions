class Solution {
public:
    int smallestNumber(int n, int t) {
        int num = n;

        while(true){
            int d = 1;
            int temp = num;

            while(temp){
                d *= (temp % 10);
                temp /= 10;
            }

            if(d % t == 0)
                return num;
            
            num++;
        }
    }
};