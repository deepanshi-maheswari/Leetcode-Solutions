class Solution {
public:
    bool isValid(string s) {
        // if(s.size() == 0){
        //     return true;
        // }

        // int fnd = s.find("abc");
        // if(fnd != string::npos){
        //     //found
        //     string tleft = s.substr(0, fnd);
        //     string tright = s.substr(fnd + 3, s.size());
        //     return isValid(tleft + tright);
        // }

        // return false;


        //METHOD 2:
        if(s[0] != 'a') return false;

        stack<char> st;
        for(auto ch: s){
            if(ch == 'a'){
                st.push(ch);
            }
            else if(ch == 'b' && !st.empty() && st.top() == 'a'){
                st.push(ch);
            }
            else{
                //ch == 'c'
                if(!st.empty() && st.top() == 'b'){
                    st.pop();
                    if(!st.empty() && st.top() == 'a'){
                        st.pop();
                    }
                    else 
                        return false;
                }
                else{
                    return false;
                }
            }
        }

        return st.empty() ? true : false;
    }
};