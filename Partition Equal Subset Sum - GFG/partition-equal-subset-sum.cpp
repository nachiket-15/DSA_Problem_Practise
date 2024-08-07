//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool solve(int ind,int target,int arr[],vector<vector<int>>&dp)
    {
    //Base cases
        if(target==0){
            return true;
        }
        if(ind==0){
            return arr[0]==target;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        bool notTake=solve(ind-1,target,arr,dp);
    
        bool take=false;
        if(arr[ind]<=target){
            take=solve(ind-1,target-arr[ind],arr,dp);
        }
    
        return dp[ind][target]=notTake||take;
    }
    bool isSubsetSum(int n,int k, int arr[]){
        
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return solve(n-1,k,arr,dp);
    }
    int equalPartition(int N, int arr[])
    {
        int totalSum=0;
    	for(int i=0;i<N;i++){
    		totalSum+=arr[i];
    	}
    	if(totalSum%2){
    		return false;
    	}
    	int target=totalSum/2;
    	return isSubsetSum(N,target,arr);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends