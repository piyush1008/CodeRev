#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
     int data;
     Node *next;
     Node(int data){
        this->data= data;
        this->next=NULL;
     }
};
//inserting node at the head of the list
Node* create(Node* head,int data){
    if(head==NULL)
    {
        head=new Node(data);
        return head;
    }
    Node* newNode=new Node(data);
    newNode->next=head;
    head=newNode;
    return head;
}

Node* insertAtTail(Node* head,int data){
    if(head==NULL)
    {
        head=new Node(data);
        return head;
    }
     Node* temp=head;
     while(temp->next!=NULL)
     {
         temp=temp->next;
     }   
    Node* newnode=new Node(data);
    temp->next=newnode;
    return head;

}

int length(Node* head)
{
    int count=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}


void insertAtposition(Node* &head,int position,int data)
{
    int len=length(head);
    if(position<0 || position>len)
    {
        return;
    }
    int c=1;
    Node* temp=head;
    while(c!=position-1 && temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    Node* newnode=new Node(data);
    newnode->next=temp->next;
    temp->next=newnode;
    
}

void print_node(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void deleteAtend(Node* head)
{
    Node* temp=head;
    while(temp->next->next !=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}

void deleteAtBegining(Node* &head)
{
    Node* temp=head;
    head=head->next;
    delete(temp);
}
void deleteAtPosition(Node* head, int position){
    if(head==NULL){
        return;
    }

    int c=1;
    Node* temp=head;
    while(c!=position-1 && temp!=NULL){
        c++;
        temp=temp->next;
    }
    Node* temp1=temp->next;
    temp->next=temp->next->next;
    delete(temp1);

}

void reverseLinkedList(Node* &head){
    Node* prev=NULL;
    while(head!=NULL){
        Node* curr=head;
        Node* newnode=head->next;
        curr->next=prev;
        prev=curr;
        head=newnode;
    }
    head=prev;
}

Node* reverse(Node* curr,Node* prev){
    if(curr==NULL)
    { 
        return prev;
    }
    Node* nextnode=curr->next;
    curr->next=prev;
    prev=curr;
    return reverse(nextnode,prev);
}


//remove the nth node from the end of the list
void removenthnodefromend(Node*&head,int n)
{
    Node *fast=head;
    Node *slow=head;
    for(int i=1;i<=n;i++)
    {
        fast=fast->next;
    }

    while(fast->next!=NULL)
    {
        fast=fast->next;
        slow=slow->next;
    }
    Node* temp=slow->next;
    slow->next=slow->next->next;
    delete(temp);
}


//reverse the linked list of nodes in group of K

Node* reverseKNode(Node* &head,int k){
    if(head==NULL)
    {
        return NULL;
    }
    int len=length(head);

    if(k>len)
    {
        return head;
    }

    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;

    int count=0;

    while(curr!=NULL && count<k)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        count++;
    }
    if(forward!=NULL)
    {
        head->next=reverseKNode(forward,k); 
    }
    return prev;
}

bool detectCycle(Node* head)
{
    if(head==NULL){
        return NULL;
    }

    Node* fast=head;
    Node* slow=head;
    while(fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
    }
    return false;
}

//check if the linked list is circular
bool is_linked_list_circular(Node* head)
{
    if(head==NULL)
    {
        return false;
    }
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->next==head)
        {
            return true;
        }
        temp=temp->next;
    }
    return false;
}

//starting point of the circular linked list
Node* detectStartingpoint(Node* head)
{
    if(head==NULL)
    {
        return head;
    }
    Node* fast=head;
    Node* slow=head;

    while(fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow)
        {
            break;
        }
    }
    slow=head;
    while(slow!=fast)
    {
        fast=fast->next;
        slow=slow->next;
        if(fast==slow)
        {
            return slow;
        }
    }
}

//middle of the linked list
int detectMiddle(Node* head)
{
    if(head==NULL)
    {
        return -1;
    }
    Node* fast=head;
    Node* slow=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}

//check if the linked list is palindrome or not
// 1. find the middle of the linked list
// 2. reverse the second half of the linked list
// 3. compare the first half of the linked list with the second half of the linked list


