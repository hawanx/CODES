#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef long long ll;

int prec(char c){

if(c=='^')
        return 3;

if(c=='*' or c=='/')
        return 2;
 
if(c=='-' or c=='+')
        return 1;
else
        return -1;

}


string infixtoPostfix(string x){

stack<char> s;
string post;

for (int i = 0; i < x.length(); ++i)
{

if((x[i]>='a' and x[i]<='z') or (x[i]>='A' and x[i]<='Z') or (x[i]>='0' and x[i]<='9') )
        post+=x[i];
else if(x[i]=='(')
        s.push(x[i]);
else if(x[i]==')'){

while(s.top()!='('){

post+=s.top();s.pop();



}
s.pop();

}else{

while(s.empty() !=true and prec(s.top())>=prec(x[i])){

post+=s.top();s.pop();


}

s.push(x[i]);

}



}

while(s.empty()!=true){
        post+=s.top();s.pop();
}


return post;


}


string infixtoPrefix(string x){


reverse(x.begin(),x.end());

for (int i = 0; i < x.length(); ++i)
{
        if(x[i]=='('){
                x[i]=')';
        }
       else if(x[i]==')'){
                x[i]='(';
        }
}

string rf= infixtoPostfix(x);

reverse(rf.begin(),rf.end());

return rf;


}

int prefixEvaluation(string x){


stack<int> s;

for (int i = x.length()-1; i >=0 ; --i)
{
        if(x[i]>='0' and x[i]<='9'){
                s.push(x[i]-'0');
        }
        else{

int a = s.top();s.pop();
int b = s.top();s.pop();

switch(x[i]){

case '+':
s.push(a+b);
break;

case '-':
s.push(a-b);
break;

case '*':
s.push(a*b);
break;

case '/':
s.push(a/b);
break;

case '^':
s.push(pow(a,b));
break;
}



        }
        
}


return s.top();


}

int postfixEvaluation(string x){


stack<int> s;

for (int i = 0; i <x.length() ; ++i)
{
        if(x[i]>='0' and x[i]<='9'){
                s.push(x[i]-'0');
        }
        else{

int b = s.top();s.pop();
int a = s.top();s.pop();

switch(x[i]){

case '+':
s.push(a+b);
break;

case '-':
s.push(a-b);
break;

case '*':
s.push(a*b);
break;

case '/':
s.push(a/b);
break;

case '^':
s.push(pow(a,b));
break;
}



        }
        
}


return s.top();


}



void solve(){

string x ="24+5*(8*4-12)";

string prefix = infixtoPrefix(x);
string postfix =infixtoPostfix(x);

cout << "PREFIX  FORM: "<< prefix<<endl;


cout<<"POSTFIX FORM: "<<postfix<<endl;


cout << prefixEvaluation(prefix)<<endl;

cout << postfixEvaluation(postfix);





}






int main(){
  
  
  
    solve();
  
  return 0;
}
