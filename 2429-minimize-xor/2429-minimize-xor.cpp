class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0;
        int ans = 0;

        while(num2 > 0){
            if(num2 & 1){
                cnt++;
            }
            num2 = num2 >> 1;
        }

        for(int i = 31; i >= 0 && cnt > 0; i--){ //i - 32 to 0
            if(num1 & (1 << i )){
                ans |= (1 << i);
                cnt--;
            }
        }

        for(int i = 0; i <= 31 && cnt > 0; i++){
            if(!(num1 & (1 << i))){
                ans |= (1 << i);
                cnt--;
            }
        }

        return ans;
    }
};