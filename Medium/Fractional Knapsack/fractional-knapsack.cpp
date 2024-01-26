//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comparator(Item a,Item b){
        double r1=(double)a.value/(double)a.weight;
        double r2=(double)b.value/(double)b.weight;
        //so that it sorts decreasingly
        return r1>r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        //Firstly you need to sort the given array with value/weight 
        //ratio , then only you will be able to greedily decide which 
        //weight & value to take place so that we can have max value
        sort(arr,arr+n,comparator);
        
        //Create current weight and final value variables
        //so that we can calculate them while looping
        int currWt=0;
        double finalVal=0;
        
        for(int i=0;i<n;i++)
        {
            //Check if current included weight is less than knapsack 
            //weight , then update current weight and final value
            if(currWt+arr[i].weight <=W){
                currWt+=arr[i].weight;
                finalVal+=arr[i].value;
            }else{
                int required=W-currWt;
                finalVal+=((double)arr[i].value/(double)arr[i].weight)*(double)required;
                break;
            }
        }
        return finalVal;
    }
        
};



//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends