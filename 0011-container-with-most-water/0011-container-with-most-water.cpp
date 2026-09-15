class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int ans = INT_MIN;

        int mn = 0;
        int mx = n - 1;

        while(mn < mx){
            int h = min(height[mn], height[mx]);
            int l = mx - mn;
            int area = h * l;

            ans = max(ans, area);

            if(height[mn] < height[mx]){
                mn++;
            }
            else{
                mx--;
            }
        }

        return ans;
    }
};