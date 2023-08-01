//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void solve(vector<string>&ans,int index,string mapping[],int a[],int N,string output){
        //Base case 
        if(output.length()==N){
            //When index becomes equal or goes ahead of string len 
            ans.push_back(output);//push it into ans 
            return;
        }
        
        int num=a[index];
        string value=mapping[num];
        
        //Iterate and recursively call
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            //Call func recursively
            solve(ans,index+1,mapping,a,N,output);
            output.pop_back();
        }
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Handle base case
        vector<string>ans;
        
        if(N==0){
            return ans;
        }
        
        //Create a mapping corresponding to number--alphabet
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        //We will use helper func that will return ans
        string output="";
        solve(ans,0,mapping,a,N,output);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}
// } Driver Code Ends