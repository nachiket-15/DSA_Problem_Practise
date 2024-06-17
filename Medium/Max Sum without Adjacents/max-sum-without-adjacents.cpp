//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int solve(int*arr,int idx,vector<int>&dp)
	{
	    if(idx<0){
	        return 0;
	    }
	    if(idx==0){
	        return arr[idx];
	    }
	    //Memoization
	    if(dp[idx]!=-1){
	        return dp[idx];
	    }
	    
	    int pick=arr[idx]+solve(arr,idx-2,dp);
	    int nonPick=solve(arr,idx-1,dp);
	    
	    return dp[idx]=max(pick,nonPick);
	}
	int findMaxSum(int *arr, int n) 
	{
	    //This problem uses pick/nonpick strategy
	    
	    vector<int>dp(n,0);
	   // return solve(arr,n-1,dp);
	   
	    // Base case: If there are no elements in the array, return 0
        dp[0] = arr[0];
        
        // Iterate through the elements of the array
        for (int i = 1; i < n; i++) {
            // Calculate the maximum value by either picking the current element
            // or not picking it (i.e., taking the maximum of dp[i-2] + arr[i] and dp[i-1])
            int pick = arr[i];
            if (i > 1)
                pick += dp[i - 2];
            int nonPick = dp[i - 1];
            
            // Store the maximum value in the dp array
            dp[i] = max(pick, nonPick);
        }
        
        // The last element of the dp array will contain the maximum sum
        return dp[n - 1];
	}
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends