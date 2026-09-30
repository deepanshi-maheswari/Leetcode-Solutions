class Solution {
public:
    int romanToInt(string s) {
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC" , "L", "XL", "X", "IX", "V", "IV", "I"};

        int value[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int ans = 0;

        for(int i = 0; i < 13; i++){
            while(s.size() >= symbol[i].size() && s.substr(0, symbol[i].size()) == symbol[i]){
                ans += value[i];
                s = s.substr(symbol[i].size());
            }
        }

        return ans;
    }
};