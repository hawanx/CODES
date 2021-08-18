#include <iostream>

using namespace std;
 
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
 
 static int c =0;
   
    int L[n1], R[n2];
 
     for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    int i = 0;
 
    int j = 0;
 
    int k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
            c+=n1-i;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
void mergeSort(int arr[],int l,int r){
    if(l>=r){
        return ;
     }


    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}


int main(){
 

int n;cin>>n;

int x[n];

for (int i = 0; i < n; ++i)
{
   cin>>x[i];
}

mergeSort(x,0,n-1);
cout << "\nAfter Sorting: ";
for (int i = 0; i < n; ++i)
{
   cout << x[i] << " ";
}

  return 0;
}