//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        string y="Yes",no="No";
        
        int sum=0;
        int temp=n;
        
        while(temp)
        {
            int single=temp%10;
            sum+=(single*single*single);
            temp=temp/10;
        }
        
        return sum==n?y:no;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends