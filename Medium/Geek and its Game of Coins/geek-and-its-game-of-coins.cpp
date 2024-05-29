//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool solve(int n,int x,int y,vector<bool>&dp)
    {
        //base case = where we can directly win
        
        if(n==1|n==x|n==y)
        {
            return dp[n]=true;
        }
        if(dp[n]!=false)
        {
            return dp[n];
        }
        //consider that opponent wins 
        bool p=true,q=true,r=true;
        //opponent has 3 choices
        if(x<=n)
        {
            p=solve(n-x,x,y,dp);
        }
        if(y<=n)
        {
            q=solve(n-y,x,y,dp);
        }
        if(n>=1)
        {
            r=solve(n-1,x,y,dp);
        }
        
        //if opponent loses in any one case 
        bool ans=(!p||!q||!r);
        return dp[n]=ans;
    }
    int findWinner(int n, int x, int y) {
        vector<bool>dp(n+1,0);
        return solve(n,x,y,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends