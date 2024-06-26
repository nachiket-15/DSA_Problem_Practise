//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        // normal element (i,j)
        // up is (i-1,j)
        // right is (i,j+1)
        // left is (i,j-1)
        // down is (i+1,j)
        
        int coverageCnt=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    // up
                    
                    if(i-1>=0)
                    {
                        if(matrix[i-1][j]==1)
                        {
                            coverageCnt++;
                        }
                    }
                    // down
                    if(i+1<n)
                    {
                        if(matrix[i+1][j]==1)
                        {
                            coverageCnt++;
                        }
                    }
                    // left
                    if(j-1>=0)
                    {
                        if(matrix[i][j-1]==1)
                        {
                            coverageCnt++;
                        }
                    }
                    // right
                    if(j+1<m)
                    {
                        if(matrix[i][j+1]==1)
                        {
                            coverageCnt++;
                        }
                    }
                }
            }
        }
        return coverageCnt;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends