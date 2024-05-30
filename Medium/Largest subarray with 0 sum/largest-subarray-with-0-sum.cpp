//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int>map;
        
        int sum=0;
        int k=0;
        int maxlen=0;
        
        for(int i=0;i<n;i++){
            
            sum+=A[i];
            
            if(sum==k){
                maxlen=i+1;
            }
            //If not any entry regarding current prefixSum in map 
            //then make one
            
            if(map.find(sum)==map.end()){
                map[sum]=i;
            }
            
            //If you already have any entry , then compare whether 
            //current maxLen is greater or already stored one
            //Update accordingly
            
            if(map.find(sum-k)!=map.end()){
                if(maxlen<i-map[sum-k]){
                    maxlen=i-map[sum-k];
                }
            }
        }
        return maxlen;
    }
};




//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends