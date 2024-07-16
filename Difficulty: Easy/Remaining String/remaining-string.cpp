//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    string printString(string s, char ch, int count) 
    {
        int start=0;
        int i=0;
        while(i<s.length())
        {
            if(s[i++]==ch)count--;
            
            if(count==0){
                start=i;
                break;
            }
        }
        
        
        string ans="";
        
        if(start==0)return "";
        
        if(start>s.length())return "";
        
        for(int k=start;k<s.length();k++)
        {
            ans+=s[k];
        }
        
        return ans==""?" ":ans;
        
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        char ch;
        int count;

        cin >> s >> ch >> count;
        Solution ob;
        cout << ob.printString(s, ch, count) << "\n";
    }

    return 0;
}
// } Driver Code Ends