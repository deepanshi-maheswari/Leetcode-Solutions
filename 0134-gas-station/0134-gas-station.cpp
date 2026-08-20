class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        //kitna petro kaam padg gaya
        int deficit = 0;
        //kitna petro bacha h
        int balance = 0;
        //circit kaha se start kr rahe ho
        int start = 0;

        for(int i = 0; i < gas.size(); i++){
            balance += gas[i] - cost[i];
            if(balance < 0){
                deficit += balance;
                start = i + 1;
                balance = 0;
            }
        }

        if(deficit + balance >= 0){
            return start;
        }
        else{
            return -1;
        }

    }
};