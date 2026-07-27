class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        int maxi = 0;

        
        maxi = max(maxi, (nums[0] - 1) * (nums[1] - 1));

        return maxi;

    }
};