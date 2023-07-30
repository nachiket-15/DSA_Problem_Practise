//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int ind,int n,int price[],vector<vector<int>>&dp)
    {
    	//Base case
    	if(ind==0){
    		return (n*price[0]);
    	}
    	if(dp[ind][n]!=-1){
    		return dp[ind][n];
    	}
    	//
    	int notTake=solve(ind-1,n,price,dp);
    	int take=-1e9;
    	int rodLen=ind+1;
    	if(rodLen<=n){
    		take=price[ind]+solve(ind,n-(rodLen),price,dp);
    	}
    	return dp[ind][n]=max(take,notTake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n,vector<int>(n+1,0));
	   // return solve(n-1,n,price,dp);
	   
	   //Tabulation
	   for(int N=0;N<=n;N++){
	       dp[0][N]=N*price[0];
	   }
	   
	   for(int ind=1;ind<n;ind++){
	       for(int N=0;N<=n;N++){
	            int notTake=dp[ind-1][N];
            	int take=-1e9;
            	int rodLen=ind+1;
            	if(rodLen<=N){
            		take=price[ind]+dp[ind][N-(rodLen)];
            	}
            	dp[ind][N]=max(take,notTake);
	       }
	   }
	   return dp[n-1][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends