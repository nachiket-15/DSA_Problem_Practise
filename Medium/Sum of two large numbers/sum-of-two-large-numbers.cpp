//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // long func(string X)
    // {
    //     int ans=0;
        
    //     for(char s:X)
    //     {
    //         ans=ans*10+s-'0';
    //     }
    //     return ans;
    // }
    string findSum(string X, string Y) {
        //Brute force gives tle
        // long x=func(X);
        // long y=func(Y);
        // return to_string(x+y);
        
        
        //optimized approach - solution referred
         string ans="";
         
         int i=X.size()-1;
         int j=Y.size()-1;
         
         int carry=0;
         while(i>=0&&j>=0){
             
             int sum=(X[i]-'0')+(Y[j]-'0')+carry;
             ans+=sum%10+'0';
             carry=sum/10;
             i--;
             j--;
         }
         while(i>=0){
             int sum=(X[i]-'0')+carry;
             ans+=sum%10+'0';
             carry=sum/10;
             i--;
         }
         while(j>=0){
             int sum=(Y[j]-'0')+carry;
             ans+=sum%10+'0';
             carry=sum/10;
             j--;
         }
          
          if(carry!=0){
              
              ans+=carry+'0';
             
          }
          
         reverse(ans.begin(),ans.end());
         
       while(ans[0]=='0'){
            ans.erase(0,1);
        }
        if(ans=="") return "0";
        return ans;
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
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";
    }

    return 0;
}
// } Driver Code Ends