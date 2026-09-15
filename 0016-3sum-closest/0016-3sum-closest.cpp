class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = nums[0] + nums[1] + nums[2];

        int i = 0;

        while(i < n - 2){
            int j = i + 1;
            int k = n - 1;

            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];

                if(abs(sum - target) < abs(ans - target)){
                    ans = sum;
                }

                if(sum < target){
                    j++;
                }
                else if(sum > target){
                    k--;
                }
                else{
                    return target;
                }
            }

            i++;
        }


        return ans;
    }
};