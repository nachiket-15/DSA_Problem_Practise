//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<vector<int>> insertNewEvent(int N, vector<vector<int>> &intervals, vector<int> &newEvent) {
        //result variable
        vector<vector<int>>result;
        
        int index=0;
        
        //first find all the elements which fall left of all those
        //which overlap
        
        // intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]]
        // newEvent  = [5,10]
        
        // above [1,2] is left of all those who atleast overlap
        // [3,5] has overlap as new interval just starts at 5
        // [12,16] are to right of all those who overlaps
        
        // deal with left part
        
        while(index<N && intervals[index][1] < newEvent[0])
        {
            result.push_back({intervals[index][0],intervals[index][1]});
            index++;
        }
        
        // deal with overlapping part
        
        
        while(index<N && intervals[index][0]<=newEvent[1])
        {
            newEvent[0]=min(newEvent[0],intervals[index][0]);
            newEvent[1]=max(newEvent[1],intervals[index][1]);
            index++;
        }
        
        result.push_back({newEvent[0],newEvent[1]});
        
        while(index<N)
        {
            result.push_back({intervals[index][0],intervals[index][1]});
            index++;
        }
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> intervals(N,vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0]>>intervals[i][1];
        }
        vector<int> newEvent(2);
        cin>>newEvent[0]>>newEvent[1];
        
        Solution obj;
        vector<vector<int>> ans = obj.insertNewEvent(N, intervals,newEvent);
        cout<<"[";
        for(int i=0;i<ans.size();i++){
            cout<<"["<<ans[i][0]<<','<<ans[i][1]<<']';
            if(i!=(ans.size()-1)) cout<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}
// } Driver Code Ends