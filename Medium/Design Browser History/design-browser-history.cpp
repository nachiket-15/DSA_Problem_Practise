//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Node{
    public:
    Node*next=NULL;
    Node*prev=NULL;
    string data="";
    Node(string val)
    {
        data=val;
        next=NULL;
        prev=NULL;
    }
};

class BrowserHistory {
public:
    // constructor to initialize object with homepage
    Node*home=NULL;
    Node*curr=NULL;
    BrowserHistory(string homepage) {
        home=new Node(homepage);
        curr=home;
    }
    
    // visit current url
    void visit(string url) {
        Node*newnode=new Node(url);
        curr->next=newnode;
        newnode->prev=curr;
        curr=curr->next;
    }
    
    // 'steps' move backward in history and return current page
    string back(int steps) {
        while(steps)
        {
            if(curr->prev)
            {
                curr=curr->prev;
            }else{
                break;
            }
            steps--;
        }
        return curr->data;
    }
    
    // 'steps' move forward and return current page
    string forward(int steps) {
        while(steps)
        {
            if(curr->next){
                curr=curr->next;
            }
            else{
                break;
            }
            steps--;
        }
        return curr->data;
    }
};

//{ Driver Code Starts.

int main()
{
    string homepage;
    cin >> homepage;
    
    BrowserHistory obj(homepage);
    
    int total_queries;
    cin >> total_queries;
    while(total_queries--)
    {
        int query;
        cin >> query;
        
        // if query = 1, visit()
        // if query = 2, back()
        // if query = 3, forward()
        
        if(query == 1) {
            string url;
            cin >> url;
            obj.visit(url);
        }
        else if(query == 2) {
            int steps;
            cin >> steps;
            cout << obj.back(steps) << endl;
        }
        else {
            int steps;
            cin >> steps;
            cout << obj.forward(steps) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends