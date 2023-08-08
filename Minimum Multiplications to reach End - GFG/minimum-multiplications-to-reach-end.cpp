//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end)return 0;
        
        queue<pair<int,int>>q;//multiplication,dist;
        q.push({start,0});
        
        int mod=1e5;
        
        vector<int>dist(100000,1e9);
        dist[start]=0;
        
        while(!q.empty()){
            int num=q.front().first;
            int cnt=q.front().second;
            q.pop();
            
            for(auto n:arr){
                int adjNode=(num*n)%mod;
                
                if(cnt+1<dist[adjNode]){
                    dist[adjNode]=cnt+1;
                    if(adjNode==end)return cnt+1;
                    q.push({adjNode,cnt+1});
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends