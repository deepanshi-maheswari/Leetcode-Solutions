class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0; //pointer for string word1
        int j = 0; //pointer for string word2

        string ans = "";

        while(i < word1.length() && j < word2.length()){
            ans += word1[i];
            ans += word2[j];
            i++;
            j++;
        }

        //word1 string bachi ho
        while(i < word1.length()){
            ans += word1[i];
            i++;
        }

        //word2 string bachi ho
        while(j < word2.length()){
            ans += word2[j];
            j++;
        }

        return ans;
    }
};