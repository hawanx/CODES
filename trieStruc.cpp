#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef long long ll;


class trie{

public:

class node{

public:
bool end;
node* next[26];

node(){

end= false;

for (int i = 0; i < 26; ++i)
{
    next[i]=NULL;
}


}


};

node* tri=new node();


void insert(string str){

node* t = tri;

for (int i = 0; i < str.size(); ++i)
{
    int idx= str[i]-'a';
    
if(t->next[idx]==NULL)
    t->next[idx] = new node();

t=t->next[idx];


}

t->end=true;


}

bool search(string str){



node* t = tri;

for (int i = 0; i < str.size(); ++i)
{
int idx= str[i]-'a';

    if(t->next[idx]==NULL)
        return false;

    t= t->next[idx];

     

}

return t->end;

}


void isFound(string str){

if(search(str))
    cout << str << " is in the trie structure"<<endl;
else
    cout << str << " is not in the trie structure"<<endl;


}



};

 




void solve()

{

    trie t1;

    t1.insert("hello");

    t1.insert("hemlet");


t1.isFound("hemlet");






}
 
 
int main(){
 



   
fastio();
 
  
   
        solve();
       
 
 
 
  return 0;
}