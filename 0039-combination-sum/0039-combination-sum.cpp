class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates , int target , vector<int>& temp , int index){
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        if(target < 0){
            return;
        }

        for(int i = index; i < candidates.size(); i++){
            temp.push_back(candidates[i]);

            solve(candidates , target - candidates[i] , temp , i);

            temp.pop_back(); //backtracking
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;

        solve(candidates , target , temp, 0);
         
        return ans;
    }
};