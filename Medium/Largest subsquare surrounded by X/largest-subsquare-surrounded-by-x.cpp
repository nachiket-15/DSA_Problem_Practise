//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
         vector<vector<int>> vertical(n+1,vector<int>(n+1,0));
        vector<vector<int>> horizontal(n+1,vector<int>(n+1,0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(a[i][j] == 'X') {
                    vertical[i+1][j+1] = vertical[i][j+1] + 1;
                    horizontal[i+1][j+1] = horizontal[i+1][j] + 1;
                }
            }
        }
        
        int largestSquare = 0;
        
        for(int i = n; i > largestSquare; i--) {
            for(int j = n; j > largestSquare; j--) {
                if(vertical[i][j] == 0 || horizontal[i][j] == 0) {
                    continue;
                }
                
                int biggestSquarePossible = min(vertical[i][j], horizontal[i][j]);
                
                while(biggestSquarePossible > largestSquare) {
                    if(vertical[i][j-biggestSquarePossible+1] >= biggestSquarePossible){
                        if(horizontal[i - biggestSquarePossible+1][j] >= biggestSquarePossible) {
                            largestSquare = biggestSquarePossible;
                            break;
                        }
                    }
                    biggestSquarePossible--;
                }
            }
        }
        
        return largestSquare;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends