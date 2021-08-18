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
node* left;
node* right;

node(int val){

data =val;left=NULL;right=NULL;


}


};

void preorderTransversal(node* root){

if(root==NULL)
        return;

cout << root->data << " ";
preorderTransversal(root->left);
preorderTransversal(root->right);



}


void inorderTransversal(node* root){

if(root==NULL)
        return;


inorderTransversal(root->left);
cout << root->data << " ";
inorderTransversal(root->right);



}


void postorderTransversal(node* root){

if(root==NULL)
        return;


postorderTransversal(root->left);

postorderTransversal(root->right);
cout << root->data << " ";


}

int search(int arr[],int start,int end,int curr){

for (int i = 0; i <=end ; ++i)
{
   if(arr[i]==curr)
        return i;
}
return -1;

}



node* buildTreePreInOrder(int preorder[],int inorder[],int start,int end){

static int indx = 0;

int curr = preorder[indx];
indx++;

node* head = new node(curr);

int pos = search(inorder,start,end,curr);

if(start!=end){

head->left = buildTreePreInOrder(preorder,inorder,start,pos-1);


head->right = buildTreePreInOrder(preorder,inorder,pos+1,end);
}

return head;

}


node* buildTreePostInOrder(int postorder[],int inorder[],int start,int end){

static int indx = end;

if(start>end)
        return NULL;

int curr = postorder[indx];
indx--;

node* head = new node(curr);


int pos = search(inorder,start,end,curr);

if(start!=end){

        head->right = buildTreePostInOrder(postorder,inorder,pos+1,end);

head->left = buildTreePostInOrder(postorder,inorder,start,pos-1);



}

return head;

}

void KlevelTransversal(node* head){

if(head==NULL)
        return;


queue<node*> q;

q.push(head);
q.push(NULL);

while(q.empty()==0)
{

node* n = q.front();
q.pop();
if(n!=NULL){
cout << n->data << " ";

if(n->left!=NULL)
        q.push(n->left);

if(n->right!=NULL)
        q.push(n->right);

}else if(q.empty()==0){
q.push(NULL);
cout<<"| ";
}




}






}


int countNodes(node* head){

if(head==NULL)
        return 0;

return countNodes(head->left)+countNodes(head->right)+1;

}

int sumOfTree(node* head){

if(head==NULL)
        return 0;

return sumOfTree(head->left)+sumOfTree(head->right)+head->data;



}


int maxHeight(node* head){

if(head==NULL)
        return 0;

return max(maxHeight(head->left),maxHeight(head->right))+1;



}


int diameterOfTree(node* head){

if(head==NULL)
        return 0;

 int max1 =max(diameterOfTree(head->right),diameterOfTree(head->left));

 return max(maxHeight(head->left)+maxHeight(head->right)+1,max1);



}

void replacementSum(node* &     head){

if(!(head->right==NULL and head->left==NULL)){

head->data =sumOfTree(head);

replacementSum(head->left);
replacementSum(head->right);


}


}


void rightViewOfTree(node* head){

if(head==NULL)
        return;


queue<node*> q;

q.push(head);
q.push(NULL);

while(q.empty()==0)
{

node* n = q.front();
q.pop();
if(n!=NULL){

if(q.front()==NULL)
cout << n->data << " ";

if(n->left!=NULL)
        q.push(n->left);

if(n->right!=NULL)
        q.push(n->right);

}else if(q.empty()==0){
q.push(NULL);

}




}


}


void leftViewOfTree(node* head){

if(head==NULL)
        return;


queue<node*> q;

q.push(head);
q.push(NULL);
cout << head->data <<  " ";     
while(q.empty()==0)
{

node* n = q.front();
q.pop();
if(n!=NULL){



if(n->left!=NULL)
        q.push(n->left);

if(n->right!=NULL)
        q.push(n->right);

}else if(q.empty()==0){

cout << (q.front())->data<< " ";
q.push(NULL);

}




}






}


node* insertBst(node* &root , int val){

if(root==NULL)
  return new node(val);

if(root->data > val)
  root->left = insertBst(root->left,val);
else
  root->right= insertBst(root->right,val); 

return root;


}


node* searchbst(node* head,int key){


if(head->data==key)
  return head;

if(head->data>key)
return  searchbst(head->left,key);
else
return searchbst(head->right,key);
 

return NULL;


}

node* constructbst(int pre[],int n){

node* t =new node(pre[0]);

for (int i = 1; i < n; ++i)
{

insertBst(t,pre[i]);
  
}

return t;

}


void solve(){

//transversing a self-made tree
cout << "Transversing a self-made tree -:\n\n";

node* root = new node(1);

root->left = new node(2);

root->right = new node(3);

root->left->left = new node(4);
root->left->right = new node(5);

root->right->left = new node(6);
root->right->right = new node(7);


cout << "PREORDER  = ";
preorderTransversal(root);
cout<<endl;
cout << "INORDER   = ";
inorderTransversal(root);
cout<<endl;
cout << "POSTORDER = ";
postorderTransversal(root);

cout << "\nKlevelTransversal : ";
KlevelTransversal(root );
cout<<endl;cout<<endl;cout<<endl;

//making a tree from pre-post and inorder transversal data

cout << "Making a tree from pre-post and inorder transversal data-:\n"<<endl;

int pre[]={1 ,2, 4, 5, 3, 6, 7 };

int in[]={4 ,2, 5, 1, 6, 3, 7 };

int post[]={4, 5, 2, 6, 7, 3,1 };

node *head1 = buildTreePreInOrder(pre,in,0,6);

node *head2 = buildTreePostInOrder(post,in,0,6);
cout << "INORDER   = ";
inorderTransversal(head1);
cout<< " (Preorder data) " ;
cout<<endl;
cout << "INORDER   = ";
inorderTransversal(head2);
cout<< " (Postorder data) " ;

cout<<endl;cout<<endl;

cout <<"Sum of tree: " <<  sumOfTree(root)<<endl;

cout << "MAX height : " << maxHeight(root);
cout<<endl;

cout << "Diameter : " << diameterOfTree(root);

cout<<endl;

cout << "Right View : ";
rightViewOfTree(root);
cout << endl;

cout << "Left View : ";
leftViewOfTree(root);


}



int main(){
  
  
    solve();
  
  return 0;
}
