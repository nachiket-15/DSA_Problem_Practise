//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // brute force n^2 is easy , just traverse each element 
        //in matrix and update the count
        
        //try to observe pattern in the matrix
        //for n as 4 , 5 is occurring most frequent
        //for n as 5 , 6 is occurring most frequent
        
        long long mostFreqElement=n+1;
        
        //in the matrix it is seen from end of first row , towards 
        //diagonal in opposite direction 
        
        //its frequency is n
        
        if(q>(2*n))
        {
            return 0;
        }
        
        return n-(abs(q-mostFreqElement));
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n,q;
        
        cin>>n>>q;

        Solution ob;
        cout << ob.sumMatrix(n,q) << endl;
    }
    return 0;
}
// } Driver Code Ends