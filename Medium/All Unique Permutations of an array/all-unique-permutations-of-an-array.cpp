//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void func(int idx,vector<int>&arr,set<vector<int>>&ans)
    {
        if(idx==arr.size()){
            ans.insert(arr);
            return;
        }
        
        for(int i=idx;i<arr.size();i++)
        {
            swap(arr[idx],arr[i]);
            func(idx+1,arr,ans);
            swap(arr[i],arr[idx]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        
        set<vector<int>>ans;
        
        func(0,arr,ans);
        
        vector<vector<int>>res(ans.begin(),ans.end());
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;
        vector<int> arr(n);
        
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];

        Solution ob;
        vector<vector<int>> res = ob.uniquePerms(arr,n);
        for(int i=0; i<res.size(); i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends