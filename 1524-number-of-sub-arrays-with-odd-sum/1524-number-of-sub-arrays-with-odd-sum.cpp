class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        
        int even = 1;
        int odd = 0;

        int sum = 0;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            sum += arr[i];

            if(sum % 2 == 0){
                cnt += odd;
                even++;
            }
            else{
                cnt += even;
                odd++;
            }
            
            cnt %= mod;
        }

        return cnt;
    }
};