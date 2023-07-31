//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
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
        // your code here
        vector<vector<int>>dp(n,vector<int>(m,-1));
	    return solve(n-1,m-1,s,t,dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends