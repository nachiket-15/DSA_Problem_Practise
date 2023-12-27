//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        //Solution logic referred , coding on own 
        
        //BFS traversal is used with slight observation of pattern of printing
        //anti diagonal elements 
        
        //Pattern observed is : for an element , push in queue , element in same 
        //row and next column & element in same column and next row
        
        int n=matrix.size();
        
        if(n==0)return {};
        
        vector<int>ans;
        vector<vector<bool>> visited(n, vector<bool> (n, 0));
        
        queue<pair<int,int>>q;
        
        q.push({0,0});
        visited[0][0]=1;
        
        while(!q.empty())
        {
            // int size=q.size();
            // while(size--)
            // {
                auto it=q.front();
                q.pop();
                
                int i=it.first;
                int j=it.second;
                ans.push_back(matrix[i][j]);
                
                if( j+1 < n && visited[i][j+1]==0)
                {
                    visited[i][j+1]=1;
                    q.push({i,j+1});
                }
                if( i+1 < n && visited[i+1][j]==0)
                {
                    visited[i+1][j]=1;
                    q.push({i+1,j});
                }
            // }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends