//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        if(N<=1)return 0;
        
        long long sum=1;
        int sqrtN=sqrt(N);
        
        for(int i=2;i<=sqrtN;i++){
            if(N%i==0 ){
                sum+=i;
                sum+=(N/i);
            }
        }
        
        return sum==N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends