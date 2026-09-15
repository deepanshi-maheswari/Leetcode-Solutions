class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        int i = 0;

        while(i <= n - 4){
            //skip duplicate i
            if(i > 0 && nums[i] == nums[i-1]){
                i++;
                continue;
            }

            int j = i + 1;

            while(j <= n - 3){
                //skip duplicate j
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    j++;
                    continue;
                }

                int k = j + 1;
                int l = n - 1;

                while(k < l){
                
                    long long sum = (long long) nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++, l--;

                        //skip duplicate k
                        while(k < l && nums[k] == nums[k - 1])
                            k++;
                        //skip duplicate l
                        while(k < l && nums[l] == nums[l + 1])
                            l--;

                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
                j++;
            }

            i++;
        }


        return ans;
    }
};