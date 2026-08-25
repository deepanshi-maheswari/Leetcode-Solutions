class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        vector<bool> exist(101); 
        for(int num: nums){
            exist[num] = true;
        }

        int num = k;
        while(num < 101){
            if(!exist[num]){
                return num;
            }

            num += k;
        }

        return num;
    }
};