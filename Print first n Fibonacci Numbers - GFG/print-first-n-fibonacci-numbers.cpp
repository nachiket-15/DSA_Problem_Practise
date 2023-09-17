//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
     long long solve(int n,vector<long long>&dp)
    {
        
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        
        return dp[n] = solve(n-1,dp) + solve(n-2,dp);
    }
    
    vector<long long> printFibb(int n) 
    {
        //code here
        
        vector<long long>dp(n,-1);
        dp[0]=1;
        if(n==1)
        {
            return dp;
        }
        
        dp[1]=1;
        if(n==2)
        {
            return dp;
        }
        solve(n-1,dp);
        return dp;
        
        
    }
};

//{ Driver Code Starts.
int main()
 {
     //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends