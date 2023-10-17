#include<iostream>
using namespace std;
void Insertion_Sort(int a[],int n);

int main()
{
    int size = 5;
    int arr[size] = {8,2,22,4,5};
    Insertion_Sort(arr,size);
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}

void Insertion_Sort(int a[],int n){
    for(int i = 1;i<n;i++){
      int hole = i;
      int temp = a[i];
      while(hole > 0 && temp < a[hole - 1]){
          a[hole] = a[hole - 1];
          hole--;
      }
      a[hole] = temp;
    }
}