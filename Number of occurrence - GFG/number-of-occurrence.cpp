//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int lowerBound(int *arr,int n,int x){
	    
	    int ans=n;
	    int low=0;
	    int high=n-1;
	    
	    while(low<=high){
	        int mid=(low+high)/2;
	            
	        if(arr[mid]>=x){
	            ans=mid;
	            high=mid-1;
	        }else{
	            low=mid+1;
	        }
	    }
	    return ans;
	}
	int upperBound(int *arr,int n,int x){
	    
	    int ans=n;
	    int low=0;
	    int high=n-1;
	    
	    while(low<=high){
	        int mid=(low+high)/2;
	            
	        if(arr[mid]>x){
	            ans=mid;
	            high=mid-1;
	        }else{
	            low=mid+1;
	        }
	    }
	    return ans;
	}
	int count(int arr[], int n, int x) {
	    //Done on own today
	    int lb=lowerBound(arr,n,x);
	    int ub=upperBound(arr,n,x);
	    
	    if(lb==n){
	        return 0;
	    }
	    
	    return ub-lb;
	}
};

//{ Driver Code Starts.

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
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends