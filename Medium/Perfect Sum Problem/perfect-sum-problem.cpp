//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int solve(int ind,int arr[],int target,vector<vector<int>>&dp)
    {
    	
    	if(ind==-1){
    		return 0==target;
    	}
    	if(dp[ind][target]!=-1){
    		return dp[ind][target];
    	}
    	int notTake=solve(ind-1,arr,target,dp);
    	int Take=0;
    	if(arr[ind]<=target){
    		Take=solve(ind-1,arr,target-arr[ind],dp);
    	}
    	return dp[ind][target]=(Take+notTake)%(int)(1e9+7);
    }
    
	int perfectSum(int arr[], int n, int sum)
	{
        int k=sum;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
    	return solve(n-1,arr,k,dp);
	}
	  
};




//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends