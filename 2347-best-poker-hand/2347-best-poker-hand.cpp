class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        vector<int> cnt(14, 0);

        bool flush = true;

        for(int i = 0; i < 5; i++){
            cnt[ranks[i]]++;

            if(suits[i] != suits[0]){
                flush = false;
            }
        }

        if(flush){
            return "Flush";
        }

        for(int i = 1; i <= 13; i++){
            if(cnt[i] >= 3){
                return "Three of a Kind";
            }
        }

        for(int i = 1; i <= 13; i++){
            if(cnt[i] >= 2){
                return "Pair";
            }
        }


        return "High Card";
    }
};