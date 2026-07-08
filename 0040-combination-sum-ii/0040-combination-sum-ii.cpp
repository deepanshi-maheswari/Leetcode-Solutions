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
            if(i > index && candidates[i] == candidates[i - 1]){
                continue;
            }
            temp.push_back(candidates[i]);

            solve(candidates , target - candidates[i] , temp , i+1);

            temp.pop_back(); //backtracking
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;

        solve(candidates, target, temp, 0);

        // set<vector<int>> st;
        // for(auto e:ans){
        //     st.insert(e);
        // }
        // ans.clear();
        // for(auto e:st){
        //     ans.push_back(e); //only unique vectors.
        // }

        return ans;
    }
};