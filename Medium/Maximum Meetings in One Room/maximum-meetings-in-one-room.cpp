//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool comparator(vector<int>&a,vector<int>&b) {
        if(a[1]!=b[1])
            return a[1] < b[1];
        else
            return a[2] < b[2];
    }

vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F){
    //Solution referred
    
    vector<vector<int>>meetings;
    
    for(int i=0;i<N;i++)
    {
        //Start,finish,Meeting No
        meetings.push_back({S[i],F[i],i+1});
        //Reason behind storing the meeting no is that 
        //When we will sort them on basis of finish time 
        //We will lose their track and sequence that we have to return 
        //in final ans 
        
        //So meeting no is helpful in pushing in final ans
    }
    
    sort(meetings.begin(),meetings.end(),comparator);
    
    vector<int>ans;
    ans.push_back(meetings[0][2]);
    
    int endOfPrev=meetings[0][1];
    
    for(int i=1;i<N;i++){
        int startOfCurrent=meetings[i][0];
        
        if(startOfCurrent > endOfPrev){
            ans.push_back(meetings[i][2]);
            endOfPrev=meetings[i][1];
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends