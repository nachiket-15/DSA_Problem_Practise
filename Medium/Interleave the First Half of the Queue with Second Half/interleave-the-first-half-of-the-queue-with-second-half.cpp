//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> rearrangeQueue(queue<int> &q){
        //Approach referred , code writing on own
        
        int n=q.size();
        stack<int>st;
        
        int m=0;
        while(m<(n/2))
        {
            st.push(q.front());
            q.pop();
            m++;
        }
        
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        
        m=0;
        while(m<(n/2))
        {
            q.push(q.front());
            q.pop();
            m++;
        }
        
        m=0;
        while(m<(n/2))
        {
            st.push(q.front());
            q.pop();
            m++;
        }
        
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
            q.push(q.front());
            q.pop();
        }
        
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        
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
        
        queue<int> q;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans=ob.rearrangeQueue(q);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
// } Driver Code Ends