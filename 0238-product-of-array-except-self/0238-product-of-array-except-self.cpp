class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        // Step 1: Store prefix products
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // Step 2: Multiply with suffix products
        int suffixProduct = 1;
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= suffixProduct;
            suffixProduct *= nums[i];
        }

        return ans;
    }
};