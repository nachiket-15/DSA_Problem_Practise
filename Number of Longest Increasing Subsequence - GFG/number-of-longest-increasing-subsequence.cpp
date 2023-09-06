//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int NumberofLIS(int n, vector<int>&arr) {
        // int n=arr.size();
        vector<int>dp(n,1);
        vector<int>cnt(n,1);
        int maxi=0;
    
        for(int i=0;i<n;i++){
            for(int prev=0;prev<i;prev++){
    
                if(arr[i]>arr[prev] && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    cnt[i]=cnt[prev];
                }
                else if(arr[i]>arr[prev] && 1+dp[prev]==dp[i]){
                    cnt[i]+=cnt[prev];
                }
            }
            maxi=max(dp[i],maxi);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi)ans+=cnt[i];
        }
        // cout<<"Dp array-"<<endl;
        // for(auto i:dp){
        //     cout<<i<<" ";
        // }
        // cout<<"cnt array-"<<endl;
        // for(auto c:cnt){
        //     cout<<c<<" ";
        // }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            arr.push_back(x);
        }
        
        Solution obj;
        cout<<obj.NumberofLIS(n, arr)<<"\n";
    }
    return 0;
}
// } Driver Code Ends