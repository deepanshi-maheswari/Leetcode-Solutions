class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        vector<int> present(52);

        for(int i = 0; i < n; i++){
            present[nums[i]] = true;
        }

        int sum = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] ==  nums[i - 1] + 1){
                sum += nums[i];
            }
            else{
                break;
            }
        }
        if(sum > 50) return sum;
        for(int i = sum; i <= 52; i++){
            if(!present[i]) return i;
        }

        return 0;
    }
};