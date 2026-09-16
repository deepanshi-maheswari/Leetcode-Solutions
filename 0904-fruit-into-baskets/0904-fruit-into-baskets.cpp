class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();

        vector<int> freq(n, 0);

        int i = 0;
        int ans = 0;
        int type = 0;


        for(int j = 0; j < n; j++){
            if(freq[fruits[j]] == 0){
                type++;
            }

            freq[fruits[j]]++;

            while(type > 2){
                freq[fruits[i]]--;

                if(freq[fruits[i]] == 0){
                    type--;
                }
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
        
    }
};