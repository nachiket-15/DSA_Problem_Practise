//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        //Keep the store of array
        vector<int>brr=arr;
        //Sort the array
        sort(arr.begin(),arr.end());
        //Store element,corresponding rank
        map<int,int>mp;
        
        int k=1;
        for(int i=0;i<N;i++){
            //If rank of element is not already stored, then only store it
            if(mp[arr[i]]==0){
                mp[arr[i]]=k;
                k++;
            }
        }
        
        vector<int>ans;
        //Push rank in ans vector
        for(int i=0;i<N;i++)ans.push_back(mp[brr[i]]);
        
        return ans;

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
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends