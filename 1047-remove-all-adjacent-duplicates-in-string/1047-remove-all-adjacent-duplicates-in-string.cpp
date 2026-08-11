class Solution {
public:
    string removeDuplicates(string s) {
        //Method 1: string concatination
        // string ans = "";
        // int i = 0;

        // while(i < s.length()){

        //     if(ans.length() > 0){
        //         if(ans[ans.length() - 1] == s[i]){
        //             ans.pop_back();
        //         }
        //         else{
        //             ans.push_back(s[i]);
        //         }
        //     }
        //     else{
        //         ans.push_back(s[i]);
        //     }
        //     i++;
        // }
        // return ans;


        //Method 2: using stack
        int n = s.size();
        stack<char> st;

        for(int i = 0; i < n; i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(!st.empty() && st.top() == s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};