//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int maxi=arr[n-1];
        int mini=arr[0];
        
        int res=maxi-mini;
        
        for(int i=0;i<n;i++)
        {
            //consider there is a boundary after ith element
            
            mini = min(arr[0] + k, arr[i+1] - k);//lets minimize right side of boundary by subtracting k from it 
            maxi = max(arr[i] + k, arr[n-1] - k);//lets maximize left side of boundary by adding k in it
            //maxizing left side of array and minimizing right portion of array only will help us to find minimum diff
            res=min(res,maxi-mini);
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends