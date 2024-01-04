//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int solve(int ind,int buy,int cap,vector<int>& prices,int n,vector<vector<vector<int>>>&dp)
{
    if(ind==n ||cap==0)return 0;
    if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
    if(buy==1){
        //buy or not buy
        return dp[ind][buy][cap]=max(-prices[ind]+solve(ind+1,0,cap,prices,n,dp),0+solve(ind+1,1,cap,prices,n,dp));
    }
    //Sell or dont sell 
    return dp[ind][buy][cap]=max(prices[ind]+solve(ind+1,1,cap-1,prices,n,dp),0+solve(ind+1,0,cap,prices,n,dp));
}
int maxProfit(vector<int>&prices){
    //Write your code here..
    int n=prices.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
    return solve(0,1,2,prices,n,dp);
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends