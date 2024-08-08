//{ Driver Code Starts
#include <bits/stdc++.h>
const int mod = 1e9 + 7;
using namespace std;


// } Driver Code Ends


// function to find longest common subsequence

class Solution
{
    public:
    int solve(int i,int j,string &s,string &t,vector<vector<int>>&dp)
    {
    	//Base case
    	if(i<0 ||j<0){
    		return 0;
    	}
    	//Memoization
    	if(dp[i][j]!=-1){
    		return dp[i][j];
    	}
    	if(s[i]==t[j]){
    		return 1+solve(i-1,j-1,s,t,dp);
    	}
    	return dp[i][j]=max(solve(i,j-1,s,t,dp),solve(i-1,j,s,t,dp));
    }
    
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s, string t)
    {
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
	   // return solve(n-1,m-1,s,t,dp);
	   
	   //Tabulation
	   
	   //Base case
	   for(int i=0;i<=n;i++)dp[i][0]=0;
	   for(int j=0;j<=m;j++)dp[0][j]=0;
	   
	   //
	   for(int i=1;i<=n;i++){
	       for(int j=1;j<=m;j++){
	            if(s[i-1]==t[j-1]){
    		        dp[i][j]= 1+dp[i-1][j-1];
    	        }
    	        else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
	       }
	   }
	   return dp[n][m];
	   
    }
};





//{ Driver Code Starts.
int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m; // Take size of both the strings as input
        string str1, str2;
        cin >> str1 >> str2; // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, str1, str2) << endl;
    }
    return 0;
}

// } Driver Code Ends