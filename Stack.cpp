#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;
    Stack(int size)
    {
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int data)
    {
        if(top>size)
        {
            cout<<"stack overflow"<<endl;
        }
        top++;
        arr[top]=data;
    }

    void pop(){
        if(top==-1)
        {
            cout<<"stack underflow"<<endl;
        }
        top--;
    }

    int getTop()
    {
        if(top==-1)
        {
            cout<<"stack underflow"<<endl;
            return -1;
        }
        return arr[top];
    }

    int getSize()
    {
        if(top==-1)
        {
            cout<<"stack underflow"<<endl;
            return -1;
        }
        else{
            return top+1;
        }
    }

    bool isEmpty(){
        if(top==-1)
        {
            return true;
        }
        return false;
    }


};


//implement 2 stack in one array

class Stack2{
    public:
    int size;
    int top1;
    int top2;
    int *arr;

    Stack2(int size)
    {
        this->size=size;
        arr=new int[size];
        top1=-1;
        top2=size;
    }

    void push1(int data)
    {
        if(top2-top1==1)
        {
            cout<<"no space available"<<endl;
            return;
        }
        top1++;
        arr[top1]=data;
    }

    void push2(int data)
    {
        if(top2-top1==1)
        {
            cout<<"no space available"<<endl;
            return;
        }
        arr[top2]=data;
        top2--;
    }

    void pop1(){
        if(top1==-1)
        {
            cout<<"stack underflow"<<endl;
            return;
        }
        top1--;
    }
     void pop2(){
        if(top2==size)
        {
            cout<<"stack underflow"<<endl;
            return;
        }
        top2++;
    }
};

///reverse the stack  -easy solution 


//find mid point of the stack



//approach1 - simple solution
void findmid(stack<int> s)
{
    int length=s.size();
    int mid=length/2;
    int count=0;
    while(!s.empty() && count!=mid)
    {
        s.pop();
        count++;
    }
    cout<<s.top()<<endl;
}

//approach 2  - recursion appraoch to understand better

void findmid2(stack<int> s,int length)
{
    if(s.size()==(length+1)/2)
    {
        cout<<s.top()<<endl;
        return;
    }
    int temp=s.top();
    s.pop();
    findmid2(s,length);
    s.push(temp);
}


void insertAtBottom(stack<int> &s,int &target)
{
    if(s.empty())
    {
        s.push(target);
        return;
    }
    int temp=s.top();
    s.pop();
    insertAtBottom(s,target);
    s.push(temp);
}

///reverse the stack
/*
    A-1 just create a new stack and put all the element in the new stack
    A-2 use recursion approach for better understanding of the recursion on stack
*/
void reverseStack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }
    int temp=s.top();
    s.pop();
    reverseStack(s);
    insertAtBottom(s,temp);
}

void print_stack(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

bool checkValidparanthesis(string str)
{
    stack<char> s;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='[' || str[i]=='{' || str[i]=='(')
        {
            s.push(str[i]);
        }
        else{
            if(s.empty())
            {
                return false;
            }
            if(str[i]==')' && s.top()=='(')
            {
                s.pop();
            }
             if(str[i]==']' && s.top()=='[')
            {
                s.pop();

            }
            if(str[i]=='}' && s.top()=='{')
            {
                s.pop();
            }
        }
    }
    if(s.empty())
    {
        return true;
    }
    else{
        return false;
    }
}


void inserttopelement(stack<int> &s,int target)
{
    if(s.empty())
    {
        s.push(target);
        return;
    }
    if(s.top()>target)
    {
        s.push(target);
        return;
    }
    int topele=s.top();
    s.pop();
    inserttopelement(s,target);
    s.push(topele);

}

void sortStack(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }
    int topelement=s.top();
    s.pop();
    sortStack(s);
    inserttopelement(s,topelement);
}

bool checkRedundancy(string str)
{
    stack<char> s;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]==')')
        {
            char top=s.top();
            s.pop();
            bool flag=true;
            while(!s.empty() && top!='(')
            {
                if(top=='+' || top=='-' || top=='*' || top=='/')
                {
                    flag=false;
                }
                top=s.top();
                s.pop();
            }
            if(flag==true) //if no operator is found
            {
                return true;
            }
        }
        else{
            s.push(str[i]);
        }
    }
  
    if(!s.empty())
    {
        return true;
    }
    return false;
}



int findlongestValidParanthesis(string str)
{
    stack<int> s;
    int maxlen=0;
    for(int i=0;i<str.length();i++)
    {
        if(str[i]=='(')
        {
            s.push(i);
        }
        else{
            if(s.empty())
            {
                continue;
            }
            int top=s.top();
            s.pop();
            int len=i-top+1;
            if(len>maxlen)
            {
                maxlen=len;
            }
        }
    }
    return maxlen;
}


//next smaller element

void nextsmallerelement(vector<int> v)
{
    cout<<"ender"<<endl;
    stack<int> s;
    s.push(-1);
    vector<int> ans;
    for(int i=v.size()-1; i>=0; i--)
    {
        int curr=v[i];
        cout<<"asdfasdf"<<endl;
        while(!s.empty() && s.top()>=curr)
        {
            s.pop();
        }
        ans.push_back(s.top());
        s.push(curr);
    }
    cout<<"asdfasdf"<<endl;
    reverse(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}








void previousSmallerElement(vector<int> v)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans;
    for(int i=0;i<v.size();i++)
    {
        int curr=v[i];
        while(!s.empty() && s.top()>=curr)
        {
            s.pop();
        }
        ans.push_back(s.top());
        s.push(curr);
    }

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}



void nextGreaterElement(vector<int> v)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans;
    for(int i=v.size()-1;i>=0;i--)
    {
        int curr=v[i];
        while(!s.empty() && s.top()<=curr)
        {
            s.pop();
        }
        if(s.empty())
        {
            s.push(-1);
        }
        ans.push_back(s.top());
        s.push(curr);
    }
    reverse(ans.begin(), ans.end());
     for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}






int main()
{
    // int a[]={4,5,1,2,3};
    // int n=sizeof(a)/sizeof(a[0]);
    // Stack s(10);
    // for(int i=0;i<n;i++)
    // {
    //     s.push(a[i]);
    // }
    

    // s.pop();

    // stack<int> s;
    // for(int i=0;i<n;i++)
    // {
    //     s.push(a[i]);
    // }

    //cout<<s.size()<<endl;

    //findmid(s);
    // print_stack(s);s

    // reverseStack(s);
    // cout<<"pritnitng after reversing the stack"<<endl;
    // print_stack(s);
//     string str="[{}]";
//    cout<<checkValidparanthesis(str)<<endl;
    
    // sortStack(s);
    // print_stack(s);

    // string str1="((a+b)";

    // cout<<checkRedundancy(str1);


    // string str3=")()()";
    // cout<<findlongestValidParanthesis(str3);

    vector<int> a({4,5,2,25});
    //nextsmallerelement(a);
    //previousSmallerElement(a);
    nextGreaterElement(a);
     
    return 0;
}