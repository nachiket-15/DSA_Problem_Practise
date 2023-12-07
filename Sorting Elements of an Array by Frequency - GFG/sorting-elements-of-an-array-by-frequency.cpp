//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    
    static bool cmp(pair<int,int>p1,pair<int,int>p2){
        //If freq is same 
        if(p1.first==p2.first){
            return p1.second<p2.second;
        }
        //Whose freq is more should be placed ahead
        return p1.first>p2.first;
    }
        
    vector<int> sortByFreq(int arr[],int n)
    {
        map<int,int>map;
        for(int i=0;i<n;i++)map[arr[i]]++;
        
        //now create an vector
        vector<pair<int,int>>v;
        
        for(auto it:map){
            //Insert frequencies first then element
            v.push_back({it.second,it.first});
        }
        vector<int>ans;
        sort(v.begin(),v.end(),cmp);
        
        //Create resultant vector
        for(int i=0;i<v.size();i++){
            while(v[i].first--){
                ans.push_back(v[i].second);
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
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends