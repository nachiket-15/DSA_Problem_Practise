//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        //solution referred
        
        //Basically we first handle the initial sequences as the base cases
        if(n==1)return "1";
        if(n==2)return "11";
        
        //Then we start with string as "11"
        string s="11";
        
        //Then we start iterating from i=3 till end
        for(int i=3;i<=n;i++){
            //We initialized count
            int cnt=1;
            //We keep this character so that , we will be able to compare last character(see above - loop goes till n)
            s=s+"&";
            //Declare a temporary string 't'
            string t="";
            
            //As we have to compare adjacent back elements , we start iterating over string s from 1
            for(int i=1;i<s.length();i++){
                if(s[i]!=s[i-1]){
                    //Insert the count first
                    t=t+to_string(cnt);
                    //Then put original number
                    t=t+s[i-1];
                    //Reset the count
                    cnt=1;
                }else{
                    //Increment the count
                    cnt++;
                }
            }
            s=t;
        }
        
        return s;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends