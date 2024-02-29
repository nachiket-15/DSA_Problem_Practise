//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	long long sumBitDifferences(int arr[], int n) {
	    long long ans = 0;
	   
	    for(int i = 0;i<32;i++){
	       
	       long long set_bits_cnt = 0;
	       
	       for(int j = 0;j<n;j++){
	           // at each position find the set bit
	           if(arr[j]&(1<<i))set_bits_cnt++;
	       }
	       long long unset_bits_cnt=n-set_bits_cnt;
	       
	       //This is formula for no of different bits(x,y) & (y,x)
	       ans+=set_bits_cnt*unset_bits_cnt*2;
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
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.sumBitDifferences(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends