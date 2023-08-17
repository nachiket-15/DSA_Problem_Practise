//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findMax(vector<int>piles){
        int n=piles.size();
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(piles[i],ans);
        }
        return ans;
    }
    int total_hours(vector<int>piles,int d){
        int sum=0;
        for(int i=0;i<piles.size();i++){
            sum+=(ceil(double(piles[i])/double(d)));
        }
        return sum;
    }
    int Solve(int N, vector<int>& piles, int H) {
        int low=1;
        int high=findMax(piles);
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            int totalH=total_hours(piles,mid);
            
            if(totalH<=H){
                high=mid-1;
                ans=mid;
            }
            else 
                low=mid+1;
            
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
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends