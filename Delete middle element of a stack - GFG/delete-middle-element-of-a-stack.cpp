//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        vector<int>v;
        
        for(int i=0;i<sizeOfStack;i++){
            v.push_back(s.top());
            s.pop();
        }
        
        int n=v.size()/2 ;
        // cout<<v[n]<<" ";
        v.erase(v.begin()+n);
        
        // for(int j=0;j<v.size();j++)cout<<v[j]<<" ";
        for(int j=v.size()-1 ;j>=0;j--){
            s.push(v[j]);
        }
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}

// } Driver Code Ends