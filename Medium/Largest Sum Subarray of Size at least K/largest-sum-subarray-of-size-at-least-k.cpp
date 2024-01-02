//{ Driver Code Starts
// C++ program to find largest subarray sum with
// at-least k elements in it.
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:    
    #define ll long long int
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        //problem is asking us for atleast k sized subarray 
        //So acc to second Ex Testcase , subarray can be equal k size or more too
        
        
        //Requires to implement sliding window approach
        ll ans=LONG_MIN;
        ll sum=0;
        ll prevSum=0;
        
        //First compute sum for 1st k sized window
        for(int i=0;i<k;i++)
            sum+=a[i];
            
        ans=max(sum,ans);
        
        //Intuition here is , keep a variable that calculates previous 
        //Sum while iterating from k 
        //If prevSum is negative , We have to remove it from our sum variable 
        //As it contains it & negative no in sum kuch kam ka nahi
        int j=0;
        
        for(int i=k;i<n;i++)
        {
            sum+=a[i];
            ans=max(ans,sum);
            prevSum+=a[j++];
            
            if(prevSum<0)
            {
                //Remove it from sum variable
                sum=sum-prevSum;
                //Initialize it to zero as its removed from current sum
                prevSum=0;
                //Check for maximum ans
                ans=max(ans,sum);
            }
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    long long int t;
    cin >> t;
    while (t--) {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> k;
        Solution ob;
        cout << ob.maxSumWithK(a, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends