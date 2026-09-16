class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> dq;

        vector<int> ans;

        for(int i = 0; i < k; i++){
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        ans.push_back(nums[dq.front()]);

        for(int j = k; j < n; j++){
            while(!dq.empty() && j - dq.front() >= k){
                dq.pop_front();
            }

            while(!dq.empty() && nums[j] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(j);
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};