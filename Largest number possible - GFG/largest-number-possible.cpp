//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        string res="";
       if(S==0&&N!=1)
       return to_string(-1);
       while(res.size()!=N)
       {
           if(S)
           {
                if(S<9){
                res.push_back('0'+S);
                S=0;
                }
                else
                {
                    res.push_back(0+'9');
                    S-=9;
                }
                
                
           }
           else
           res.push_back('0');
       }
       if(S!=0)
       return to_string(-1);
       return res;
    
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends