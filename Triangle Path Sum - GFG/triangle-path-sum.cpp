//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int minimizeSum(int n, vector<vector<int>>& triangle) {
        //Memoization done on leetcode
        //By Tabulation as Memoization might give TLE
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        //Base case conversion in Tabulation(which is bottom up approach)
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        
        //For other cases in Tabulation - Down and Diagonal Movements
        //We need to start from second last row
        for(int i=n-2;i>=0;i--){
            //As They are Triangular matrix
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int diagonal=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,diagonal);
            }
        }
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minimizeSum(n, triangle) << "\n";
    }
    return 0;
}
// } Driver Code Ends