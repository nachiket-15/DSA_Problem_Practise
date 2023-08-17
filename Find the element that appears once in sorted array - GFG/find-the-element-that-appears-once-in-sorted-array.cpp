//{ Driver Code Starts
// Driver code

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  public:
    int findOnce(int arr[], int n)
    {
        /* My approach - O(N)
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[arr[i]]++;
        }
        int ans;
        for(auto x:map){
            if(x.second==1)ans=x.first;
        }
        return ans;*/
        
        //Try using binary search as array is given sorted 
        
        //check for edge cases in advance 
        int l=0,h=n-1;
        // if(n==1) return arr[0];
        // if(arr[0]!=arr[1]) return arr[0];
        // if(arr[n-1]!=arr[n-2]) return arr[n-1];
        
        while(l<=h){
            int mid=(l+h)>>1;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];
            if(arr[mid]==arr[mid-1]){
                int left_count=mid-l+1;
                if(left_count%2==0){
                    l=mid+1;
                }
                else h=mid-2;
            }
            if(arr[mid]==arr[mid+1]){
                int right_count=h-mid+1;
                if(right_count%2==0) h=mid-1;
                else l=mid+2;
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int A[n];
        for(int i = 0;i < n;i++)
        {
            cin>>A[i];
        }
        
        Solution ob;
        
        int res = ob.findOnce(A,n);
        cout << res << endl;
    }
    
    return 0;
}
// } Driver Code Ends