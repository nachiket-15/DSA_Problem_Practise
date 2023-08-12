class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //TC - O(N) , SC - O(1)
        int ans=0;
        for(auto x:nums){
            ans=ans^x;
        }
        return ans;

        /*Another approach
        int i=0;
    while(i<arr.size()){
        if(arr[i]==arr[i+1])i+=2;
        else return arr[i];
    }*/
    }
};