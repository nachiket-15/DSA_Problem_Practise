//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        //Simple bfs traversal yields ans
        
        queue<pair<int,pair<int,int>>>q;
        //dist,(src_x,src_y)
        q.push({0,{0,0}});
        
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        
        while(!q.empty())
        {
            int distance=q.front().first;
            int row=q.front().second.first;
            int col=q.front().second.second;
            q.pop();
            
            if(row==X && col==Y)return distance;
            
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                
                if(nrow<N && nrow>=0 && ncol<M &&ncol>=0 &&A[nrow][ncol]==1){
                    q.push({distance+1,{nrow,ncol}});
                    A[nrow][ncol]=0;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends