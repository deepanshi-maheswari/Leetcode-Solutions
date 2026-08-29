class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int j = 0;

        for(string word: words){
            for(char c: word){
                if(j >= s.length() || s[j] != c)
                    return false;

                j++;
            }

                if(j == s.length())
                    return true;
        }   

        return false;
    }
};