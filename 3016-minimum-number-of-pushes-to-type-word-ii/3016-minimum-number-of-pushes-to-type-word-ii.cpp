class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for(char ch: word){
            freq[ch - 'a']++;
        }

        sort(freq.begin(), freq.end(), greater<int>());

        int press = 0;
        for(int i = 0; i < 26; i++){
            press += (i / 8 + 1) * freq[i];
        }

        return press;
    }
};