#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef long long ll;
 
class Queue{

public:
    int front,back;
    unsigned capacity,size;
    int *arr;



};

Queue* createQueue(unsigned c){

Queue *queue = new Queue();

queue->front=queue->size=0;queue->back=-1;
queue->capacity=c;

queue->arr = new int[c];
return queue;


}


bool isEmpty(Queue* queue){

if(queue->size==0)
return true;

return false;


}


void enqueue(Queue* &queue,int val){
if(queue->size==queue->capacity){
cout << "Storage Full";
return;
}

queue->back=(queue->back+1)%(queue->capacity);

queue->arr[queue->back] =val;

(queue->size)++;



}

void front(Queue* queue){

if(isEmpty(queue)){
cout << "No elements to show";
return;
}

cout << queue->arr[queue->front];




}

void back(Queue* queue){

if(isEmpty(queue) or queue->front>queue->back ){
cout << "No elements to show";
return;
}

cout << queue->arr[queue->back];




}
void dequeue(Queue* queue){

if(isEmpty(queue) or queue->front>queue->back ){
cout << "No elements to pop";
return;
}

(queue->front)=(queue->front+1)%(queue->capacity);

(queue->size)--;

}


void solve()

{

Queue* queue = createQueue(10);

enqueue(queue,10);
enqueue(queue,20);
enqueue(queue,30);

dequeue(queue);

front(queue);




}
 
 
int main(){
 





fastio();
 
  
   
        solve();
       
 
 
 
  return 0;
}