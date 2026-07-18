class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n == 0) return true;

        int len = flowerbed.size();
        if(len == 1)
            return flowerbed[0] == 0 && n <= 1;

        int cnt = 0;

        //starting
        if(flowerbed[0] == 0 && flowerbed[1] == 0){
            flowerbed[0] = 1;
            cnt++;
        }

        for(int i = 1; i < len - 1; i++){
            if(flowerbed[i] == 1) continue;

            if(flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0){
                flowerbed[i] = 1;
                cnt++;
            }
        }

        //ending
        if(flowerbed[len - 1] == 0 && flowerbed[len - 2] == 0){
            flowerbed[len - 1] = 1;
            cnt++;
        }


        return cnt >= n ;
    }
};