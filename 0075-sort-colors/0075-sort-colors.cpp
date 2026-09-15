class Solution {
public:
    void sortColors(vector<int>& nums) {
      // sort(nums.begin(), nums.end()); 

      int n = nums.size();
      int i = 0;
      int j = n - 1;
      vector<int> freq(3, 0);

      for(int x: nums){
        freq[x]++;
      }

      while(i < freq[0]){
        nums[i] = 0;
        i++;
      }

      while(j >= n - freq[2]){
        nums[j] = 2;
        j--;
      }

      while(i <= j){
        nums[i] = 1;
        i++;
      }

    }
};