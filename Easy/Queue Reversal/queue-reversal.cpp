//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        int n=q.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            int m=q.front();
            q.pop();
            st.push(m);
        }
        
        for(int i=0;i<n;i++){
            int m=st.top();
            st.pop();
            q.push(m);
        }
        
        
        
        return q;
    }
};



//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends