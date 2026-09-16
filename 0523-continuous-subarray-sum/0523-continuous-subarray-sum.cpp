class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = -1;

        long long sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];

            if(mp.count(sum % k)){
                if(i - mp[sum % k] >= 2)
                    return true;
            }
            else{
                mp[sum % k] = i;
            }
        }

        return false;
    }
};