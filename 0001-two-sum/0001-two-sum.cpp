class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* Solution 1 - Done by me :))
        vector<int>ans;
        int n=nums.size();

        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    ans.push_back(i);
                    ans.push_back(j);
                }
            }
        }
        return ans;*/

        //Solution 2 - Referred 
        //This is efficient way 
        unordered_map<int,int>map;//num,index

        for(int i=0;i<nums.size();i++){
            map[nums[i]]=i;
        }

        for(int i=0;i<nums.size();i++){
            int diff = target - nums[i];

            //If difference exists in map and index is not current one
            if(map.count(diff) && map[diff]!=i){
                return {i,map[diff]};
            }
        }

        return {};
    }
};