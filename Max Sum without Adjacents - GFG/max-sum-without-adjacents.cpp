//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
private:
    int solve(vector<int>&dp,int index,int*arr){
        if(dp[index]!=-1){
            return dp[index];
        }
        //Base cases 
        if(index<0)return 0;
        if(index==0)return arr[index];
        
        int pick=arr[index]+solve(dp,index-2,arr);
        int nonPick=0+solve(dp,index-1,arr);
        
        return dp[index]=max(pick,nonPick);
    }
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    //Memoization solution
	    vector<int>dp(n,-1);
	    return solve(dp,n-1,arr);
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