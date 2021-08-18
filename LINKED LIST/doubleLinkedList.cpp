#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef long long ll;
 
 class node{

public:
    node* prev;
    int data;
    node* next;
    

 };


 void transverse(node* p){
node *temp = p;
   cout << "Previous "<< " Current " << "  Next " << "  DATA" << endl;

 do
    {

printf("%8p %8p %8p %3d\n",p->prev,p,p->next,p->data);


p=p->next;

}while(p!=temp);


 }

 void pushb(node* &head,int val){

node * n = new node;

n->data = val;
n->next = head;
node * temp = head;

if(head ==NULL){

head= n ;
head->prev=head;

return;

}

while(temp->next!=head)
    temp = temp->next;

temp->next = n;
n->prev=temp;

 }


void pushf(node* &head,int val){

node* t = head;
node* n = new node;
n->data = val;

if(head==NULL){

head = n;
head->data = val;
head->next = head;

return;

}

while(t->next!=head)
  t=t->next;
t->next = n; 
n->next = head;
n->prev =t;
head->prev = n;
head = n;


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

node* t = head;

if(pos==1){

if(head==NULL)
    return;
else if(head->next==NULL)
    head=NULL;
else{

head = head->next;

head->prev=NULL;


}




}else{

for (int i = 0; i < pos-2; ++i)
{

t=t->next;

if((t->next)->next==NULL){
    
t->next=NULL;

    return;
}


}

t->next = (t->next)->next;
(t->next)->prev=t;



}





}

void solve()

{


node*head = NULL;


pushb(head,10);
pushb(head,20);
pushb(head,30);
pushb(head,40);
pushf(head,5);


pushAtP(head,6,50);

deleteAtP(head,1);

transverse(head);




}
 
 
int main(){
   
        solve();
       
 
 
 
  return 0;
}