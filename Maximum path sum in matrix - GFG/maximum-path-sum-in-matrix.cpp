//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int j,vector<vector<int>>&Matrix,vector<vector<int>>&dp)
    {
        //Base cases
        
        //Always check first out of bound in base cases
        if(j<0 || j>=Matrix[0].size()){
            return -1e8;
        }
        //When you reach first row
        if(i==0){
            return Matrix[0][j];
        }
        
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up=Matrix[i][j]+solve(i-1,j,Matrix,dp);
        int leftDiagonal=Matrix[i][j]+solve(i-1,j-1,Matrix,dp);
        int rightDiagonal=Matrix[i][j]+solve(i-1,j+1,Matrix,dp);
        
        return dp[i][j]=max(up,max(leftDiagonal,rightDiagonal));
    }
    int maximumPath(int N, vector<vector<int>> matrix)
    {
        /*
        
        //Memoization solution
        int n=Matrix.size();
        int m=Matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        //In last row , go through al columns for starting
        int maxi=-1e9;
        
        //We start traversing from last row to first row
        for(int j=0;j<m;j++){
            maxi=max(maxi,solve(n-1,j,Matrix,dp));
        }
        return maxi;
        
        */
    int n=matrix.size();
    int m=matrix[0].size();

    vector<vector<int>>dp(n,vector<int>(m,-1));

    //Tabulation solution

    //Base case 

    //Fill dp array with first row
    for(int j=0;j<m;j++){
        dp[0][j]=matrix[0][j];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){

            int up=matrix[i][j]+dp[i-1][j];

            int ld=matrix[i][j];
            if(j-1>=0 && j-1<m)
                ld+=dp[i-1][j-1];
            else ld+=-1e9;  

            int rd=matrix[i][j];
            if(j+1>=0 && j+1<m)
               rd+=dp[i-1][j+1];
            else rd+=-1e9;

            dp[i][j]=max(up,max(ld,rd));
        }
    }
    int maxi=-1e9;
    for(int j=0;j<m;j++){
        maxi=max(maxi,dp[n-1][j]);
    }
    return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends