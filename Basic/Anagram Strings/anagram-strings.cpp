//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int areAnagram(string S1, string S2) {
        // code here
         if(S1.length()!=S2.length()){
            return 0;
        }
        else{
            sort(S1.begin(),S1.end());
            sort(S2.begin(),S2.end());
            if(S1==S2){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S1, S2;
        cin >> S1;
        cin >> S2;
        Solution ob;
        cout << ob.areAnagram(S1, S2) << endl;
    }
    return 0;
}

// } Driver Code Ends