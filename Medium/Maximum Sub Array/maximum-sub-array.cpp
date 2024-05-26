//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	vector<int> findSubarray(int arr[], int n) {
	    //solution referred 
	    
	    int start=0;
	    int ansStart=0;
	    int ansEnd=0;
	    int sum=0;
	    int maxSum=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        //if array element is negative
	        if(arr[i]<0)
	        {
	            start=i+1;
	            sum=0;
	        }
	        else{
	            sum=sum+arr[i];
	            if(sum>maxSum)
	            {
	                maxSum=sum;
	                ansStart=start;
	                ansEnd=i;
	            }else if(sum==maxSum)
	            {
	                if((i-start)>(ansEnd-ansStart))
	                {
	                    ansStart=start;
	                    ansEnd=i;
	                }
	            }
	        }
	    }
	    
	    
	    vector<int>ans;
	    for(int i=ansStart;i<=ansEnd;i++)
	    {
	        ans.push_back(arr[i]);
	    }
	    
	    return ans;
	}
};


//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends