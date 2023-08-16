//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *nums, int n, int k)
    {
        vector<int>ans;
        deque<int>dq;

        for(int i=0;i<n;i++){

            //check if deque is non empty and has correct window element (ex when i=4 window should (2,3,4) so if it has 1 it is out of bound and needs to be removed)
            if(!dq.empty() && dq.front()==(i-k)){
                dq.pop_front();
            }
            //Store indexes of elements in decreasing order
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }
            //Store index of currently brough element 
            dq.push_back(i);

            //Whenever a specific window size if meet , then after every iteration we push deques front element into ans array
            //Atleast when index goes ahead of 2, in zero based indexing so atleast window has traversed 3 elements
            if(i>=k-1){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends