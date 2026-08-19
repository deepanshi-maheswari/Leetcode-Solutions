class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, set<int>> mp;

        for(auto seat: reservedSeats){
            mp[seat[0]].insert(seat[1]);
        } 

        int ans = (n - mp.size()) * 2;  //unreserved seat

        for(auto row: mp){
            set<int> s = row.second;

            bool left = true;
            bool middle = true;
            bool right = true;

            for(int seat = 2; seat <= 5; seat++){
                if(s.count(seat)){
                    left = false;
                    break;
                }
            }

            for(int seat = 6; seat <= 9; seat++){
                if(s.count(seat)){
                    right = false;
                    break;
                }
            }

            for(int seat = 4; seat <= 7; seat++){
                if(s.count(seat)){
                    middle = false;
                    break;
                }
            }

            if(left && right)
                ans += 2;
            else if(left || right || middle)
                ans += 1;
        }


        return ans;
    }
};