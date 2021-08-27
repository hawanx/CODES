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
#define acc(x,n) accumulate(x,x+n,0) 
#define vi vector<int>
#define vii vector<vi>
#define cend cout<<endl;
 

class Queue {
public:
    int f, r, size;
    unsigned capacity;
    int *arr;

Queue(unsigned cap){
cap = capacity;
f =size= r =0;
arr = new int[cap];
}

bool empty()
{
    if(size==0)
      return true;
    else return false;
}

void pop()
{
    f++;
    size--;
}

int front()
{
  
    return arr[f];
}

void push(int a){

arr[r] = a;
r++;
size++;

}

};


class Stack {
public:
    int r, size;
    unsigned capacity;
    int *arr;

Stack(unsigned cap){

cap = capacity;
size= r =0;

arr = new int[cap];

}

bool empty()
{
    if(size==0)
      return true;
    else return false;
}

void pop()
{
    r--;
    size--;
}

int top()
{
  
    return arr[r-1];
}

void push(int a){

arr[r] = a;
r++;
size++;

}

};



void solve()
{

Stack s(10);

s.push(10);
s.push(20);
s.push(30);
s.push(40);

cout << s.top();



}



int main(){


 


  int t=1;
  //cin>>t;
   
   while(t--){
    
    solve();
 cout <<endl;
       }
  return 0;
}   