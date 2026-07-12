class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> rank;
        int currRank = 1;

        for(int x: temp){
            if(rank.find(x) == rank.end()){
                rank[x] = currRank++;
            }
        }

        vector<int> ans;

        for(int x: arr){
            ans.push_back(rank[x]);
        }

        return ans;
    }
};