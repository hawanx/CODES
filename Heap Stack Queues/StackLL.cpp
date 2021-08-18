#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define f(i,m,n,d) for(int i=(m);i<(n);i+=d)
#define r(i,n) f(i,0,n,1)
#define mst(a,b,c) memset(a, b, sizeof(c));
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef long long ll;
 
void flag(bool gg){

if(gg)
  cout<<"YES";
else
  cout<<"NO";


}

class StackLL{

public:
    int data;
    StackLL* next;



};

bool isEmpty(StackLL* &head){

if(head==NULL)
    return true;
else return false;


}

void push(StackLL* &head,int val){

StackLL* node = new StackLL();

node->data = val;
node->next = head;

head=node;



}

void pop(StackLL* &head){

if(isEmpty(head)){
    cout << "Stack is empty";
return;}

head = head->next;

}
  
  void peek(StackLL* &head){

if(isEmpty(head)){
    cout << "Stack is empty";
return;}
cout << head->data;


  }

  
void solve()
{

StackLL* head = NULL;

push(head,10);
push(head,20);
push(head,30);
pop(head);
peek(head);





 }
int main(){

fastio();
 
 

solve();  
  return 0;
}