//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // The idea is to increment the platform count when a 
        // train arrives and decrement the platform count when 
        // a train departs.
        
        sort(arr,arr+n);
        sort(dep,dep+n);
        
        int maxPlatforms=1;
        int platformsReq=1;
        
        int i=1;
        int j=0;
        
        // i will track arrival
        // j will track departure
        
        while(i<n && j<n)
        {
            // if its arrival of new train
            int arrivalTimeofNextTrain=arr[i];
            int depTimeofCurrTrain=dep[j];
            
            if(arrivalTimeofNextTrain <= depTimeofCurrTrain)
            {
                // new train came before older ones leave
                // we will require new platforms
                platformsReq++;
                i++;
            }else{
                // older trains leave
                platformsReq--;
                j++;
            }
            
            if(platformsReq>maxPlatforms)
            {
                maxPlatforms=platformsReq;
            }
            
        }
        
        return maxPlatforms;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends