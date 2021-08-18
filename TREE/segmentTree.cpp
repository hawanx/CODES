#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef long long ll;


int getSum(int node,int ss, int se,int qs,int qe,int tree[]){


if(qe<ss or qs>se)
  return 0;
if(qs<=ss and qe>=se)
  return tree[node];

int mid = (ss+se)/2;

int left = getSum(2*node+1,ss,mid,qs,qe,tree);
int right = getSum(2*node+2,mid+1,se,qs,qe,tree);


return left+right;

}


void buildSt(int node,int x[],int s , int e,int tree[]){

if(s==e){
tree[node]=x[s];

return;
}
int mid = (s+e)/2;

buildSt(2*node+1,x,s,mid,tree);
buildSt(2*node+2,x,mid+1,e,tree);


tree[node] = tree[2*node+1] + tree[2*node+2];

}

void updateValueUntil(int node,int ss, int se,int i,int tree[],int diff){

if(i<ss or i>se)
  return;

if(i>=ss and i<=se)
  tree[node]+=diff;

if(ss==se)
  return;

int mid = (ss+se)/2;

updateValueUntil(2*node+1,ss,mid,i,tree,diff);
updateValueUntil(2*node+2,mid+1,se,i,tree,diff);




}


void update(int i ,int val,int tree[],int x[], int n){

if(i<0 or i>n-1)
  return;

int diff = val - x[i];

x[i]=val;

updateValueUntil(0,0,n-1,i,tree,diff);




}




void solve(){
  
  int x[] = {1,2,3,4,5};

int tree[100];

buildSt(0,x,0,4,tree);

update(1,10,tree,x,5);

cout << getSum(0,0,4,1,3,tree)<<endl;


for (int i = 0; i < 5; ++i)
{
  cout << x[i] << " ";
}


}

int main(){




fastio();

  int T=1;
  //cin>>T;
  for(int t=1;t<=T;t++){

    solve();
  }
  return 0;
}
