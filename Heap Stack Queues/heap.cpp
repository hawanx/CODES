#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef long long ll;
 
void swap(int &x,int &y){

int  t=x;
x=y;
y=t;


}

class MinHeap{
    public:
int *harr;
int capacity;
int heap_size;

public:
int parent(int i){return (i-1)/2;}

int left(int i){return 2*i +1;}

int right(int i){return 2*i +2;}


    MinHeap(int cap){

capacity= cap;
heap_size=0;
harr = new int[capacity];

    }


void insertKey(int val){

if(heap_size>=capacity){
    cout << "Heap is full "<<endl;
    return;
}

int i = heap_size;

harr[i]=val;

heap_size++;

while(i!=0 and val<harr[parent(i)]){

swap(harr[i],harr[parent(i)]);

i=parent(i);

} 



}

void heapify(int i){

int smallest = i;
int l = left(i);

int r = right(i);

if(l<heap_size and harr[l]<harr[smallest])
    smallest = l;
if(r<heap_size and harr[r]<harr[smallest])
    smallest=r;

if(smallest!=i){
    swap(harr[i],harr[smallest]);

heapify(smallest);
}



    
}


void changeKey(int i , int val){

if(harr[i]>val){

harr[i]=val;

while(i!=0 and val<harr[parent(i)]){

swap(harr[i],harr[parent(i)]);

i=parent(i);

} 



}else{

heapify(i);

}



}

int extractmin(){
if(heap_size<=0){
   
    return INT_MAX;
}
if(heap_size==1){
    heap_size--;
    return harr[heap_size];
}

int mina = harr[0];

harr[0] = harr[heap_size-1];
 
heap_size--;

heapify(0);

return mina;



}

void deleteKey(int i){

changeKey(i,INT_MIN);
extractmin();


}


int getMin(){

if(heap_size==0){
    cout << "Heap is Empty";return -1;
}

return harr[0];

}
int size(){

return heap_size;

}


};


class MaxHeap{



int *harr;
int capacity;
int heap_size;
public:
int parent(int i){return (i-1)/2;}

int left(int i){return 2*i +1;}

int right(int i){return 2*i +2;}


    MaxHeap(int cap){

capacity= cap;
heap_size=0;
harr = new int[capacity];

    }


void insertKey(int val){

if(heap_size>=capacity){
    cout << "Heap is full "<<endl;
    return;
}

int i = heap_size;

harr[i]=val;

heap_size++;

while(i!=0 and val>harr[parent(i)]){

swap(harr[i],harr[parent(i)]);

i=parent(i);

} 



}

void heapify(int i){

int largest = i;
int l = left(i);

int r = right(i);

if(l<heap_size and harr[l]>harr[largest])
    largest = l;
if(r<heap_size and harr[r]>harr[largest])
    largest=r;

if(largest!=i){
    swap(harr[i],harr[largest]);

heapify(largest);
}



    
}


void changeKey(int i , int val){

if(harr[i]<val){

harr[i]=val;

while(i!=0 and val>harr[parent(i)]){

swap(harr[i],harr[parent(i)]);

i=parent(i);

} 



}else{
harr[i]=val;

heapify(i);

}



}

int extractmax(){
if(heap_size<=0){
   
    return INT_MAX;
}
if(heap_size==1){
    heap_size--;
    return harr[heap_size];
}

int maxa = harr[0];

harr[0] = harr[heap_size-1];
 
heap_size--;

heapify(0);

return maxa;



}

void deleteKey(int i){

changeKey(i,INT_MAX);
extractmax();


}


int getMax(){

if(heap_size==0){
    cout << "Heap is Empty";return -1;
}

return harr[0];

}

};

void solve()

{

 MinHeap h1(11);
    
h1.insertKey(4);
h1.insertKey(3);
h1.insertKey(2);
h1.insertKey(1);

for (int i = 0; i < h1.heap_size; i++)
{
    cout << h1.harr[i]<<endl;
}



}
 
 
int main(){
 
  


fastio();
 
  
   
        solve();
       
 
 
 
  return 0;
}