class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        //Simply include only those who havent been included twice already
        for(int n:nums){
            if(i<2 || n>nums[i-2]){
                nums[i++]=n;
            }
        }

        return i;
    }
};