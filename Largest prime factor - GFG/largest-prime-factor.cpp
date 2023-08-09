//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public: 
    long long int largestPrimeFactor(int N){
        int ans;
        //If even
        while(N%2 == 0)
        {
            ans = 2;
            N /= 2;
        }
        //Means it is odd
        for(int i=3; i<=sqrt(N); i += 2)
        {
            while(N%i == 0)
            {
                ans = i;
                N /= i;
            }
        }
        if(N>2) return N;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends