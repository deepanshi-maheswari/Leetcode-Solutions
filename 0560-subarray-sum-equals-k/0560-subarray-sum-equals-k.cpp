class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<long long, int> mp;
        mp[0] = 1;

        int ans = 0;
        long long sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];

            if(mp.count(sum - k)){
                ans += mp[sum - k];
            }

            mp[sum]++;
        }

        return ans;
    }
};