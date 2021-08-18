#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef long long ll;
 
 class node{

public:
    int data;
    node* next;
    

 };


 void transverse(node* p){
node *temp = p;
    do
    {
printf("%8p  %8p  %4d\n",temp,temp->next,temp->data);

    
        temp = temp->next;
    }while(temp!=p);
    cout << endl;
 }

void pushb(node* &head,int val){

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

node*temp = head;

if(pos<1)
    return;
else if(pos==1){


while(temp->next!=head)
  temp=temp->next;

head=head->next;
temp->next=head;



}
else{

for (int i = 0; i <pos-2 ; ++i)
{
if((temp->next)->next==head){
        return;
}

    temp=temp->next;
}

temp->next = (temp->next)->next;


}




}

void solve()

{


cout << "Current" << "      " <<  "Next"<< "    " << "Data"<<endl;

node*head = NULL;

pushb(head,10);
pushb(head,20);
pushb(head,30);
pushb(head,40);
pushf(head,5);

pushAtP(head,5,45);

deleteAtP(head,5);

transverse(head);

}
 
 



int main(){
   
        solve();
       
 
 
 
  return 0;
}