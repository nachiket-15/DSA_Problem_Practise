class Solution {
public:
    /*This is better approach (brute would be using third loop inside second loop and checking addition of elements to be zero)
    
    Solution using hashSet that gives TLE

    int n=nums.size();
        //Create a set that stores vectors into it
        set<vector<int>>st;

        //Using hashset for finding if third element creating overall sum zero is present or not
        for(int i=0;i<n;i++){
            //everytime create new hashset
            set<int>hashSet;
            for(int j=i+1;j<n;j++){
                int target=-(nums[i]+nums[j]);
                if(hashSet.find(target)!=hashSet.end()){
                    vector<int>v={nums[i],nums[j],target};
                    sort(v.begin(),v.end());
                    st.insert(v);
                }
                hashSet.insert(nums[j]);
            }
        }

        vector<vector<int>>res(st.begin(),st.end());
        return res;
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        //Its like a three pointer approach
        vector<vector<int>>ans;
        //Sort the given array first
        sort(nums.begin(),nums.end());
        set<vector<int>>s;

        //Iterate over loop
        for(int i=0;i<nums.size();i++){
            //Continue when elements are duplicates
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum<0){
                    j++;
                }
                if(sum>0){
                    k--;
                }else if(sum==0){
                    s.insert({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                }
            }
        }
        for(auto triplets:s){
            ans.push_back(triplets);
        }
        return ans;
    }
};