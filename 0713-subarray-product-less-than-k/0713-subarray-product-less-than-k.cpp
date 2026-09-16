class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();

        if(k <= 1){
            return 0;
        }

        int i = 0;
        int ans = 0;
        long long product = 1;

        // for(int x: nums){
        //     if(x < k){
        //         ans++;
        //     }
        // }


        for(int j = 0; j < n; j++){
            product *= nums[j];

            while(product >= k){
                product = product / nums[i];
                i++;
            }

            ans += j - i +1;
                
        }

        return ans;
    }
};