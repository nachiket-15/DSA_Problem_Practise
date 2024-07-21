//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int mod=(1e9+7);
    long long int findMaxProduct(vector<int>& arr) 
    {
        int n=arr.size();
        long long int product=1;
        int maxi=-1e9;
        int zero=0;
        int negative=0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                zero++;
                continue;
            }
            else if(arr[i]<0)
            {
                negative++;
                maxi=max(maxi,arr[i]);
            }
            long long int curr=arr[i];
            product=(product*curr)%mod;
        }
        
        
        
        if(zero==1 && negative==1 && n==2)return 0;
        
        
        
        if(product<0)return product/maxi;
        
        return product;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends