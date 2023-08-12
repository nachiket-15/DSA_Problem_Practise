class Solution {
public:
    int missingNumber(vector<int>& nums) {
       
       int n=nums.size();
       int res=1;
       vector<int>temp(n+1,0);
       //first insert 0 at all index in temp array
       //have temp array with one size more 
       
       for(int i=0;i<n;i++){
           //Mark attendence of numbers from array
           temp[nums[i]]=1;
       }

       for(int i=0;i<=n;i++){
           //Check which number was absent
           if(temp[i]==0)
                res=i;
       }
       return res;
    }
};