//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    int max1=arr[0];
	    int max2=-1;
	     
	    for(int i=0;i<n;i++){
	        //General case 
	        if(arr[i]>max1){
	            max2=max1;
	            max1=arr[i];
	        }
	        //Imp case as array is not sorted
	        else if(arr[i]<max1 && arr[i]>max2){
	            max2=arr[i];
	        }
	        
	    }
	    
	    return max2;
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
        auto ans = ob.print2largest(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends