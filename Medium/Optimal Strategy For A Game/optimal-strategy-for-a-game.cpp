//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    int solve(int arr[],int start,int end,vector<vector<int>>&dp)
    {
        if(start==end)return arr[start];
        if(start>end)return 0;
        
        if(dp[start][end]!=-1)
        {
            return dp[start][end];
        }
        //Minimax strategy is the optimal for game 
        //You take max and let opponent take min so that we win
        int choseLeft=arr[start]+min(solve(arr,start+1,end-1,dp),solve(arr,start+2,end,dp));
        int choseRight=arr[end]+min(solve(arr,start+1,end-1,dp),solve(arr,start,end-2,dp));
        
        return dp[start][end]=max(choseLeft,choseRight);
    }
    long long maximumAmount(int arr[], int n){
        int start=0;
        int end=n-1;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(arr,start,end,dp);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}
// } Driver Code Ends