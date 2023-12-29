//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	    //If string len is not multiple of k , return false
	    if(n%k!=0)
	        return 0;
	        
	    //Create an unordered map (sub-string,freq)
	    unordered_map<string,int>map;
	    
	    //Store all substrings of length k
	    for(int i=0;i<n;i+=k)
	        //substr(start_index,len_of_string_ahead)
	        map[s.substr(i,k)]++;
	    
	    //If already string has all same substrings , its true
	    if(map.size()==1)
	        return 1;
	    //If map contains more than 2 sub-strings , its false 
	    // As we cannot transform it into required string
	    
	    if(map.size()>2)
	        return 0;
	    
	    //Following condition is obsertvation based 
	    //Take examples : abcabcabc,abcdefabc,abcdefghi with k=3
	    if(map.begin()->second==1 || map.begin()->second==(n/k)-1)
	        return 1;
	    //Finally return false
	    return 0;
	    
	    
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends