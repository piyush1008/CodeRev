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

int main()
{
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(a[0]);
    Stack s(10);
    for(int i=0;i<n;i++)
    {
        s.push(a[i]);
    }
    

    s.pop();

    return 0;
}