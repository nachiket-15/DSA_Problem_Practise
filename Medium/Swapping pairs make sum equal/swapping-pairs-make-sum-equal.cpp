//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        sort(b,b+m);
        
        int sum1 = accumulate(a,a+n,0);
        int sum2 = accumulate(b,b+m,0);
        
        int dif = sum1-sum2;
        
        //the statement if(dif & 1) return -1; means:
        //If dif is odd, the function returns -1.
        //If dif is even, the function continues to execute the subsequent code.
        if(dif&1) return -1;
        
        dif/=2;
        
        for(int i=0;i<n;i++){
            int val = a[i]-dif;
            if(binary_search(b,b+m,val)) {return 1;}
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends