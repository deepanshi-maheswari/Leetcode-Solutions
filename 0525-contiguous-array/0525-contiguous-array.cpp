class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        mp[0] = -1;
        //mp[1] = 1;

        int sum = 0;
        int ans = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                sum--;
            else
                sum++;

            if(mp.count(sum)){
                ans = max(ans, i - mp[sum]);
            }
            else{
                mp[sum] = i;
            }

        }

        return ans;
    }
};