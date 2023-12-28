//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void convertMinToMaxHeap(vector<int> &arr, int N){
        //Nothing fancy , Just MaxHeapify each element from array
        
        //Start from non leaf nodes
        for(int i=(N/2-1);i>=0;i--)
            maxHeapify(arr,i,N);
    }
    void maxHeapify(vector<int>&arr,int index,int n)
    {
        int lc=2*index+1;
        int rc=2*index+2;
        int largest=index;
        
        if(lc < n && arr[lc] > arr[largest])
            largest=lc;
        if(rc < n && arr[rc] > arr[largest])
            largest=rc;
            
        if(largest!=index)
        {
            swap(arr[largest],arr[index]);
            maxHeapify(arr,largest,n);
        }
    }
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends