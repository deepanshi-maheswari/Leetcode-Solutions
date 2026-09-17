class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int, int> mp;
        int diff = 0;

        for(int i = 0; i < n; i++){
            diff = target - nums[i];

            if(mp.find(diff) != mp.end()){
                return {mp[diff] , i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};