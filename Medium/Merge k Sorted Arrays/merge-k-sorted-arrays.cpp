//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

typedef pair<int,pair<int,int>> triplet;
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<triplet,vector<triplet>,greater<triplet>>pq;
        
        //Store first element from each array
        for(int i=0;i<arr.size();i++)
            pq.push({arr[i][0],{i,0}});
        
        vector<int>ans;
        
        //Now Iterate with storing next elements
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            
            int data=it.first;
            int row=it.second.first;
            int col=it.second.second;
            
            ans.push_back(data);
            if(col+1<K)
            {
                pq.push({arr[row][col+1],{row,col+1}});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends