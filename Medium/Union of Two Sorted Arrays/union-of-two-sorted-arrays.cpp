//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
         vector<int>ans;
        
        for(int i=0;i<n;i++){
            ans.push_back(arr1[i]);
        }
        
        for(int i=0;i<m;i++){
            ans.push_back(arr2[i]);
        }
        
        int i=0;
        
        sort(ans.begin(),ans.end());
        for(int j=1;j<m+n;j++){
            if(ans[j]!=ans[i]){
                i++;
            }
            ans[i]=ans[j];
        }
        
        int decide=(m+n)-i-1;
        // cout<<decide;
        for(int i=0;i<decide;i++){
            ans.pop_back();
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends