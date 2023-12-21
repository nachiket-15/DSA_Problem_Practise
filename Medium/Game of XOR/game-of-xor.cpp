//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int gameOfXor(int N, int A[]) {
    /*
    // Initialize ans to 0
    int ans = 0;

    // Generate all subarrays, store their xors in an array
    vector<int> xorStore;

    for (int i = 0; i < N; i++) {
        int res = 0; // Initialize res to 0 outside the inner loop
        for (int j = i; j < N; j++) {
            res = res ^ A[j];
            xorStore.push_back(res);
        }
    }

    // Calculate the final XOR value
    for (int i = 0; i < xorStore.size(); i++)
        ans = ans ^ xorStore[i];

    return ans;
    */
    
    
    /*
    Optimized logic 
    The core concept is rooted in the observation that if the array size 
    is even, the XOR sum of all subarrays will be 0. This is due to 
    the symmetrical nature of XOR operations.
 
    For an odd-sized array, we iterate through the array using 
    a step of 2, accessing elements at odd indices. We perform bitwise 
    XOR on these elements, accumulating the XOR sum. The final 
    result is the bitwise XOR of values at odd indices.
    
    */
    
    if(N%2==0)return 0;
    
    int ans=0;
    
    for(int i=0;i<N;i=i+2){
        ans=ans^A[i];
    }
    
    return ans;
}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends