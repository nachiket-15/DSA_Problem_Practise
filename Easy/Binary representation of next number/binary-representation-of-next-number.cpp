//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        int n = s.length();

    // Start from the last character and find the first '0' from the end
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            // Change this '0' to '1' and make all bits after it '0'
            s[i] = '1';
            fill(s.begin() + i + 1, s.end(), '0');
            
            // Remove leading zeros
            s.erase(0, s.find_first_not_of('0'));
            return s;
        }
    }

    // If we did not find any '0', it means the number was all '1's
    // In this case, we need to add an extra '1' at the beginning
    // and make the rest '0's
    s = "1" + string(n, '0');

    // Remove leading zeros (though there shouldn't be any in this case)
    s.erase(0, s.find_first_not_of('0'));
    return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends