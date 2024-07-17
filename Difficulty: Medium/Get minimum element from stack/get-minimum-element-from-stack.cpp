//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minTillNow;
    stack<pair<int,int>> st;
    public:
    
       /*returns min element from stack*/
       int getMin(){
            if(st.empty()) {
                return -1;
            }
            return st.top().second;  
       }
       
       /*returns poped element from stack*/
       int pop(){
            if(st.empty()) {
                return -1;
            }
            int poppedElement = st.top().first;
            st.pop();
            if (!st.empty()) {
                minTillNow = st.top().second;
            } else {
                minTillNow = INT_MAX; // or some default value indicating an empty stack
            }
            return poppedElement;
       }
       
       /*push element x into the stack*/
       void push(int x){
            
            if(st.empty())
            {
                minTillNow=x;
                st.push({x,x});
            }
            else{
                minTillNow=min(minTillNow,x);
                st.push({x,minTillNow});
            }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends