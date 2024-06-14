//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int count_of_subarray_with_sum_less_than_equal_to_target(vector<int>arr,int target)
    {
        if(target<0)return 0;
        
        int left=0;
        int right=0;
        int cnt=0;
        int sum=0;
        int n=arr.size();
        
        while(right<n)
        {
            sum+=arr[right];
            
            while(sum>target)
            {
                sum-=arr[left];
                left++;
            }
            
            cnt+=(right-left+1);
            right++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& arr, int N, int target){
        return count_of_subarray_with_sum_less_than_equal_to_target(arr,target)-count_of_subarray_with_sum_less_than_equal_to_target(arr,target-1);
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
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends