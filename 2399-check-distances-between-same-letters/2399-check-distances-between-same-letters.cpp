class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int>pos(26, -1);

        for(int i = 0; i < s.size(); i++){
            int idx = s[i] - 'a';

            if(pos[idx] == -1){
                pos[idx] = i;
            }
            else{
                int diff = i - pos[idx] - 1;

                if(diff != distance[idx]){
                    return false;
                }
            }
        }

        return true;
    }
};