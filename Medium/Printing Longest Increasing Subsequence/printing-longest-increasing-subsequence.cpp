//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {

        vector<int>dp(n,1);
        vector<int>hash(n,1);
    
        for(int i=0;i<n;i++){
            hash[i]=i;
    
            for(int prev=0;prev<=i-1;prev++){
                if(arr[prev]<arr[i] && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
        }
        
        int ans=-1;
        int lastIdx=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                lastIdx=i;
            }
        }
        vector<int>temp;
        temp.push_back(arr[lastIdx]);
    
        while(hash[lastIdx]!=lastIdx){
            lastIdx=hash[lastIdx];
            temp.push_back(arr[lastIdx]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
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
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends