//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    int maxOnes(int a[], int n)
    {
        int curr_sum = 0, count_one = 0, max_sum = 0;
        for (int i = 0; i < n; i++){
            if (a[i] == 1)
                count_one++;
            if(a[i]==0){
                a[i]=1;
            }
            else{
                a[i]=-1;
            }
            
            curr_sum+=a[i];
            max_sum = max(max_sum,curr_sum);
            
            if (curr_sum < 0)
                curr_sum = 0;
        }
        return max_sum+count_one;
    }
};
// if we have arr[5] = [1 0 0 1 0] 
// if we change 0 -> 1 and 1 -> -1 so, arr[5] would be -> [-1,1,1,-1,1];
// then apply the kadane's algo or finding the maxSum in modifyed array then 
// it gives 2 and In original arr has 2 ones 
// so, if we add the kadane's answer and count_ones so it is the anwere of Flip Bits
// so, for this input the answer is 2 + 2 = 4 ans.

//{ Driver Code Starts.
int main()
{
    int t; cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n+5];
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        cout<< ob.maxOnes(a, n) <<endl;
    }
    return 0;
}

// } Driver Code Ends