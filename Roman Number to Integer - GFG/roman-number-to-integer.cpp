//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        map<char,int>decode;
        decode.insert({'I',1});
        decode.insert({'V',5});
        decode.insert({'X',10});
        decode.insert({'L',50});
        decode.insert({'C',100});
        decode.insert({'D',500});
        decode.insert({'M',1000});
        int sum=0;
        
        for(int i=0;i<str.length();i++){
            if(decode[str[i]]<decode[str[i+1]]){
                sum+=decode[str[i+1]]-decode[str[i]];
                i++;
            }
            else{
                sum+=decode[str[i]];
            }
        }
        return sum;
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
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends