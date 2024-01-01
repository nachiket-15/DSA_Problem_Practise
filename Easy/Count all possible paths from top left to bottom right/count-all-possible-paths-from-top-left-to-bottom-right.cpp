//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
      long long solve(int i, int j,int m,int n, vector<vector<int>>&dp){
        
        //bc
        if(i== m-1 && j==n-1){
            return 1;
        }
        
        if(i>=m || j>= n)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        dp[i][j] = (solve(i+1,j,m,n,dp)+solve(i,j+1,m,n,dp))%1000000007;
        return dp[i][j];
    }
    long long int numberOfPaths(int m, int n){
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return solve(0,0,m,n,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends