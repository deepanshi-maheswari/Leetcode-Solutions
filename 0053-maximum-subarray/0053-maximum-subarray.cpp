class Solution {
public:
   int maxSubArrayHelper(vector<int>& nums, int start, int end){
    if(start == end) return nums[start];

    int maxLeftBoaderSum = INT_MIN, maxRightBoaderSum = INT_MIN;
    int leftBoaderSum = 0, rightBoaderSum = 0;

    int mid = start + (end - start) / 2;

    int maxLeftSum = maxSubArrayHelper(nums, start, mid);
    int maxRightSum = maxSubArrayHelper(nums, mid + 1, end);

    // Max Cross Boader Sum.
    for(int i = mid; i >= start; i--){
        leftBoaderSum += nums[i];
        if(leftBoaderSum > maxLeftBoaderSum){
            maxLeftBoaderSum = leftBoaderSum;
        }
    }

    for(int i = mid + 1; i <= end; i++){
        rightBoaderSum += nums[i];
        if(rightBoaderSum > maxRightBoaderSum){
            maxRightBoaderSum = rightBoaderSum;
        }
    }
    int crossBoaderSum = maxLeftBoaderSum + maxRightBoaderSum;

    return max(maxLeftSum, max(maxRightSum, crossBoaderSum));
   } 
    
    int maxSubArray(vector<int>& nums) {
        // int sum = nums[0];
        // int maxi = nums[0];

        // for(int i = 1; i < nums.size(); i++){
        //     sum = max(nums[i] , sum + nums[i]);
        //     maxi = max(sum , maxi);
        // }

        // return maxi;

        return maxSubArrayHelper(nums, 0, nums.size() - 1);
    }
};