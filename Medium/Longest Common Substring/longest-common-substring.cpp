//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        //dp array
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
        //Base case for Tabulation:
        
        //Fil first column with 0
        for(int i=0;i<=n;i++)dp[i][0]=0;
        //Fill frst row with 0
        for(int j=0;j<=m;j++)dp[0][j]=0;
        int res=0;
        //Remaining 
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //Match case
                
                //(i-1) & (j-1) as strings have 0 based indexing
                if(S1[i-1]==S2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    res=max(res,dp[i][j]);
                }
                //Non match case
                // else{
                //     dp[i][j]=0;
                // }
            }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends