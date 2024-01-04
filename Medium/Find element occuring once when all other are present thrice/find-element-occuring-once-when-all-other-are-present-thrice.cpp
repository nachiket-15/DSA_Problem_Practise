//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        //Solution using Auxiliary space is easy & can be done on own
        //But Solution referred for w/o using aux space
        
        int ans=0;
        for(int i=0;i<=32;i++)
        {
            int x= (1<<i);//takes values 1,2,4,8,16.....till 2^32
            int sum=0;
            //Check for xth bit position for all elements in array
            //in binary form
            
            for(int j=0;j<N;j++)
            {
                if(arr[j] & x){
                    sum++;
                }
            }
            //If sum var is not divisble by 3 , it means this bit is from number which is ans
            if(sum%3)
            {
                ans = ans | x;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends