//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int findMax(int *arr,int n){
        int ans=arr[0];
        for(int i=1;i<n;i++)ans=max(ans,arr[i]);
        
        return ans;
    }
    int findSum(int *arr,int n){
        int sum=0;
        for(int i=0;i<n;i++)sum+=arr[i];
        
        return sum;
    }
    
    int funcToFindLeastDays(int *arr,int n,int currentLeastWt){
        int days=1;
        int load=0;
        
        for(int i=0;i<n;i++){
            if(arr[i]+load > currentLeastWt){
                load=arr[i];
                days++;
            }
            else {
                load+=arr[i];
            }
        }
        return days;
    }
    int leastWeightCapacity(int arr[], int N, int D) {
        int low=findMax(arr,N);
        int high=findSum(arr,N);
        int ans=-1;
        while(low<=high){
            //Mid will act as least weight capacity
            int mid=(low+high)/2;
            int leastDays=funcToFindLeastDays(arr,N,mid);
            
            if(leastDays<=D){
                ans=mid;
                //jr ka divas shillak rahat astil tr kam kami karu shkto
                high=mid-1;
            }else{
                low=mid+1;
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
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends