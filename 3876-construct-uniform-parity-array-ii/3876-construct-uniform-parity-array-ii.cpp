class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mn = *min_element(nums1.begin(), nums1.end());

        //min element odd ho toh sabko odd bana sakate h
        if(mn % 2 == 1)
            return true;

        
        //sab even ho
        for(int x: nums1){
            if(x % 2 == 1)
                return false;
        }

        return true;
    }
};