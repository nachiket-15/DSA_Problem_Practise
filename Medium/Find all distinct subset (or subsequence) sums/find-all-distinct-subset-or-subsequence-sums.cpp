//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int func(int i,int sum,vector<int>&nums,set<int>&st,
        vector<vector<int>>&dp){
        
        if(i>=nums.size()){
          st.insert(sum);
          return 0;  
        } 
        if(dp[i][sum]!=-1) return dp[i][sum];
        
        // take
        int take=func(i+1,sum+nums[i],nums,st,dp);
        
        // nottake
        int nottake=func(i+1,sum,nums,st,dp);
        
        return dp[i][sum]=max(take,nottake);
    }
    vector<int> DistinctSum(vector<int>nums){
        // Code here
        int maxSum=0;
        for(int i=0;i<nums.size();i++) maxSum=maxSum+nums[i];
        
        vector<vector<int>>dp(nums.size()+1,vector<int>(maxSum+1,-1));
        
       // map<int,int>mp;
       set<int>st;
      
        
        func(0,0,nums,st,dp);

        vector<int>ans(st.begin(),st.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int> ans = obj.DistinctSum(nums);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}

// } Driver Code Ends