#include <iostream>

using namespace std;
 int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
    
        if (arr[mid] == x)
            return mid;
 
       
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
       
        return binarySearch(arr, mid + 1, r, x);
    }
 
    
    return -1;
}
int main(){

int n;cin>>n;

int x[n];

for (int i = 0; i < n; ++i)
{
   cin>>x[i];
}

int a;cin>>a;

int result = binarySearch(x, 0, n - 1, a);

 cout <<"The element is present at index = "<< a ;

  return 0;
}