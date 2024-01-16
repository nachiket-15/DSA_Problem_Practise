//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int function(int n,int m)
    {
        //If you have reached the end , i.e. till max element 
        //You will add up the count 
        
        //As we will go top down , condition reverses 
        if(n==0)return 1;
        
        //If length of individual seq ends , we add up 0
        
        if(m==0)return 0;
        
        int pick=function(n-1,m/2);
        int notPick=function(n,m-1);
        
        return pick+notPick;
    }
    int numberSequence(int m, int n){
        
        //Required space complexity is O(1)
        //Also Q can't be solved without using Recursion
        
        //m is number up to which generated sequence's max element can go 
        //n is length of individual sequence
        return function(n,m);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends