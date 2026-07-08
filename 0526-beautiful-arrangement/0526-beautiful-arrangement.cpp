class Solution {
public:
    void solve(int n, vector<int>& temp, int& ans, int curr){
        //base case
        if(curr == n + 1){
            ans++;
            return;
        }

        for(int i = 1; i <= n; i++){
            if(temp[i] == 0 && (curr % i == 0 || i % curr == 0)){
                temp[i] = curr;
                solve(n, temp, ans, curr + 1);
                //backtraking 
                temp[i] = 0;
            }
        }
    }
    
    int countArrangement(int n) {
        vector<int> temp(n+1);
        int ans = 0;

        solve(n, temp, ans, 1);

        return ans;
    }
};