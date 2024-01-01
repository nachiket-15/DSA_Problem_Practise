//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int f(int day,int last,vector<vector<int>>&dp,vector<vector<int>> &points)
{
    //BASE CASE
    if(day==0){
        int maxi=0;
        for(int i=0;i<=2;i++){
            if(i!=last){
                maxi=max(points[0][i],maxi);}
        }
        return dp[day][last]=maxi;
    }
    if(dp[day][last]!=-1){
        return dp[day][last];
    }
    int maxi=0;
    for(int i=0;i<=2;i++){
        if (i != last) {
            int activity = points[day][i] + f(day - 1, i, dp, points);
            maxi = max(activity, maxi);
        }
    }
    return dp[day][last]=maxi;
}
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>>dp(n,vector<int>(4,-1));
        //Reason behind creating a dp of n*4 instead of n*3 is that
        //In first call , before starting we are saying last as 3 
        //Which is imaginary , as we dont want any condition of last 
        //While picking first task 
        
        //See below function call
        return f(n-1,3,dp,points);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends