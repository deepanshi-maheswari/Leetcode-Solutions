class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        long long sum = 0;
        int ans = INT_MAX;

        for(int j = 0; j < n; j++){
            sum += nums[j];

            while(sum >= target){
                ans = min(ans, j - i + 1);

                sum -= nums[i];
                i++;
            }

        }

        if(ans == INT_MAX){
            return 0;
        }

        return ans;
    }
};