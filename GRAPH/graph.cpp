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
 
void flag(bool gg){

if(gg)
  cout<<"YES";
else
  cout<<"NO";


}

class Graph{

bool *visited;

vi *vec;

int v;
public:
Graph(int vertices){

v=vertices;

vec = new vi[v];

visited = new bool[v];

for (int i = 0; i < v; ++i)
{
  visited[i]=false;
}

}




  void addEdge(int a,int b){

vec[a].pb(b);


  }

  void BFS(int s){

for (int i = 0; i < v; ++i)
{
  visited[i]=false;
}


queue<int> q;

q.push(s);
visited[s]=true;

while(q.empty()!=true){

s= q.front();
cout << s << " ";
q.pop();

for (auto i:vec[s]){

if(visited[i]==false){

visited[i]=true;
q.push(i);


}



}




}


for (int i = 0; i < v; ++i)
{
  visited[i]=false;
}

  }

  void DFS(int s){


visited[s]=true;
cout << s << " ";


for (auto i:vec[s])
{

  if(visited[i]==false)
    DFS(i);

}




  }


};





void solve()
{

Graph g(6);
   g.addEdge(5, 0);
    g.addEdge(5,2);
   g.addEdge(2,3);
   g.addEdge(3,1);
   g.addEdge(4,1);
   g.addEdge(4,0);





g.DFS(4);


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