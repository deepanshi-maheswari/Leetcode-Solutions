class Solution {
public:

    void solve(string digits, int index, string output, vector<string>& alphabet, vector<string>& ans){
        //base case
        if(index >= digits.size()){
            ans.push_back(output);
            return;
        }

        int digit = digits[index] - '0';
        string letter = alphabet[digit];

        for(char ch: letter){
            output.push_back(ch);
            solve(digits, index + 1, output, alphabet, ans);
            output.pop_back(); //backtrack
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};

        vector<string> ans;

        vector<string> alphabet = {
            "", //0
            "", //1
            "abc", //2
            "def", //3
            "ghi", //4
            "jkl", //5
            "mno", //6
            "pqrs", //7
            "tuv", //8
            "wxyz", //9
        };

        string output = "";
        solve(digits, 0, output, alphabet, ans);

        return ans;
    }
};