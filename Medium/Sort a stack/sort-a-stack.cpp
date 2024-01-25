//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}
// } Driver Code Ends




/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void sortedInsert(stack<int>&st,int num)
{
    //You have to keep a condition for insertion
    if(st.empty() || (!st.empty() && st.top()<num)){
        st.push(num);
        return;
    }
    int n=st.top();
    st.pop();
    sortedInsert(st,num);
    st.push(n);
}
void SortedStack :: sort()
{
   //First remove all the elements from stack
   if(s.empty()){
      return; 
   }
   int n=s.top();
   s.pop();
   //Recursively call this function to empty the stack
   sort();
   //Do sorted insertion
   sortedInsert(s,n);
}