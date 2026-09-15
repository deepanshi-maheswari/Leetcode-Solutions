class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        vector<int> freq(26, 0);

        int i = 0;
        int ans = 0;
        int maxFreq = 0;

        for(int j = 0; j < n; j++){
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            int change = (j - i + 1) - maxFreq;

            if(change > k){
                freq[s[i] - 'A']--;
                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};