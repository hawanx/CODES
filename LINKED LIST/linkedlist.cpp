#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 class node{

public:
    int data;
    node* next;

 };


void transverse(node *p){
     cout << "CURRENT ADDRESS" << "   " << "VALUE" << "    "<< "NEXT ADDRESS" << endl;

while(p!=NULL){

cout << p << "           "<< p->data<< "       " << p->next <<  endl;
p = p->next;

}


}

void pushf(node* &head,int val){


node *n = new node;
n->data = val;
n->next = head;
head = n;




}
void pushb(node * &head,int val){

node * n = new node;
n->data = val;
n->next = NULL;

node * temp =head;

if(head ==NULL){

head= n ;
return;

}

while(temp->next!=NULL)
    temp = temp->next;

temp->next = n;



}

void pushAtP(node* &head,int pos, int val){

node *n = new node;

n->data = val;

node * temp = head;

if(pos<=1){

pushf(head,val);


}else{

for (int i = 0; i < pos-2; ++i)
{
if(head->next==NULL){
    head = temp;
pushb(head,val);
return;

}else

   head=head->next;
}

node*t=head->next;
head->next = n;
n->next = t;

head = temp;


}

}

void deleteAtP(node* &head,int pos){

node*temp = head;

if(pos<1)
    return;
else if(pos==1){head=head->next;}
else{

for (int i = 0; i <pos-2 ; ++i)
{
if((head->next)->next==NULL){
    head=temp;
    return;
}

    head=head->next;
}

head->next = (head->next)->next;
head =temp;

}




}

void listdelete(node* &head){

while(1){

if(head==NULL)
    break;
else
    deleteAtP(head,1);


}


}

void reverse(node* &head){

node*temp = head;
node*prev  =NULL;

while(temp!=NULL){

temp=head->next;
head->next = prev;
prev=head;
head=temp;




}

head=prev;


}

void solve()

{

   
node* head =NULL;

for (int i = 1; i<= 8 ;++i)
{
    pushb(head,i);
}

deleteAtP(head,8);

reverse(head);

transverse(head);

}
 
 
int main(){

fastio();
 
  
   
        solve();
 
  return 0;
}