class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> Group(n, 0);
        int currentGroup = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] - nums[i - 1] > maxDiff){
                ++currentGroup;
            }
            Group[i] = currentGroup;
        }

        vector<bool> qA;
        qA.reserve(queries.size());
        for(vector<int>& q: queries){
            qA.push_back(Group[q[0]] == Group[q[1]]);
        }

        return qA;
    }
};