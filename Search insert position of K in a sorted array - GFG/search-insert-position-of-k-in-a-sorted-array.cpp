//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int searchInsertK(vector<int>nums, int N, int k)
    {
        // code here
        //Think of applying lower bound concept , as we insert new element in sorted array
        //So lower bound exactly gives us index of element which is slightly greate than target or target itself
        //Lower bound means floor in sorted array - largest element which is smaller than or equal to X(target)
        int n=N,target=k;
        int low=0;
        // int n=nums.size();
        int high=n-1;
        int ans=n;

        while(low<=high){
            int mid=low+(high-low)/2;

            if(nums[mid]>=target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }return ans;
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
        cin >> N;
        vector<int>Arr(N);
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int k;
        cin>>k;
        Solution obj;
        cout<<obj.searchInsertK(Arr, N, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends