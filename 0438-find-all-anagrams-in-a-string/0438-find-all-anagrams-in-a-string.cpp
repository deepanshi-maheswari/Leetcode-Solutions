class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size();
        int m = s.size();

        if(n > m){
            return {};
        }

        vector<int> ans;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        for(char ch: p){
            freq1[ch - 'a']++;
        }

        for(int i = 0; i < n; i++){
            freq2[s[i] - 'a']++;
        }

        for(int i = 0; i <= m - n; i++){
            if(freq1 == freq2){
                ans.push_back(i);
            }

            freq2[s[i] - 'a']--;
            if(i + n < m)
                freq2[s[i + n] - 'a']++;
        }

        return ans;
    }
};