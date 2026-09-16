class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int ans = 0;
        vector<int> freq(2, 0);

        for(int j = 0; j < n; j++){
            freq[nums[j]]++;

            while(freq[0] > k){
                freq[nums[i]]--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};