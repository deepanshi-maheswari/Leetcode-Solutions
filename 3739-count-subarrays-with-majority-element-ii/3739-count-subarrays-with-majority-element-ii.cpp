class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> pre(n * 2 + 1, 0);

        pre[n] = 1;
        int count = n;
        long long ans = 0, presum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == target){
                presum += pre[count];
                ++count;
                ++pre[count];
            }
            else{
                --count;
                presum -= pre[count];
                ++pre[count];
            }
            ans += presum;
        }

        return ans;
    }
};