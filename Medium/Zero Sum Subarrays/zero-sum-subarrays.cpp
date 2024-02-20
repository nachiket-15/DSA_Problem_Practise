//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        //Solution referred
        
        long long int cnt=0,prefix_sum=0;
        
        unordered_map<long long int,long long int>freq;
        
        for(auto num:arr){
            prefix_sum+=num;
            
            if(prefix_sum==0){
                cnt++;
            }
            
            freq[prefix_sum]++;
        }
        
        for(auto it:freq){
            cnt+=(it.second*(it.second-1))/2;
        }
        
        return cnt;
    }
    /*
Here is my observation:
Index               { 0,   1,  2,  3,  4,   5,  6,  7}
If the array is     { 5,  -2,  2,  3,  -3,  1,  2, -2}
so the prefix sum array will be  { 5,   3,  5,  8,   5,  6,  8,  6}

Now there is a zero-sum subarray from index 3 to 4, {-2, 2}. 
So the prefix sum of index 2 is repeated at index  4.
The same thing is happening for sub-array 
{3,  -3} and {-2,  2,  3,  -3}.

So we can say that if the prefix sum at index l repeats at index r,
there is a zero-sum subarray from l+1 to r.

How to count the sub-arrays.

Now for a prefix sum [ prefix_sum[i] ],
if the count is 2 then there is 1 zero-sum subarray
if the count is 3 then there is 3 zero-sum subarray
if the count is 4 then there is 6 zero-sum subarray
if the count is n then there is nC2 = (n*(n-1))/2 zero-sum subarray

for the given array
count of presum value 5 is 3, so the ans is (3*2)/2=3,
count of presum value 8 is 2, so the ans is 3+(2*1)/2 = 3+1 = 4
count of presum value 6 is 2, so the ans is 4+(2*1)/2 = 4+1 = 5



 */
};


//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends