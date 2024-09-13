//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}

// } Driver Code Ends


/* The structure of the class is
class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};
 */

//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
    // Push x first in empty q2
    q2.push(x);
    
    // Push all the remaining elements in q1 to q2
    while (!q1.empty()) {
        q2.push(q1.front());
        q1.pop();
    }
    
    // Swap the names of q1 and q2
    queue<int> q = q1;
    q1 = q2;
    q2 = q;
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    // If q1 is empty
    if (q1.empty())
        return -1;
    
    // Pop the top element
    int top = q1.front();
    q1.pop();
    return top;
}

