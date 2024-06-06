//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        //Sol ref
        
        //See the approach that we are going to follow is 
        //We will iterate from last searching for an odd element 
        //Moment we get it , we will stop iterating and 
        //We will return string from first to that index 
        
        //Obv it is the largest odd no string
        int idx=-1;
        
        for(int i=s.length()-1 ;i>=0;i--)
        {
            if((s[i]-'0')%2)
            {
                idx=i;
                break;
            }
        }
        
        string ans="";
        if(idx!=-1){
            ans=s.substr(0,idx+1);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends