#include <bits/stdc++.h>
using namespace std;


#define n 20


class Stack{


int *arr;int top;

public:
    Stack(){

arr = new int[n];
top=-1;

    }

void push(int x){

if(top>=n-1)
{    cout <<"Memory Full" << endl;
return;}

top++;
arr[top]=x;



}

void Top(){

if(top==-1){
    cout<<"Empty stack"<<endl;

return;}


cout << arr[top]<<endl;


}
void pop(){

if(top==-1){
    cout<<"Empty stack"<<endl;

return;
}
top--;



}

bool empty(){


if(top==-1)
    return true;

return false;

}


};




void solve()

{

Stack gg;

gg.push(10);

gg.push(20);


gg.push(30);
gg.push(40);

gg.pop();

gg.Top();



}
 
 
int main(){ 
   
   
    
    solve();
   
       
 
 
 
  return 0;
}