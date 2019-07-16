#include<iostream>
#include <stack>

using namespace std;

class node{

public:

     int data;
     node *next;
     node(int d){
          data =d;
          next = NULL;
     }

     ~node(){
          if(next!=NULL)
               delete next;
     }
};

int len(node *head){
     int l=0;
     while(head!=NULL){
          l++;
          head = head->next;
     }
     return l;
}

void insert_begin(node *&head, int d){
     if(head == NULL){
          head = new node(d);
          return;
     }
     node *new_node = new node(d);
     new_node->next = head;
     head = new_node;
}

void insert_end(node *&head, int d){
     if(head == NULL){
          head = new node(d);
          return;
     }
     node * new_node = new node(d);
     node *temp=head;
     while(temp->next!= NULL){
          temp=temp->next;
     }
     temp->next= new_node;
}

void insert_mid(node *&head, int d, int pos){
     if(head == NULL || pos<=0){
          insert_begin(head,d);
          return;
     }
     if(pos>= len(head)){
          insert_end(head,d);
          return;
     }
     node * new_node = new node(d);
     node *temp=head;
     while(pos--){
          temp=temp->next;
     }
     new_node->next = temp->next;
     temp->next= new_node;

}

int delete_begin(node *&head){
     if(head == NULL){
          return -1;
     }
     int val;
     node *temp=head;
     val = head->data;
     head = head->next;
     delete temp;
     return val;
}

int delete_end(node *&head){
     if(head == NULL){
          cout<<"Linked List empty.";
          return -1;
     }
     int val;
     node *temp=head;
     while(temp->next->next !=NULL){
          temp=temp->next;
     }
     node *endnode=temp->next;
     val=endnode->data;
     temp->next=NULL;
     delete endnode;
     return val;
}

int delete_pos(node *&head, int pos){
     if(head == NULL || pos<0){
          cout<<"Node can't be deleted";
          return -1;
     }
     if(pos==0){
          return delete_begin(head);
     }
     if(pos>=len(head)){
          return delete_end(head);
     }
     node *temp=head;
     while(pos--){
          temp=temp->next;
     }
     node *nextnode=temp->next;
     int val=nextnode->data;
     temp->next=temp->next->next;
     delete nextnode;
     return val;
}

void search_it(node *head, int d){
     int pos=0;
     while(head!=NULL){
          pos++;
          if(head->data == d){
               cout<<"Data found at : "<<pos;
               return;
          }
          head=head->next;
     }
     cout<<"Data not found";
}

void search_rec(node *head,int d,int pos){
     if(head==NULL){
           cout<<"data not found";
          return;
     }
     if(head->data==d){
          cout<<"Data found at "<<pos;
          return;
     }
     pos++;
     return search_rec(head->next,d,pos);
}

void search_nth_last(node *head,int pos){
     if(head==NULL)
          return;

     int l=len(head)-pos;
     while(l--){
          head=head->next;
     }
     cout<<head->data<<endl;
}

void print_mid(node *head){
     if(head==NULL)
          return;
     node* slow=head;
     node* fast=head->next;
     int pos=0;
     while(fast!=NULL && fast->next!=NULL){
          pos++;
          slow=slow->next;
          fast = fast->next->next;
     }
     cout<<pos<<" ";
}

node* tail(node *head){
     while(head->next!=NULL)
          head=head->next;
     return head;

}

bool detect_loop(node *head){
     node *slow=head;
     node *fast=head;
     bool ans=false;
     while(fast!=NULL && fast->next!=NULL){
          fast=fast->next->next;
          slow=slow->next;
          if(slow==fast){
               ans= true;
               break;
          }
     }
     slow=head;
     fast=head;
     while(slow!=fast){
          slow=slow->next;
          fast=fast->next;
     }
     cout<<"Loop starts at : "<<slow->data;
     return ans;
}

bool pallindrome_stack(node *head){
     bool ans=true;
     stack <int> check;
     int l=len(head)/2;
     int l2=l;
     while(l2--){
          check.push(head->data);
          head=head->next;
     }
     while(l--){
          if(check.top()!=head->data){
               ans=false;
               break;
          }
          check.pop();
          head=head->next;
     }
return ans;
}

void reverse_it(node *&head){
     node *prev=NULL;
     node *curr=head;
     node *next_node=NULL;

     while(curr!=NULL){
          next_node=curr->next ;
          curr->next=prev;
          prev=curr;
          curr=next_node;
     }
     head=prev;
}

bool sublist_pres(node *head,node *test){
    if(head==NULL && test==NULL)
        return true;
    else if(test==NULL)
        return true;
    else if(head==NULL && test!=NULL)
        return false;
    node *tp=test;
    while(head!=NULL){
        tp=test;
        while(tp!=NULL){
            if(head->data == tp->data){
                tp=tp->next;
                head=head->next;
            }
            if(tp==NULL)
                return true;
            else if(head==NULL)
                return false;
            else
                head=head->next;
        }
    }
    return false;
}

void display(node *head){
     while(head!=NULL){
          cout<<head->data<<" ";
          head = head->next;
     }
     cout<<endl;
}

int main(){
     int p;
     cin>>p;
     node *head = NULL;
     node *test =NULL;
     insert_begin(head, 10);
     insert_begin(head, 10);
     insert_begin(head, 20);
     insert_end(head, 20);
     insert_begin(head, 40);
     insert_begin(head, 10);
     //insert_mid(head, 60,p-1);
     insert_begin(test, 10);
     insert_begin(test, 10);
     insert_begin(test, 20);
     display(head);
     display(test);
     search_rec(head,60,0);
     node *t=NULL;
     cout<<"\n";

     if(sublist_pres(head,test))
          cout<<"sublist present";
     else
          cout<<"sublist absent";
     //search_nth_last(head,4);
     //display(head);
     //cout<<"\n";
     //print_mid(head);
     /*
     if(pallindrome_stack(head))
          cout<<"Palindrome present";
     else
          cout<<"Palindrome absent";
     reverse_it(head);
     display(head);

     node *tailnode= tail(head);
     tailnode->next=head->next;
     if(detect_loop(head))
          cout<<"Loop present";
     else
          cout<<"Loop absent";*/
   return 0;
}
