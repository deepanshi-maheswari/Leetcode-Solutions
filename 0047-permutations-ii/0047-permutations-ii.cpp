class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, int s){
        //base case
        if(s == nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_map<int, bool> visited;

        for(int i = s; i < nums.size(); i++){
            if(visited.find(nums[i]) != visited.end())
                continue;
            
            visited[nums[i]] = true;
            swap(nums[i], nums[s]);
            solve(nums, ans, temp, s +1);
            swap(nums[i], nums[s]);
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;

        solve(nums, ans, temp, 0);

        //push ans into set
        // set<vector<int>> st;
        // for(auto e: ans){
        //     st.insert(e);
        // }
        // ans.clear();
        // for(auto e: st){
        //     ans.push_back(e);
        // }
        return ans;
    }
};