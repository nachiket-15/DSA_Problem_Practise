//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int f(int index,vector<int>&nums,vector<int>&dp){
    if(index==0)return nums[0];

    if(dp[index]!=-1)return dp[index];
    
    int pick=nums[index]+f(index-2,nums,dp);
    int notpick=0+f(index-1,nums,dp);

    return dp[index]=max(pick,notpick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    //asked in arcesium online assesment
    int n=nums.size();
    vector<int>dp(n,-1);
    return f(n-1,nums,dp);
}
	int findMaxSum(vector<int>&arr, int n) {
	    // code here
	    return maximumNonAdjacentSum(arr);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>arr(n);
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