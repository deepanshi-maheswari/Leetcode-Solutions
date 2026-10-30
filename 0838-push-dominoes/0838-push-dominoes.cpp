class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int prev = -1;
        int i = 0;

        while(i < n){
            if(dominoes[i] == '.'){
                i++;
                continue;
            }

            if(prev == -1){
                if(dominoes[i] == 'L'){
                    for(int t = 0; t < i; t++){
                        dominoes[t] = 'L';
                    } 
                }
            }
            else if(dominoes[prev] == dominoes[i]){
                for(int t = prev + 1; t < i; t++){
                    dominoes[t] = dominoes[i];
                }
            }
            else if(dominoes[prev] == 'R' && dominoes[i] == 'L'){
                int a = prev + 1;
                int b = i - 1;

                while(a < b){
                    dominoes[a] = 'R';
                    dominoes[b] = 'L';
                    a++;
                    b--;
                }
            }

            prev = i;
            i++;
        }

        if(prev != -1 && dominoes[prev] == 'R'){
            for(int t = prev + 1; t < n; t++){
                dominoes[t] = 'R';
            }
        } //ex- "R.."


        return dominoes;
    }
};