Node* reverseLinkedList_1(Node* &head){
    Node* curr=head;
    Node* prev=NULL;
    while(curr!=NULL){
        Node* nextnode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextnode;
    }
    return prev;
}
bool checkPalindrome(Node* head)
{
    if(head==NULL)
    {
        return true;
    }
    if(head->next==NULL)
    {
        return true;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next; 
    }
     Node* reversekahead=NULL;
    if(slow->next!=NULL){
        reversekahead=reverseLinkedList_1(slow->next);
    }   
   
    slow->next=reversekahead;

    Node* temp1=head;
    Node* temp2=reversekahead;
    while(temp2!=NULL)
    {
        if(temp1->data!=temp2->data)
        {
            return false;
        }
        else{
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }
    return true;
}
//removes the duplicate from the sorted linked list
void removeDuplicate(Node* &head)
{
    Node* curr=head;
    while(curr->next!=NULL){
        if(curr->data==curr->next->data){
            Node* temp=curr->next;
            curr->next=curr->next->next;
            temp->next=NULL;
            delete(temp);
        }
        else{
            curr=curr->next;
        }
    }
}


//removes the duplicate node from the unsorted linked list

void remove_duplicat_node(Node* &head)
{
    if(head==NULL)
    {
        return;
    }
    Node* curr=head;
      Node* prev=NULL;
    unordered_set<int> s;
    while(curr!=NULL)
    {
        if(s.find(curr->data)!=s.end())
        {
            prev->next=curr->next;
            delete(curr);
        }
        else{
            s.insert(curr->data);
            prev=curr;
        }
        curr=prev->next;
    }
}

//sort the 0s,1s and 2s in the linkeed list 

void sort012(Node* &head)
{
    if(head==NULL)
    {
        return;
    }
    int zeroCount=0;
    int oneCount=0;
    int twoCount=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==0)
        {
            zeroCount++;
        }
         if(temp->data==1)
        {
            oneCount++;
        }
         if(temp->data==2)
         {
            twoCount++;
         }
         temp=temp->next;
    }

    Node* temp1=head;
    while(temp1!=NULL)
    {
        while(zeroCount--)
        {
            temp1->data=0;
            temp1=temp1->next;
        }
        while(oneCount--)
        {
            temp1->data=1;
            temp1=temp1->next;
        }
        while(twoCount--)
        {
            temp1->data=2;
            temp1=temp1->next;
        }
    }

    Node* temp2=head;
    while(temp2!=NULL)
    {
        cout<<temp2->data<<" ";
        temp2=temp2->next;
    }
}


//another method for doing the above the above questions

// Node* sort2(Node* &head)
// {
//     if(head==NULL)
//     {
//         return head;
//     }

//     Node* zerohead=new Node(-1);
//     Node* zerotail=zerohead;

//     Node* onehead=new Node(-1);
//     Node* onetail=onehead;

//     Node* twohead=new Node(-1);
//     Node* twotail=twohead;

//     Node* curr=head;
//     while(curr!=NULL)
//     {
//         if(curr-data==0)
//         {
//             Node* temp=curr;
//             curr=curr->next;
//             temp->next=NULL;

//             zerotail->next=temp;
//             zerotail=temp;
//         }
//         if(curr->data==1)
//         {
//             Node* temp=curr;
//             curr=curr->next;
//             temp->next=NULL;

//             onetail->next=temp;
//             onetail=temp;
//         }
//         if(curr->data==2)
//         {
//             Node* temp=curr;
//             curr=curr->next;
//             temp->next=NULL;

//             twotail->next=temp;
//             twotail=temp;
//         }
//     }

//     zerotail->next=onehead->next;
//     onetail->next=twohead->next;

//     Node* temp=onehead;  //remove the -1
//     onehead=onehead->next;
//     temp->next=NULL;
//     delete temp;

//     Node* temp=twohead;  //remove the -1
//     twohead=twohead->next;
//     temp->next=NULL;
//     delete temp;

//     if(onehead!=NULL)
//     {
//         zerotail->next=onehead;
//         if(twohead!=NULL)
//         {
//             onetail->next=twohead;
//         }
//     }
//     else{
//         if(twohead!=NULL)
//         {
//             zerotail->next=twohead;
//         }
//     }

//     Node* temp=zerohead;   //remove the -1
//     zerohead=zerohead->next;
//     temp->next=NULL;
//     delete temp;

//     return zerohead;


// }


void deleteMiddleNode(Node* &head)
{
    if(head==NULL)
    {
        return;
    }
    Node* fast=head;
    Node* slow=head;
    Node* prev=NULL;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        fast=fast->next->next;
        prev=slow;
        slow=slow->next;    
    }
    prev->next=slow->next;
    delete(slow);
    
}

