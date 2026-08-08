class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch: s){
            //opening brakets
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }

            //closing brackets
            else{
                
                if(!st.empty()){
                    if(ch == ')' && st.top() == '('){
                        st.pop();
                    }

                    else if(ch == '}' && st.top() == '{'){
                        st.pop();
                    }

                    else if(ch == ']' && st.top() == '['){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        }

        return st.empty() ? true : false; 
    }
};