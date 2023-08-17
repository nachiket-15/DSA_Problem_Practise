//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends




pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    //Solution referred but understood now
    pair<int,int>p(-1,-1);
    sort(arr,arr+n);
    int high=n-1;
    int low=0;
    
    while(low<=high){
        int mid=(low+high)/2;
        
        if(arr[mid]==x){
            p.first=arr[mid];
            p.second=arr[mid];
            return p;
        }
        
        else if(arr[mid]<x){
            //updating floor
            p.first=arr[mid];
            low=mid+1;
        }
        else {
            //updating ceil
            p.second=arr[mid];
            high=mid-1;
        }
    }
    return p;
}