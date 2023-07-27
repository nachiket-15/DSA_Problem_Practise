//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(int ind,vector<int>& arr,int target,vector<vector<int>>&dp)
    {
    	if(ind==0){
    		if(target==0 && arr[0]==target){
                return 2;
            }
            if(target==0 || target==arr[0]){
                return 1;
            }
            return 0;
    	}
    	if(dp[ind][target]!=-1){
    		return dp[ind][target];
    	}
    	int notTake=solve(ind-1,arr,target,dp);
    	int Take=0;
    	if(arr[ind]<=target){
    		Take=solve(ind-1,arr,target-arr[ind],dp);
    	}
    	return dp[ind][target]=(Take+notTake)%(int)(1e9+7);
    }
    int findWays(vector<int>& arr, int k)
    {
    	int n=arr.size();
    	vector<vector<int>>dp(n,vector<int>(k+1,-1));
    	return solve(n-1,arr,k,dp);
    }
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int total=accumulate(arr.begin(),arr.end(),0);
        if(total-d<0|| (total-d)%2){
            return 0;
        }
        return findWays(arr,(total-d)/2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends