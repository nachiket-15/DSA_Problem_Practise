//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        int idx=0;
        

        
        string temp="";
        
        for(auto it:str)
        {
            if(it!='.')
            {
                temp+=it;
            }else{
                int num=stoi(temp);
                // cout<<"Number is "<<num<<endl;
                if(num>255 || num<0)
                {
                    return 0;
                }
                temp="";
            }
        }
        
        int num=stoi(temp);
        
        // cout<<"Number is "<<num<<endl;
        if(num>255 || num<0)
        {
            return 0;
        }
                
        return 1;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends