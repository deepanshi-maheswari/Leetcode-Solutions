class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        vector<int> next(nums2.size(), -1);
        stack<int> st;
        for(int i = nums2.size() - 1; i >= 0; i--){
            while(!st.empty() && nums2[i] >= nums2[st.top()]){
                st.pop();
            }

            if(!st.empty()){
                next[i] = nums2[st.top()];
            }
            st.push(i);
        }

        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                    ans.push_back(next[j]);
                }
            }
        }

        return ans;
    }
};