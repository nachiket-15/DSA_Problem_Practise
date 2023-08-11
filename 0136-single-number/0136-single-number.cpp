class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //TC - O(N) , SC - O(1)
        int ans=0;
        for(auto x:nums){
            ans=ans^x;
        }
        return ans;
    }
};