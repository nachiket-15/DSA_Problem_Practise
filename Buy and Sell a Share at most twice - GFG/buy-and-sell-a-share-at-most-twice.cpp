//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

int maxProfit(vector<int>&prices){
     // Write your code here.
    int n = prices.size();
    int firstBuy = INT_MIN, firstSell = 0;
    int secondBuy = INT_MIN, secondSell = 0;

    // Loop to consider each day
    for(int i = 0; i < n; i++)
    {
    	// Maximum profit after buying the stock for the first time 
    	firstBuy = max(firstBuy, - prices[i]);

    	// Maximum profit after selling the stock for the first time 
    	firstSell = max(firstSell, firstBuy + prices[i]);

    	// Maximum profit after buying the stock for the second time 
    	secondBuy = max(secondBuy, firstSell - prices[i]);

    	// Maximum profit afer selling the stock for the second time 
    	secondSell = max(secondSell, secondBuy + prices[i]);
    }

    // Return the final profit
    return secondSell;
}

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        cout<<maxProfit(price)<<endl;
    }

}

// } Driver Code Ends