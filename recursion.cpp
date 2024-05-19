#include<bits/stdc++.h>
using namespace std;

int findfib(int n)
{
    if(n==1)
    {
        return 1;
    }
    return n*findfib(n-1);
}

//printing numbers from 1 to n from top to down 

void printtoptobottom(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<" ";
    printtoptobottom(n-1);
}


//printing numbers from 1 to n from down to up

void printbottomtotop(int n)
{
    if(n==0)
    {
        return;
    }
    
    printbottomtotop(n-1);
    cout<<n<<" ";
   
}

int findfibnocci(int n)
{
    if(n==0){
        return 0;
    }
    if(n==1)
    {
        return 1;
    }

    return findfibnocci(n-1)+findfibnocci(n-2);
}


int climbstairs(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }

    return climbstairs(n-1)+climbstairs(n-2);
}


//print array using recursion

void printarray(int a[],int n ,int i)
{
    if(i>=n)
    {
        return;
    }
    cout<<a[i]<<" ";
    i++;
    printarray(a,n,i);
}

//find the maxelement in the array

int findmaxelement(int a[],int n,int i,int &maxelement)
{
    if(i>=n)
    {
        return maxelement;
    }

    if(maxelement<a[i])
    {
        maxelement=a[i];
    }
    i++;
    return findmaxelement(a,n,i,maxelement);
}

//check if the "r" is present in the string

bool ispresent(string str,char ch,int i,int len)
{
    if(i>=len)
    {
        return false;
    }
    if(str[i]==ch)
    {
        return true;
    }
    i++;
    return ispresent(str,ch,i,len);

}

void printdigit(int n)
{
    if(n==0)
    {
        return;
    }
    printdigit(n/10);
    cout<<n%10;
  
}

//check if the array is sorted or not 

bool isSorted(int a[],int n,int i)
{
    if(i==n-1)
    {
        return true;
    }

    if(a[i+1]<a[i])
    {
        return false;
    }
    i++;
    return isSorted(a,n,i);
}


bool linearsearch(int a[],int n,int i,int element)
{
    if(i>=n)
    {
        return false;
    }
    if(a[i]==element)
    {
        return true;
    }
    i++;
    return linearsearch(a,n,i,element);
    
}

bool BinarySearch(int a[],int n,int &s,int &e,int &element)
{
    if(s>e)
    {
        return false;
    }

    int mid=s+(e-s)/2;
    if(a[mid]==element)
    {
        return true;
    }
    else if(a[mid]>element)
    {
        mid=mid-1;
        return BinarySearch(a,n,s,mid,element);
    }
    else{
        mid=mid+1;
        return BinarySearch(a,n,mid,e,element);
        
    }
    
}



//subsequence of a string
void printallsubsequence(string str,int i, string output)
{
    if(i>=str.length())
    {
        cout<<output<<" ";
        return;
    }

    //exclude
    printallsubsequence(str,i+1,output);

    output.push_back(str[i]);

    printallsubsequence(str,i+1,output);
}

######Important question ###########

//array to distinct input element

int printelement(vector<int> v,int n,int target,int mini)
{
    if(target==0)
    {
        return 0;
    }
    if(target<0)
    {
        return INT_MAX;
    }
    for(int i=0;i<n;i++)
    {
        int ans=printelement(v,n,target-v[i],mini);
        if(ans!=INT_MAX)
        {
            mini=min(mini,ans+1);
        }
    }
    return mini;
}   

int solve(int n,int x,int y,int z)
{
    if(n==0)
    {
        return 0;
    }

    if(n<0)
    {
        return INT_MIN;
    }

    int ans1=solve(n-x,x,y,z)+1;
    int ans2=solve(n-y,x,y,z)+1;
    int ans3=solve(n-z,x,y,z)+1;

    return max(ans1,max(ans2,ans3));
}


//maxiumum sum of subsequence in which no two element are adjacent
void solvemax(vector<int> &arr,int sum, int &maxi,int i)
{
    if(i>=arr.size())
    {
        maxi=max(maxi,sum)
        return;
    }
    //take the current element in sum and exclude the next element
    solve(arr,sum+arr[i],maxi,i+2);

        //exclude the current element in sum and  include the next element
    solve(arr,sum,maxi,i+1);
}


int main()
{
    // int n=3;
    // int fib=findfib(n);
    // cout<<fib<<endl;
    // return 0;

    //printtoptobottom(n);
    // cout<<endl;
    // printbottomtotop(n);




    // cout<<findfibnocci(n);


//     int a[]={1,7,3,4};
//     int n=4;
//     int maxelement =-1;
//    // printarray(a,n,0);

//     cout<<findmaxelement(a,n,0,maxelement);

    //  int n=45;
    //  printdigit(n);


//     int a[]={1,2,3,4};
//     int n=5;
//     //cout<<isSorted(a,n,0)<<endl;
//    // cout<<linearsearch(a,n,0,8);
//    int s=0;
//    int e=n-1;
//    int element=2;
//     cout<<BinarySearch(a,n,s,e,element);

    printallsubsequence("abc",0,"");

    return 0;
}