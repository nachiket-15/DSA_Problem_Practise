//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        
        int n=str.length();
        int numChars=0;
        
        map<char,int>map;
        
        for(char ch:str)
        {
            if(ch==' ')continue;
            map[ch]=1;
            numChars++;
        }
        int ans=0;
        if (numChars < 26)return 0;
        for(auto x:map)
        {
            ans+=x.second;    
        }
        
        return ans+k>=26;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends