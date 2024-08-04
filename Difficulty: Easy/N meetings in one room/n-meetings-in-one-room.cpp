//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    struct meeting{
        int start;
        int end;
        int pos;
    };
    
    static bool comparator(struct meeting m1,meeting m2){
        //sort by meeting end time
        if(m1.end<m2.end)return true;
        if(m1.end>m2.end)return false;
        // if meeting end time was same , sort by position
        if(m1.pos<m2.pos)return true;
        else return false;
    }
    
    int maxMeetings(int n,int start[], int end[])
    {
        // Create array of structure meeting
        meeting meet[n];
        
        for(int i=0;i<n;i++){
            meet[i].start=start[i];
            meet[i].end=end[i];
            meet[i].pos=i+1;
        }
        
        //Now we will sort meet array based on end time
        sort(meet,meet+n,comparator);
        
        //Create an answer vector
        int ans=0;
        int lastMeetEndTime=meet[0].end;
        
        for(int i=1;i<n;i++){
            if(meet[i].start>lastMeetEndTime){
                lastMeetEndTime=meet[i].end;
                ans++;
            }
        }
        
        return ans+1;
    }
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++)
            cin >> start[i];

        for (int i = 0; i < n; i++)
            cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(n, start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends