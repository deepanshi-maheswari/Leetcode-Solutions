class Solution {
public:
    vector<string> ans;

    void solve(string gen, int open, int close, int n){
        if(gen.size() == 2*n){
            ans.push_back(gen);
            return;
        }

        if(open < n){
            gen.push_back('(');
            solve(gen, open+1, close, n);
            gen.pop_back(); //backtrack
        }

        if(close < open){
            gen.push_back(')');
            solve(gen, open, close+1, n);
            gen.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string gen;

        solve(gen, 0, 0, n);

        return ans;
    }
};