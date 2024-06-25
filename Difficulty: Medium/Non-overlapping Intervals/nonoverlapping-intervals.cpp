//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    static bool comparator(vector<int>&a,vector<int>&b)
    {
        //sort array in ascending order in terms of end time
        return a[1]<b[1];
    }
    int minRemoval(int N, vector<vector<int>> &intervals) 
    {
        // there is a problem named N meeting in one room 
        // there we were scheduling max no of meetings that can be possible in one room
        // here problem is reverse
        
        //here u will remove overlapping meeting
        // just get count of max meetings that can be done , subtract it from total meeting 
        
        sort(intervals.begin(),intervals.end(),comparator);
        
        int lastMeetEnd=intervals[0][1];
        int cnt=0;
        
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0]>=lastMeetEnd)
            {
                lastMeetEnd=intervals[i][1];
            }else{
                cnt++;
            }
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(N, intervals) << endl;
    }
    return 0;
}
// } Driver Code Ends