class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // unordered_set<int> pairXor;
        // unordered_set<int> ans;

        // int n = nums.size();

        // for(int i = 0; i < n; i++){
        //     for(int j = 1; j < n; j++){
        //         pairXor.insert(nums[i] ^ nums[j]);
        //     }
        // }

        // for(int x: pairXor){
        //     for(int n: nums){
        //         ans.insert(x ^ n);
        //     }
        // }

        // return ans.size();


        int n = nums.size();

        if (n <= 2) return n;

        int ans = 1;
        while (ans <= n) ans <<= 1;

        return ans;
    }
};