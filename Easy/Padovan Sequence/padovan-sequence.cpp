//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int mod=1e9+7;
    int solve(int n,vector<int>&dp)
    {
        if(n==0|n==1|n==2)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n]%mod;
        }
        return dp[n]=(solve(n-2,dp)%mod+solve(n-3,dp)%mod)%mod;
        
    }
    int padovanSequence(int n)
    {
        
        // vector<int>dp(n+1,-1);
        
        // return solve(n,dp)%mod;
       if(n==0 || n==1 || n==2){
           return 1;
       }
       
       vector<int>dp(n+1,0);
       
       dp[0]=dp[1]=dp[2]=1;
       
       for(int i=3;i<=n;i++){
           dp[i]=(dp[i-2]%mod + dp[i-3]%mod)%mod;
       }
       
       return dp[n];
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
    	Solution ob;
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends