//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        //this approach seems easy
        map<char,char>m1;
        map<char,char>m2;
        
        int n = str1.size();
        int m = str2.size();
        
        int i;
        
        for(i=0;i<n;i++)
        {
            m1.insert({str2[i],str1[i]});
            m2.insert({str1[i],str2[i]});
        }
        
        string s1="",s2="";
        for(i=0;i<n;i++)
        {
            s1+=m1[str2[i]];
            s2+=m2[str1[i]];
        }
        
        if(s1==str1 && s2==str2)
        {
            return true;
        }
        
        return false;
        
    }
        
    
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends