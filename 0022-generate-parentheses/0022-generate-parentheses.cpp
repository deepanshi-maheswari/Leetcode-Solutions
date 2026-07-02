class Solution {
public:
    vector<string> ans;

    void solve(string& curr, int open, int close, int n){
        if(curr.size() == 2 * n){
            ans.push_back(curr);
            return;
        }

        //Add -> '('
        if(open < n){
            curr.push_back('(');
            solve(curr, open + 1, close, n);
            //backtrack
            curr.pop_back();
        }

        //Add -> ')'
        if(close < open){
            curr.push_back(')');
            solve(curr, open, close + 1, n);
            //backtrack
            curr.pop_back(); 
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string curr;

        solve(curr, 0, 0, n);

        return ans;
    }
};