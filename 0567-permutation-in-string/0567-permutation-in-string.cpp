class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        if(m > n){
            return false;
        }
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(char ch: s1){
            freq1[ch - 'a']++;
        }

        for(int i = 0; i < m; i++){
            freq2[s2[i] - 'a']++;
        }

        for(int i = 0; i <= n - m; i++){
            if(freq1 == freq2){
                return true;
            }

            freq2[s2[i] - 'a']--;
            if(i + m < n)
                freq2[s2[i + m] - 'a']++;
        }

        return false;
    }
};