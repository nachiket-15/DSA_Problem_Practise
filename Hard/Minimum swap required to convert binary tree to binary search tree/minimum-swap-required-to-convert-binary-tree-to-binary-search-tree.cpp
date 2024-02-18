//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
  public:
    void inorder(vector<int> A,vector<int> &in,int index){
        if(index>=A.size()) return;
        inorder(A,in,2*index+1);
        in.push_back(A[index]);
        inorder(A,in,2*index+2);
    }
    int minSwaps(vector<int>&A, int n){
        //solution referred
        vector<int> in;
        inorder(A,in,0);
        vector<pair<int,int>> v;
        for(int i =0;i<in.size();i++){
            pair<int,int> ans = make_pair(in[i],i);
            v.push_back(ans);
        };
        sort(v.begin(),v.end());
        int swaps =0;
        
        for(int i =0;i<v.size();i++)
        {
            if(v[i].second==i) continue;
            else{
                swaps++;
                //move it to its correct position acc to inorder to BT (not BST)
                //so that while traversing when u reach there , u won't be doing
                //additional swap cnt
                swap(v[i],v[v[i].second]);
                i--;
            }
        }
        return swaps;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends