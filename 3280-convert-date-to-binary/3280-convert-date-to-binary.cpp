class Solution {
public:
    string toBinary(int n){
        string ans = "";

        while(n > 0){
            ans = to_string(n % 2) + ans;
            n = n / 2;
        }

        return ans;
    }
    
    string convertDateToBinary(string date) {
        stringstream ss(date);
        string month, day, year;

        getline(ss, year, '-');
        getline(ss, month, '-');
        getline(ss, day, '-');

        int y = stoi(year);
        int m = stoi(month);
        int d = stoi(day);

        return toBinary(y) + "-" + toBinary(m) + "-" + toBinary(d);
    }
};