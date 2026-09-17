class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();

        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;

        for(int i = 0; i < n; i++){
            string s = strs[i];

            string key = s;
            sort(key.begin(), key.end());

            mp[key].push_back(s);

        }

        for(auto it: mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};