//reverse the linked list between the left and right

Node* reverseBetween(Node* head,int left,int right)
{
    vector<int> v;
    Node* p=head;
    while(p!=NULL)
    {
        v.push_back(p->data);
        p=p->next;
    }

    while(left<right)
    {
        swap(v[left-1],v[right-1]);
        left++;
        right--;
    }

    Node* newhead=new Node(v[0]);
    Node* curr=newhead;
    for(int i=1;i<v.size();i++)
    {
        Node* newnode=new Node(v[i]);
        curr->next=newnode;
        curr=newnode;
    }

    return newhead;
    

}

//rotate the linked list 
/*
input a=[1,2,3,4,5] k=2
output a=[4,5,1,2,3]

*/


Node* rotateRight(Node* head,int k)
{
    if(k<0 || head==NULL)
    {
        return head;
    }
    int len=length(head);
    k=k%len;

    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head;
    int res=len-k;
    int c=1;
    Node* temp1=head;
    while(c<res)
    {
        temp1=temp1->next;
        c++;
    }
    cout<<temp1->data<<endl;
    Node* newhead=temp1->next;
    temp1->next=NULL;
    return newhead;


}

//sum of the two linked list 
Node* solveAdd(Node* &head1,Node* &head2)
{
    head1=reverse(head1,NULL);
    head2=reverse(head2,NULL);

    Node* anshead=NULL;
    Node* anstail=NULL;
    int carry=0;

    while(head1!=NULL && head2!=NULL)
    {
        int sum=carry+head1->data+head2->data;
        int digit=sum%10;
        int carry=sum/10;

        Node* newnode=new Node(digit);
        if(anshead==NULL)
        {
            anshead=newnode;
            anstail=newnode;
        }
        else{
            anstail->next=newnode;
            anstail=newnode;
        }
        head1=head1->next;
        head2=head2->next;
    }
   

    while(head1!=NULL)
    {
        int sum=carry+head1->data;
        int digit=sum%10;
        int carry=sum/10;
        Node* newnode=new Node(digit);
        anstail->next=newnode;
        anstail=newnode;
        head1=head1->next;

    }
     while(head2!=NULL)
    {
        int sum=carry+head2->data;
        int digit=sum%10;
        int carry=sum/10;
        Node* newnode=new Node(digit);
        anstail->next=newnode;
        anstail=newnode;
        head2=head2->next;
    }

    if(carry!=0)
    {
        Node* newnode=new Node(carry);
        anstail->next=newnode;
        anstail=newnode;
    }

     anshead=reverse(anshead,NULL);

    return anshead;

}

int main()
{

    int a[]={1,2,3};
    int n=sizeof(a)/sizeof(a[0]);
    Node* head=NULL;

    for(int i=0;i<n;i++)
    {
        head=insertAtTail(head,a[i]);
    }
    //print the linked list 
   print_node(head);
    cout<<endl;



    int b[]={1,2,3,4};
    int n1=sizeof(b)/sizeof(b[0]);
    Node* head1=NULL;

    for(int i=0;i<n1;i++)
    {
        head1=insertAtTail(head1,b[i]);
    }

 //print the linked list 
   print_node(head1);
    cout<<endl;


    Node* temp1=solveAdd(head,head1);
     //print the linked list 
   print_node(temp1);
    cout<<endl;




    // insertAtposition(head,2,18);

    // print_node(head);



    //deletion at the linked list

    // deleteAtend(head);
    // cout<<endl;

    // print_node(head);

    // deleteAtBegining(head);

    // print_node(head);

    // deleteAtPosition(head,2);

    // print_node(head);

    // Node* temp=reverse(head,NULL);

    // print_node(temp);

    // removenthnodefromend(head,2);

    // print_node(head);

    // Node* temp=reverseKNode(head,2);
    // cout<<"reversing the node"<<endl;
    //  print_node(temp);


    // int  temp=detectMiddle(head);
    // cout<<temp<<endl;


    // cout<<checkPalindrome(head)<<endl;
    //  return 0;

    // removeDuplicate(head);
    // print_node(head);
  
//   remove_duplicat_node(head);

    // sort012(head);

    // deleteMiddleNode(head);
    //  print_node(head);

    // Node* temp=reverseBetween(head,2,4);
    // print_node(temp);
    // return 0;

    Node* temp=rotateRight(head,2);
    print_node(temp);
    return 0;
}