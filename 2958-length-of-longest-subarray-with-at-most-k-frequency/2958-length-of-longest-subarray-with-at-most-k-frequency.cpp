class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;

        int maxLen = 0;
        int left = 0;

        for(int i = 0; i < n; i++){
            freq[nums[i]]++;

            while(freq[nums[i]] > k){
                freq[nums[left]]--;
                left++;
            }

            maxLen = max(maxLen, i - left + 1);
        }
        

        return maxLen;
    }
};