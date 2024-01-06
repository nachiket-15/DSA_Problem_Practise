//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int findAllPrimeFactorsPowerSum(int n)
    {
        vector<int>v;
        while(n%2==0)
        {
            v.push_back(2);
            n=n/2;
        }
        
        //We know that only two is even prime number
        //Except all prime numbers are odd 
        
        //We also know that for a number , there is no divisor between 
        //number and number/2 --> This is by our observation
        
        //Above two observations help us to write next loop faster
        
        for(int i=3;i<=sqrt(n);i=i+2)
        {
            while(n%i==0)
            {
                v.push_back(i);
                n=n/i;
            }
        }
        
        if(n>2)
            v.push_back(n);
            
        
        map<int,int>map;
        
        for(auto i:v)
        {
            map[i]++;
        }
        
        int ans=0;
        for(auto it:map)
        {
            if(it.second!=0)ans+=it.second;
        }
        
        return ans;
        
    }
	int sumOfPowers(int a, int b){
	    //Can we write a function which finds prime factors of a 
	    //number
	    
	    int ans=0;
	    for(int i=a;i<=b;i++)ans+=findAllPrimeFactorsPowerSum(i);
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends