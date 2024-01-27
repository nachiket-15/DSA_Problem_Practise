//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int func(int index,vector<int>&heights,vector<int>&dp){
        //If you have reached destination , return 0
        if(index==0){
            return 0;
        }
        
        if(dp[index]!=-1){
            return dp[index];
        }
        //When we take one step 
        int oneStep=func(index-1,heights,dp)+abs(heights[index]-heights[index-1]);
        //When we take two step (We are initially not sure if 
        //we can take two stairs or not as there might be case 
        //when we are just one step away from destination)
        int twoStep=INT_MAX;
        
        if(index>1)
            twoStep=func(index-2,heights,dp)+abs(heights[index]-heights[index-2]);
    
        return dp[index]=min(oneStep,twoStep);
    }
    int minimumEnergy(vector<int>& heights, int n) {
        vector<int>dp(n+1,-1);
        return func(n-1,heights,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends