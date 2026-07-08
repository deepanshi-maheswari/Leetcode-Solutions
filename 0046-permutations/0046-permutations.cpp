class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, int n, int i){
        //base case
        if(i >= n){
            ans.push_back(nums);
            return;
        }

        for(int j = i; j < n; j++){
            swap(nums[i], nums[j]);
            solve(nums, ans, n, i+1);
            swap(nums[i], nums[j]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int i = 0;

        vector<vector<int>> ans;
        //vector<int> temp;

        solve(nums, ans, n, i);
        return ans;
    }
};