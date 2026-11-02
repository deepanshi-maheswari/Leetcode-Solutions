class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int ans = 0;
        int n = nums.size();
        int mid = nums[n/2];

        for(int i = 0; i < n; i++){
            ans += abs(nums[i] - mid);
        }

        return ans;
    }
};