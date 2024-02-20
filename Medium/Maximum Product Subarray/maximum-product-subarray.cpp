//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
#include<bits/stdc++.h>
class Solution{
public:
    /*
	    //Atleast you should be able to come up with brute force approach
	    vector<long long>maxProduct;
	    //Generate all subarrays first
	    for(int i=0;i<n;i++){
	        for(int j=i;j<n;j++){
	            //Instead of subarray, finding product
	            long long prod=1;
	            for(int k=i;k<=j;k++){
	               // if(arr[k]==0 && n>1)continue;
	                prod=prod*arr[k];
	                maxProduct.push_back(prod);
	            }
	        }
	    }
	    
	    long long ans=0;
	    for(auto n:maxProduct)if(n>ans)ans=n;
	    
	    if(maxProduct.size()==1)return maxProduct[0];
	    
	    return ans;
	    */
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    //Efficient approach
	    long long ans=-1e9;
	    long long product=1;
	    
	    //We will traverse from front first
	    for(int i=0;i<n;i++){
	        product*=arr[i];
	        ans=max(ans,product);
	        //Whenever 0 is encountered make product one so that 
	        //we can start multiplication from next element for next subarray
	        if(arr[i]==0)product=1;
	    }
	    product=1;
	    //Traverse from behind
	    for(int i=n-1;i>=0;i--){
	        product*=arr[i];
	        ans=max(ans,product);
	        //Whenever 0 is encountered make product one so that 
	        //we can start multiplication from next element for next subarray
	        if(arr[i]==0)product=1;
	    }
	    return ans;
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends