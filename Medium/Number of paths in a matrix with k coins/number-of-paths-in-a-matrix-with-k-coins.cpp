//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

    private:
    long long solve(int i,int j,int n,int k,vector<vector<int>>&arr,vector<vector<vector<int>>>&dp)
    {
        
        if(i==n-1 && j==n-1)
        {
            return k==arr[i][j];
        }
        
        if(i<0 || j<0 || i>=n || j>=n || k<=0)return 0;
        
        if(dp[i][j][k]!=-1)return dp[i][j][k];
        
  
        long long right=solve(i+1,j,n,k-arr[i][j],arr,dp);
        long long down=solve(i,j+1,n,k-arr[i][j],arr,dp);
        
        return dp[i][j][k]=right+down;
    }
    
    public:
    long long numberOfPath(int n, int k, vector<vector<int>> arr){
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k+1, -1)));
        
        return solve(0,0,n,k,arr,dp);
    }
};

//{ Driver Code Starts.

int main()
{
    Solution obj;
    int i,j,k,l,m,n,t;
    cin>>t;
    while(t--)
    {
        cin>>k>>n;
        vector<vector<int>> v(n+1, vector<int>(n+1, 0));
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>v[i][j];
        cout << obj.numberOfPath(n, k, v) << endl;
    }
}
// } Driver Code Ends