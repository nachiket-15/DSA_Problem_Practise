//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int f(int i,int j,int k,string a,string b,string c,int n1,int n2,int n3,vector<vector<vector<int>>> &dp)
{
    if(i<0 || j<0 ||k<0)
        return 0;
    if(dp[i][j][k]!=-1)
        return  dp[i][j][k];
    if(a[i]==b[j] && b[j]==c[k])
    {
        return 1+f(i-1,j-1,k-1,a,b,c,n1,n2,n3,dp);
    }
    
    return dp[i][j][k]=max(f(i-1,j,k,a,b,c,n1,n2,n3,dp),max(f(i,j-1,k,a,b,c,n1,n2,n3,dp),f(i,j,k-1,a,b,c,n1,n2,n3,dp)));
}
int LCSof3 (string a, string b, string c, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> dp(n1,vector<vector<int>> (n2,vector<int>(n3,-1)));
    return f(n1-1,n2-1,n3-1,a,b,c,n1,n2,n3,dp);
}